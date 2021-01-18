package Algorithum;

import java.util.Scanner;

public class Non_Divisible_Subset {
	
	public static int[][] set(int arr[],int i) {
		int ans[][] = new int[arr.length - 1 - i][2];
		int c = 0;
		for(int k = i + 1; k < arr.length; k++) {
			ans[c][0] = arr[i];
			ans[c][1] = arr[k];
			c++;
		}
		return ans;
	}
	
	public static int output(int arr[],int k) {
		
		return 0;
	}
	
	private static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) {
		int n = in.nextInt();
		int k = in.nextInt();
		int arr[] = new int[n];
		for(int i = 0; i < n; i++) {
			arr[i] = in.nextInt();
		}
		System.out.println(set(arr,k));
	}
}
