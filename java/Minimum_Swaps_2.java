package Array_pac;

import java.util.*;

public class Minimum_Swaps_2 {
	
	private static Scanner in = new Scanner(System.in);
	public static int output(int arr[],int n) {
		int swap = 0;
		int temp[] = new int[n + 1];
		temp[0] = -1;
		for(int i = 1;i <= n;i++) {
			temp[arr[i-1]] = i-1;
		}
		
		for(int i = 0; i < n; i++) {
			if(arr[i] != i+1) {
				int t = arr[i];
				arr[i] = i + 1;
				arr[temp[i+1]] = t;
				temp[t] = temp[i + 1];
				swap++;
			}
		}
		
		return swap;
	}
	public static void main(String[] args) {
		int n = in.nextInt();
		int arr[] = new int[n];
		for(int i = 0; i < n; i++) 
			arr[i] = in.nextInt();
		
		System.out.println(output(arr, n));
	}
}
