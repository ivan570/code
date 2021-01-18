#include <iostream>
using namespace std;
int main()
{
    system("cls");
    int n ,a ,b;
    cin >> n;
    int sum = 0 , sum1=0;
    for(int k =0 ; k < n ;k++)
    {
        sum =0 ;
        cin >> a >> b;
        int c0[a];
        for(int i =0 ; i < a ; i++)
        {
            cin >> c0[i];
            sum1 +=c0[i];
            if(c0[i] > b)
                sum += b ;
            else 
                sum +=c0[i];
        }
        cout << sum1-sum ;
    }
}