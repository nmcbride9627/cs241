#include "huffman.h"

int main(int argc, char* argv[]) {
  char* infile;
  int freqency[256] = {0};
  FILE* in;
  infile = argv[1];
  in = fopen(infile, "rb");

  genFreqArray(in, freqency);
  printFreq(freqency);
  return 0;
}
