 #include <iostream>
 using namespace std;

 int main() {
	 int n, k, ans = 0;
	 cin >> n >> k;
	 int arr[k] = {0};
	 for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		temp = temp % k;
		arr[temp]++;
	 }
	 for (int i = 0; i <= k/2; i++) {
		if (i == 0) {
			ans += arr[0];
			continue;
		}
		if(i+i == k)
			break;
		int temp = k - i;
		if (arr[i] > arr[temp])
			ans += arr[i];
		else
			ans += arr[temp];
	 }
	 if ( k == 1)
	 {
	 	cout << "1";
	 	return 0;
	 }
	cout << ans;
    return 0;
}
