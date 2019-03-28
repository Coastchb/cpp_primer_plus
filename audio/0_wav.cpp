#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// add header for pcm file

template <typename Word>
bool write_word(std::ostream& outs, Word value, unsigned size = sizeof(Word))
{
  for (; size; --size, value >>= 8)
    outs.put(static_cast <char> (value & 0xFF));
  return true;
}

bool add_header(const string& pcm_file, const string& wav_file) {
  ofstream fw(wav_file, ios::binary );
  // Write the file headers
  fw << "RIFF----WAVEfmt ";     // (chunk size to be filled in later)
  write_word( fw,     16, 4 );  // no extension data
  write_word( fw,      1, 2 );  // PCM - integer samples
  write_word( fw,      1, 2 );  // two channels (stereo file)
  write_word( fw,  16000, 4 );  // samples per second (Hz)
  write_word( fw, 64000, 4 );  // (Sample Rate * BitsPerSample * Channels) / 8
  write_word( fw,      4, 2 );  // data block size (size of two integer samples, one for each channel, in bytes)
  write_word( fw,     16, 2 );  // number of bits per sample (use a multiple of 8)

  // Write the data chunk header
  size_t data_chunk_pos = fw.tellp();
  fw << "data----";  // (chunk size to be filled in later)

  // read headless pcm file
  FILE* fr;
  fr = fopen(pcm_file.c_str(), "rb");
  while ( !feof(fr) ) {
    short aa;
    size_t num = fread(&aa, sizeof(short), 1, fr);
    write_word(fw, aa, 2);
  }

  // (We'll need the final file size to fix the chunk sizes above)
  size_t file_length = fw.tellp();

  // Fix the data chunk header to contain the data size
  fw.seekp( data_chunk_pos + 4 );
  write_word( fw, file_length - data_chunk_pos + 8 );

  // Fix the file header to contain the proper RIFF chunk size, which is (file size - 8) bytes
  fw.seekp( 0 + 4 );
  write_word( fw, file_length - 8, 4 );

  fclose(fr);
  fw.close();

  return true;
}

int main()
{
  string pcm_file = "data/sen_1.pcm";
  string wav_file = "data/sen_1_addheader.wav";
  if (!add_header(pcm_file, wav_file))
    cerr << "error while adding header.\n";
}
