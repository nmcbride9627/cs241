/*********************/
/* Nathaniel McBride */
/* September 9, 2016 */
/* CS-241-002        */
/*********************/

#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */
#define TRUE 1
#define FALSE 0

/* count lines, words, and characters in input */
int main()
{
  int c, totalLines, totalWords, totalChars, state;
  int currentLineWC, currentLineCC;
  int lineStart;

  state = OUT;
  totalLines = totalWords = totalChars = 0;
  currentLineWC = currentLineCC = 0;
  lineStart = TRUE;
  printf("%d.", totalLines + 1);
  while ((c = getchar()) != EOF){
    if(lineStart)
    {
      printf("%d.", totalLines + 1); //Print the line number
      lineStart = FALSE;
    }
    if (c == ' ' || c == '\n' || c == '\t') //Check for spaces, newlines, and tabs
    {
      state = OUT;
      if (c == '\n') //Singles out newlines
      {
        ++totalLines;
        printf("[%d, %d]", currentLineWC, currentLineCC);
        printf("%c", c); //echos newline characters

        totalChars += currentLineCC;
        totalWords += currentLineWC;
        currentLineWC = currentLineCC = 0;
        lineStart = TRUE;
      }
      else
      {
        printf("%c", c); //echos spaces and tabs
      }
    }
    else if (state == OUT)
    {
      state = IN;
      ++currentLineWC;
      ++currentLineCC;
      printf("%c", c); //Prints the first letter coming into a word
    }
    else{
      ++currentLineCC;
      printf("%c", c); //echos everything but spaces, tabs, and new lines
    }
  }
  printf("%d lines, %d words, %d characters\n", totalLines, totalWords, totalChars);
  return 0;
}
