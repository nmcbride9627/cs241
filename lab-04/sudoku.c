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
bool isValid(char *sudokuBoard, int postion)
{
  int row = postion / 9;
  /*int col = postion % 9;*/
  int i,j;
  for(i = row * 9; i < (row * 9) + 8; i++)
  {
    for(j = i + 1 ; (row * 9) + 9; j++)
    {
      if((sudokuBoard[i] == sudokuBoard[j]) && (i != j))
      {
        printf("found duplicate\n");
        return false;
      }
    }
  }
  printf("no dupes\n");
  return true;
}
void printBoard(char *sudokuBoard)
{
  int i;
  for(i = 0; i < 81; i++)
  {
    if(i % 9 == 0)
    {
      printf("\n");
    }
    printf("%c", sudokuBoard[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  /* Error codes:
   * -1 = EOF
   *  0 = None
   *  1 = Board too short
   *  2 = Board too long
   *  3 = Invalid character
   *  4 = Invalid board
   */
  int errorCode = 0;
  char sudokuBoard[81];
  while(errorCode != -1)
  {
    errorCode = getNextBoard(sudokuBoard);
    if(errorCode && errorCode != -1)
    {
      printf("Error\n");
    }
    else
    {
      isValid(sudokuBoard, 0);
      isValid(sudokuBoard, 9);
      isValid(sudokuBoard, 18);
      isValid(sudokuBoard, 27);
      isValid(sudokuBoard, 36);
      isValid(sudokuBoard, 45);
      isValid(sudokuBoard, 54);
      isValid(sudokuBoard, 63);
      isValid(sudokuBoard, 72);
      /*solve board*/
      /*print solution*/
      /*if no soulution print no solution*/

    }
    printf("\n");
  }
  return 0;
}
