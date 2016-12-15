#include <stdio.h>

int  main()
{
char s[] = "QfQQinQalQ";
char  del = ’Q’;
int  sourceIndex = 0;
int  destIndex = 0;
while (s[sourceIndex ])
{
if (s[sourceIndex] != del)
{
s[destIndex] = s[sourceIndex ];
destIndex ++;
}
else
{
printf("[%d,%d] %s\n", sourceIndex , destIndex , s);
}
sourceIndex ++;
}
s[destIndex ]=’\0’;
printf("result: %s\n",s);
return  0;
}
