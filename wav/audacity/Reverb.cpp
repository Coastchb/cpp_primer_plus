/**********************************************************************

   Audacity: A Digital Audio Editor
   Audacity(R) is copyright (c) 1999-2013 Audacity Team.
   License: GPL v2.  See License.txt.

   Reverb.cpp
   Rob Sykes, Vaughan Johnson

******************************************************************//**

\class EffectReverb
\brief A reverberation effect

*//*******************************************************************/

#include <string>
#include <iostream>
#include <fstream>
#include <string> 
#include "Audacity.h"
#include "Reverb.h"
#include "Reverb_libSoX.h"

using namespace std;

enum 
{
   ID_RoomSize = 10000,
   ID_PreDelay,
   ID_Reverberance,
   ID_HfDamping,
   ID_ToneLow,
   ID_ToneHigh,
   ID_WetGain,
   ID_DryGain,
   ID_StereoWidth,
   ID_WetOnly
};

// Define keys, defaults, minimums, and maximums for the effect parameters
//
//     Name          Type     Key                  Def      Min      Max   Scale
// Param( RoomSize,     double,  wxT("RoomSize"),      75,      0,       100,  1  );
// Param( PreDelay,     double,  wxT("Delay"),         10,      0,       200,  1  );
// Param( Reverberance, double,  wxT("Reverberance"),  50,      0,       100,  1  );
// Param( HfDamping,    double,  wxT("HfDamping"),     50,      0,       100,  1  );
// Param( ToneLow,      double,  wxT("ToneLow"),       100,     0,       100,  1  );
// Param( ToneHigh,     double,  wxT("ToneHigh"),      100,     0,       100,  1  );
// Param( WetGain,      double,  wxT("WetGain"),       -1,      -20,     10,   1  );
// Param( DryGain,      double,  wxT("DryGain"),       -1,      -20,     10,   1  );
// Param( StereoWidth,  double,  wxT("StereoWidth"),   100,     0,       100,  1  );
// Param( WetOnly,      bool,    wxT("WetOnly"),       false,   false,   true, 1  );

static const struct
{
   std::string name;
   EffectReverb::Params params;
} FactoryPresets[] = {
   //                         Room  Pre            Hf       Tone Tone  Wet   Dry   Stereo Wet
   // Name                    Size, Delay, Reverb, Damping, Low, High, Gain, Gain, Width, Only
   { "Vocal I",          { 70,   20,    40,     99,      100, 50,   -12,  0,    70,    false } },
   { "Vocal II",          { 50,   0,     50,     99,      50,  100,  -1,   -1,   70,    false } },
   { "Bathroom",          { 16,   8,     80,     0,       0,   100,  -6,   0,    100,   false } },
   { "Small Room Bright", { 30,   10,    50,     50,      50,  100,  -1,   -1,   100,   false } },
   { "Small Room Dark",   { 30,   10,    50,     50,      100, 0,    -1,   -1,   100,   false } },
   { "Medium Room",       { 75,   10,    40,     50,      100, 70,   -1,   -1,   70,    false } },
   { "Large Room",        { 85,   10,    40,     50,      100, 80,    0,   -6,   90,    false } },
   { "Church Hall",       { 90,   32,    60,     50,      100, 50,    0,   -12,  100,   false } },
   { "Cathedral",         { 90,   16,    90,     50,      100, 0,     0,   -20,  100,   false } },
   { "Huamei",            { 75,   0,    50,     50,      100, 100,   -1,  -1,   100,   false } },
};

struct Reverb_priv_t
{
   reverb_t reverb;
   float *dry;
   float *wet[2];
};

EffectReverb::EffectReverb(int preset_ID, int sampleRate)
{
   Params params = FactoryPresets[preset_ID].params;
	
   mParams.mRoomSize = params.mRoomSize;
   mParams.mPreDelay = params.mPreDelay;
   mParams.mReverberance = params.mReverberance;
   mParams.mHfDamping = params.mHfDamping;
   mParams.mToneLow = params.mToneLow;
   mParams.mToneHigh = params.mToneHigh;
   mParams.mWetGain = params.mWetGain;
   mParams.mDryGain = params.mDryGain;
   mParams.mStereoWidth = params.mStereoWidth;
   mParams.mWetOnly = params.mWetOnly;

   mSampleRate = sampleRate;
}

EffectReverb::~EffectReverb()
{
}

// EffectClientInterface implementation

unsigned EffectReverb::GetAudioInCount()
{
   return mParams.mStereoWidth ? 2 : 1;
}

unsigned EffectReverb::GetAudioOutCount()
{
   return mParams.mStereoWidth ? 2 : 1;
}

bool EffectReverb::ProcessInitialize(int numChans)
{
   mNumChans = (numChans > 2)? 2 : numChans;

   mP = (Reverb_priv_t *) calloc(sizeof(*mP), mNumChans);

   for (unsigned int i = 0; i < mNumChans; i++)
   {
      reverb_create(&mP[i].reverb,
                    mSampleRate,
                    mParams.mWetGain,
                    mParams.mRoomSize,
                    mParams.mReverberance,
                    mParams.mHfDamping,
                    mParams.mPreDelay,
                    mParams.mStereoWidth * ((mNumChans>1) ? 1 : 0),
                    mParams.mToneLow,
                    mParams.mToneHigh,
                    MAX_AUDIO_SAMPLES,	//typical value = 16384
                    mP[i].wet);
   }

   return true;
}

bool EffectReverb::ProcessFinalize()
{
   for (unsigned int i = 0; i < mNumChans; i++)
   {
      reverb_delete(&mP[i].reverb);
   }

   free(mP);

   return true;
}

int EffectReverb::ProcessBlock(float **inBlock, float **outBlock, int blockLen)
{
   float *ichans[2] = {NULL, NULL};
   float *ochans[2] = {NULL, NULL};

   for (unsigned int c = 0; c < mNumChans; c++)
   {
      ichans[c] = inBlock[c];
      ochans[c] = outBlock[c];
   }
   
   float const dryMult = (float)(mParams.mWetOnly ? 0 : dB_to_linear(mParams.mDryGain));

   auto remaining = blockLen;

   while (remaining)
   {
      auto len = std::min(remaining, decltype(remaining)(MAX_AUDIO_SAMPLES));
      for (unsigned int c = 0; c < mNumChans; c++)
      {
         // Write the input samples to the reverb fifo.  Returned value is the address of the
         // fifo buffer which contains a copy of the input samples.
         mP[c].dry = (float *) fifo_write(&mP[c].reverb.input_fifo, len, ichans[c]);
         reverb_process(&mP[c].reverb, len);
      }

      if (mNumChans == 2)
      {
         for (decltype(len) i = 0; i < len; i++)
         {
            for (int w = 0; w < 2; w++)
            {
               ochans[w][i] = (float)(dryMult *
                              mP[w].dry[i] +
                              0.5 *
                              (mP[0].wet[w][i] + mP[1].wet[w][i]));
            }
         }
      }
      else
      {
         for (decltype(len) i = 0; i < len; i++)
         {
            ochans[0][i] = dryMult * 
                           mP[0].dry[i] +
                           mP[0].wet[0][i];
         }
      }

      remaining -= len;

      for (unsigned int c = 0; c < mNumChans; c++)
      {
         ichans[c] += len;
         ochans[c] += len;
      }
   }

   return blockLen;
}

//void EffectReverb::save_pcm_to_file(float *pBuff, size_t sampleCnt)
//{
//	__int16 *p_intbuf = new __int16[sampleCnt];
//	for (size_t i=0;i<sampleCnt;i++)
//	{
//		p_intbuf[i] = std::max<__int16>(-32767, std::min<__int16>((__int16)(pBuff[i]*32768), 32767));
//	}
//
//    fstream binary_file("output.pcm",ios::out|ios::binary);
//    binary_file.write(reinterpret_cast<char *>(p_intbuf),sampleCnt*sizeof(__int16));
//    binary_file.close();
//
//	delete p_intbuf;
//}
//
//size_t EffectReverb::load_pcm_from_file(float *pBuff)
//{
//    fstream binary_file("mono.pcm",ios::binary|ios::in);
//
//	binary_file.seekg(0, binary_file.end);
//    size_t fileLenInBytes = fileLenInBytes = (size_t)(binary_file.tellg());
//	size_t sampleCnt = std::min<size_t>(MAX_AUDIO_SAMPLES, fileLenInBytes/sizeof(__int16));
//
//	__int16 *p_intbuf = new __int16[sampleCnt];
//
//	binary_file.seekg(0, binary_file.beg);
//    binary_file.read(reinterpret_cast<char *>(p_intbuf),sampleCnt*sizeof(__int16));
//    binary_file.close();
//
//	for (size_t i=0;i<sampleCnt;i++)
//	{
//		pBuff[i] = (float)(p_intbuf[i])/32768;
//	}
//
//	delete p_intbuf;
//
//	return sampleCnt;
//}
