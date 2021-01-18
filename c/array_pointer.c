#include <stdio.h>

int main()  {
   char *name[] = { "ivan" , "ivankshu" , "vaghani"};
   char *p = *(name+2)+3 ;
   printf("%s\n",p );
   return 0;
}
