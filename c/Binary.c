#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	long long int arr[t];
	for(int i = 0 ; i < t ; i++)
		scanf("%lld",&arr[i]);

	long long int temp = 4294967295;
	for(int i = 0 ; i < t ; i++ )
		printf("%lld\n",(temp - arr[i]) );
	return 0;
}