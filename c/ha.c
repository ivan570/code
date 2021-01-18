#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[1000000];
    int count=0;
    int n,i;
    for(i=0;i<5;i++)
    {
        scanf(" %c",&a[i]);
        int value=(int)a[i];
        if(value==97)
        {
            count++;
        }
        if(value==0)
        {
            break;
        }
    }
    printf("count is %d\n",count);
   
    scanf("%d",&n);
    printf("n is %d\n",n);
    printf("%d",n-count);

}

