package Array_pac;

import java.util.Scanner;

public class Arrays____Left__Rotation {
	@SuppressWarnings("resource")
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int d = in.nextInt();
		int arr[] = new int[n];
		
		for(int i = 0 ; i < n ; i++) {
			arr[i] = in.nextInt();
		}
		
		d = d % n;
		int c = 0;
		int temp [] = new int[n];
		for(int i = d ; i < n ; i++) {
			temp[c] = arr[i];
			c++;
		}
		for(int i = 0 ; i < d ; i++ ) {
			temp[c] = arr[i];
			c++;
		}
		
		for(int i = 0 ; i < n ; i++) {
			System.out.print(temp[i] + " ");
		}
			
	}
}
