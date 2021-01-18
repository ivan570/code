#include<stdio.h>
int main()
{
    long int n,m,d=0,k=0;
    long int b;
    scanf("%ld%ld%ld",&b,&n,&m);
    long int a[n],s[m],h[b];
    long int sum=0;
    for(long int i=0;i<n;i++)
    scanf("%ld",&a[i]);
    for(long int j=0;j<m;j++){
        scanf("%ld",&s[j]);}

    for(long int i=0;i<n;i++)
    {for(long int j=0;j<m;j++)
    {
    sum=a[i]+s[j];
    if(sum<=b)
    {
     d++;
     if(sum>k)
     {
         k=sum;
     }
    }}}
    if(d>0)
    {
        printf("%ld",k);
    }
    else {
    printf("-1");
    }
}

