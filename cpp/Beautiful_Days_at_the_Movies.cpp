#include<iostream>
using namespace std;

int reverse(int n)
{
	int rev = 0;
	int remainder;
	while (n != 0) {
        remainder = n % 10;
        rev = rev * 10 + remainder;
        n /= 10;
    }
    return rev;
}

int diff(int x , int y)
{
	if(x > y)
		return (x-y);

	else
		return (y-x);
}

int main() {
	int first;
	int last;
	int div;
	int cou = 0;

	cin>>first>>last>>div;
	for(int i = first ; i <= last ; i++)
	{
		int temp = reverse(i);
		//cout<<"\n temp "<<temp;
		temp = diff(temp,i);
		if( (temp%div) == 0 )
		{
			cou++;
		}
	}

	cout<<cou;
	return 0;
}
