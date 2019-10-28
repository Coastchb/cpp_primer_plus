/**********************************************************************

   Audacity: A Digital Audio Editor
   Audacity(R) is copyright (c) 1999-2013 Audacity Team.
   License: GPL v2.  See License.txt.

   Reverb.h
   Rob Sykes, Vaughan Johnson

**********************************************************************/

#ifndef __AUDACITY_EFFECT_REVERB__
#define __AUDACITY_EFFECT_REVERB__

#define MAX_AUDIO_SAMPLES 16000*30

struct Reverb_priv_t;	// defined in Reverb_libSoX.h

class EffectReverb
{
public:
   EffectReverb(int preset_ID, int sampleRate);
   ~EffectReverb();

   struct Params
   {
      double mRoomSize;
      double mPreDelay;
      double mReverberance;
      double mHfDamping;
      double mToneLow;
      double mToneHigh;
      double mWetGain;
      double mDryGain;
      double mStereoWidth;
      bool mWetOnly;
   };
   
   enum settings
   {
	   Vocal_I, 
	   Vocal_II, 
	   Bathroom, 
	   Small_Room_Bright, 
	   Small_Room_Dark, 
	   Medium_Room, 
	   Large_Room, 
	   Church_Hall, 
	   Cathedral,
       Huamei
	};

   int mSampleRate;
   
   // EffectClientInterface implementation

   unsigned GetAudioInCount();
   unsigned GetAudioOutCount();
   bool ProcessInitialize(int mNumChans);
   bool ProcessFinalize();
   int ProcessBlock(float **inBlock, float **outBlock, int blockLen);
   
   void save_pcm_to_file(float *p, int sampleCnt);
   int load_pcm_from_file(float *pBuff);

   float mInBlock[2][MAX_AUDIO_SAMPLES];
   float mOutBlock[2][MAX_AUDIO_SAMPLES];
   
private:
   unsigned int mNumChans;
   Reverb_priv_t *mP;
   Params mParams;
};

#endif
