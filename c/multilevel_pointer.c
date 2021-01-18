#include <stdio.h>
int main()
{
   int a[] = { 10,20,30,40,50,60 };
   int *p[] = { a,a+1,a+2,a+3,a+4,a+5 };
   int **pp = p;
   printf("%d\n",pp);
   printf("%d\n",p);
   printf("%d\n",a);
   return 0;
}
