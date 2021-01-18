#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int test[t];
	for(int i = 0 ; i < t ; i++)
		cin>>test[i];
		
	for(int i = 0 ; i < t ; i++)	
	{	
		long num = test[i];
		long temp = num;
		int count = 0;
		int arr[20];
		while(temp != 0)
		{
			arr[count] = temp%10;
			temp = temp/10;
			count++;
		}
		int ans = 0;
		for(int i = count-1 ; i >=0 ; i-- )
		{
			if(arr[i] != 0)
			{
				if( (num%arr[i]) == 0 )
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
