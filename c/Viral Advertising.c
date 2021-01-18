#include<stdio.h>
int main()
{
    int n,p=5,com=2;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
       p=floor(p/2)*3;
       com+=floor(p/2);
    }
    printf("%d",com);
    
 

}
