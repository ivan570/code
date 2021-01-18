#include <stdio.h>
int main()  {
   char ch[] = "Ivankshu";
   char *p = ch;
   printf("%s",p+p[3]-p[4]);
   char ch[] = "ivan";
   puts(ch);
   return 0;
}
