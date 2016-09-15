/*********************/
/* Nathaniel McBride */
/* October 3, 2016   */
/* CS-241-002        */
/*********************/
#include <stdio.h>
#include <stdbool.h>

int getNextBoard(char *sudokuBoard)
{
  int i = 0;
  int c = 0;
  bool hasInvalidCharacter = false;

  while((c = getchar()) != EOF)
  {
    printf("%c", c);
    if(c == '\n')
    {
      if (hasInvalidCharacter)
      {
        return 3;
      }
      else if (i < 81)
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
    else if(c != '.' && (c < '1' || c > '9'))
    {
      hasInvalidCharacter = true;
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
    if(errorCode == 1)
    {
      printf("Error: board too short\n");
    }
    else if(errorCode == 2)
    {
      printf("Error: board too long\n");
    }
    else if(errorCode == 3)
    {
      printf("Error: invalid character\n");
    }
    else if(errorCode == -1)
    {
      printf("End of File\n");
    }
    else
    {
      printf("Good to go!\n");
    }
  }
  return 0;
}
