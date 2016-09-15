/*********************/
/* Nathaniel McBride */
/* October 3, 2016   */
/* CS-241-002        */
/*********************/
#include <stdio.h>

void getNextBoard(int *sudokuBoard)
{
  int i;
  int c = getchar();
  for(i = 0; c != '\n'; c = getchar(), i++)
  {
    sudokuBoard[i] = c;
  }
}

void printBoard(int *sudokuBoard)
{
  int i;
  for(i = 0; i < 81; i++)
  {
    printf("%d\n", sudokuBoard[i]);
  }
}

int main(int argc, char const *argv[]) {
  int sudokuBoard[81];
  getNextBoard(sudokuBoard);
  printBoard(sudokuBoard);
  return 0;
}
