#include<iostream>
using namespace std;
int main()  {
   char a[] = "ivankshu";
   char *p = "vaghani";
   char *temp;
   cout<<"a before any action ";
   puts(a);
   cout<<"p before any action ";
   puts(p);

   a[4] = 'h';
   // p[4] = 'h';
   // it not possible;

   cout<<"a after any action ";
   puts(a);
   cout<<"p after any action ";
   puts(p);

   // while( *temp++ = *p++);
   cout<<"temp start"<<endl;
   // int c = 65;
   // while(c<91)
   // {
   //    *temp++ += (char)c;
   //    c++;
   // }

   cout<<"temp ";
   puts(temp);

   return 0;
}
