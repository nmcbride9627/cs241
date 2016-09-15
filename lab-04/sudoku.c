/*********************/
/* Nathaniel McBride */
/* October 3, 2016   */
/* CS-241-002        */
/*********************/
#include <stdio.h>

int getNextBoard(char *sudokuBoard)
{
  int i = 0;
  int c = 0;
  while((c = getchar()) != EOF)
  {
    if(c == '\n')
    {
      if (i < 81)
      {
        return 1;
      }
      else if (i > 81)
      {
        return 2;
      }
      else
      {
        return 0;
      }
    }
    sudokuBoard[i] = c;
    i++;
  }
  return -1;
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
  int errorCode = 0;
  char sudokuBoard[81];
  while(errorCode != -1)
  {
    errorCode = getNextBoard(sudokuBoard);
    printBoard(sudokuBoard);
    printf("Error code:%d\n", errorCode);
  }
  return 0;
}
