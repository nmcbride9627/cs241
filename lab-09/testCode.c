#include "huffman.h"

int main(int argc, char* argv[]) {
  char* infile;
  int freqency[256] = {0};
  int totalNumChars;
  FILE* in;
  infile = argv[1];
  in = fopen(infile, "rb");
  totalNumChars = genFreqArray(in, freqency);
  printFreq(freqency);
  printf("Total number chars = %d\n", totalNumChars);
  return 0;
}
