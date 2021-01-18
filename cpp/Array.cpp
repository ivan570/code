#include<iostream>
using namespace std;
int main()  {
   int ar[5];
   ar[0]=10;
   ar[1]=11;
   ar[2]=12;
   ar[3]=13;
   ar[4]=14;

   int temp = (int)(ar+3);
   cout<<" a + 3 is "<<(ar+3)<<endl;
   cout<<" temp is "<<temp<<endl;
   cout<<" a[3] is "<<*(ar+3)<<endl;
   // cout<<" *temp is "<<*temp<<endl;

   int *p = (ar+1);
   int *q = (ar+3);
   // not possible to do that :::::::>
   // cout<<"p+q is "<<(p+q)<<endl;
   // only subtraction are allow to do :::::::>
   cout<<"p-q is "<<(p-q)<<endl;
   return 0;
}
