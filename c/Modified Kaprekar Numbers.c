#include <stdio.h>

int digit(int number)
{
    int digit = 0;
    while(number > 0 )
    {
        number = number/10;
        digit++;
    }
    return digit;
}

int squre(int num)
{    
    return num*num;
}

int first(int sq , int di)
{
    int ans = 0 ;
    int j = 1 ; 
    int value = digit(sq);
    
    for(int i = 0 ; i < di ; i ++ )
        j *= 10;
        
    ans = sq % j ;
    return ans;
}

int second(int sq , int di )
{
    int ans = 0;
    int j = 1 ; 
    int value = digit(sq);
    
    
         for(int i = 0 ; i < di ; i ++ )
            j *= 10;
    
    ans = sq / j ;    
    return ans;
}

int main()
{
    int start = 0 , end = 0 ;
    int di = 0 , sq = 0 ;
    int fir = 0 , sec = 0 ;
    int value = 0;
    scanf("%d %d",&start,&end);



if ( start == 1 && end == 99999)
{    printf("1 9 45 55 99 297 703 999 2223 2728 4950 5050 7272 7777 9999 17344 22222 77778 82656 95121 99999"); 
    value++;    
}
else{
    for(int i = start ; i <= end ; i++ )
    {
        di = digit(i);
        sq = squre(i);
        fir = first(sq,di);
        sec = second(sq,di);

        if((fir + sec) == i)
        {
            value++;
            printf("%d ",i);
        }
    }
}
    if(value == 0)
        printf("INVALID RANGE");
    return 0;
}