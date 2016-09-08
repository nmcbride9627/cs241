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
  int lineMostWords, lineMostChars;
  int lineMostWordsWC, lineMostCharsCC;
  int lineStart;

  state = OUT;
  totalLines = totalWords = totalChars = 0;
  currentLineWC = currentLineCC = 0;
  lineMostWords = lineMostChars = 0;
  lineMostWordsWC = lineMostCharsCC = 0;
  lineStart = TRUE;

  while ((c = getchar()) != EOF){
    /*this prints the line number*/
    if(lineStart)
    {
      printf("%d.", totalLines + 1);
      lineStart = FALSE;
    }
    /*checks for delimiters and increments the respective counts*/
    if (c == ' ' || c == '\n' || c == '\t')
    {
      state = OUT;
      /*singles out newline for special maximum count checks*/
      if (c == '\n')
      {
        ++totalLines;
        printf("[%d;%d]", currentLineWC, currentLineCC);
        printf("%c", c);

        totalChars += currentLineCC;
        totalWords += currentLineWC;
        /*line with most words check*/
        if(currentLineWC > lineMostWordsWC)
        {
          lineMostWords = totalLines;
          lineMostWordsWC = currentLineWC;
        }
        /*line with most charaters check*/
        if(currentLineCC > lineMostCharsCC)
        {
          lineMostChars = totalLines;
          lineMostCharsCC = currentLineCC;
        }
        currentLineWC = currentLineCC = 0;
        lineStart = TRUE;
      }
      /*echos and counts spaces and tabs*/
      else
      {
        ++currentLineCC;
        printf("%c", c);
      }
    }
    /*echos and counts the first character in each word
     *and counts each word*/
    else if (state == OUT)
    {
      state = IN;
      ++currentLineWC;
      ++currentLineCC;
      printf("%c", c);
    }
    /*echos and counts all other characters*/
    else{
      ++currentLineCC;
      printf("%c", c);
    }
  }
  printf("%d lines, %d words, %d characters\n",
        totalLines, totalWords, totalChars);
  printf("With %d, line %d has the most characters\n",
        lineMostCharsCC, lineMostChars);
  printf("With %d, line %d has the most words\n",
        lineMostWordsWC, lineMostWords);
  return 0;
}
