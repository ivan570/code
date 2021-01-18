package Array_pac;

import java.util.Scanner;

public class New_Year_Chaos {
	
	public static void value( int arr[], int n) {
		int val = 0;
		for(int i = n - 1; i >= 0; i--) {
			if( arr[i] - ( i + 1 ) > 2 ) {
				System.out.println("Too chaotic");
				return;
			}
		}
		
		for(int i = n - 1; i >= 0; i--) {
			for(int j = Math.max(0, (arr[i] - 2)); j < i; j++) {
				if(arr[j] > arr[i])
					val++;
			}
		}
		
		System.out.println(val);
	}
	
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		int t = scanner.nextInt();
		
		for (int tItr = 0; tItr < t; tItr++) {
            int n = scanner.nextInt();
            int arr[] = new int[n];
            for(int i = 0; i < n; i++) {
            	arr[i] = scanner.nextInt();
            }
            value(arr , n);
		}
	}
}
