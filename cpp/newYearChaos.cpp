#include <iostream>
using namespace std;

void swap(int arr[],int i,int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void output(int arr[], int n) {
    int cou = 0;
    for(int i = n-1; i >= 0; i--) {
        if(arr[i] != i+1) {
            if(i >= 1 && arr[i - 1] == (i + 1)) {
                cou++;
                swap(arr, i, i - 1);
            }
            else if(i > 1 && arr[i - 2] == (i + 1)) {
                cou += 2;
                swap(arr, i - 2, i - 1);
                swap(arr, i, i - 1);
            }
            else {
                printf("Too chaotic");
                return ;
            }
        }
    }
    printf("%d\n",cou );
}

int main() {
    int t;
    cin >> t;
    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        output(arr, n);
    }
    return 0;
}
