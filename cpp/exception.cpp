#include<iostream>
using namespace std;
int main()  {
   try{
      throw "23";
   }catch(...){
      cout<<"ivan";
   }
   return 0;
}
