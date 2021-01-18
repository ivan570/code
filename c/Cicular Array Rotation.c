
#include<stdio.h>
int main()
{
    int n1,d=0,n,k,i,q;
    scanf("%d %d %d",&n,&k,&q);
    n1=n+k;
    int a[n1],m[q];
    for(i=0;i<n1;i++){
        if(i<k){
            a[i]=0;
        }
        else
        scanf("%d",&a[i]);
    }
    for(i=0;i<q;i++){
        scanf("%d\n",&m[i]);
    }
        for(i=0;i<k;i++){
        d=a[n1-1-i];
            a[n1-1-i]=a[k-1-i];
            a[k-1-i]=d;
    }
    for(i=0;i<q;i++){
        printf("%d\n",a[m[i]]);
    }
}
