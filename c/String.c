#include <stdio.h>
#include <ctype.h>
 
int main()
{
  printf("enter the string");
  char c[4000];
  gets(c);
  int f='c';
  char  buf[] = "1234";
  char max = 0;
  int i;
   
  for (i = 0; buf[i] != '\0'; i++)
    max = ( isdigit( buf[ i ] ) && buf[ i ] > max ? buf[ i ] : max );
     
  printf ("Biggest character in string is %c\n", max);
   
 return 0;
}
