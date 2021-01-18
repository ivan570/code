#include<stdio.h>


int main() {

    
int t,no,m,sw,sd;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        scanf("%d %d %d", &no, &m, &sw);
         sd=(sw+m-1)% no;

        if(sd==0)
             printf("%d\n",no);
        else
            printf("%d\n",sd);
    }

    return 0;
}
