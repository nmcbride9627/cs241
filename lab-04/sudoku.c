/*********************/
/* Nathaniel McBride */
/* October 3, 2016   */
/* CS-241-002        */
/*********************/
#include <stdio.h>

void getNextBoard(char *sudokuBoard)
{
  int i;
  int c = getchar();
  for(i = 0; c != '\n'; c = getchar(), i++)
  {
    sudokuBoard[i] = c;
  }
}

void printBoard(char *sudokuBoard)
{
  int i;
  for(i = 0; i < 81; i++)
  {
    printf("%c", sudokuBoard[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  char sudokuBoard[81];
  getNextBoard(sudokuBoard);
  printBoard(sudokuBoard);
  getNextBoard(sudokuBoard);
  printBoard(sudokuBoard);
  return 0;
}
