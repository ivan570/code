#include<stdio.h>
int main()
{
    int n,num,k,count=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        count=0;
        scanf("%d%d",&num,&k);
        int a[num];
        for(int j=0;j<num;j++)
        {
            scanf("%d",&a[i]);
            if(a[i]<=0)
            {
                count++;
            }
        }
        if(count>=k)
        printf("NO\n");
        else {
        printf("YES\n");
        }

    }
}
