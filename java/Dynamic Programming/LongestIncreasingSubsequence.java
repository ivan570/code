import java.io.*;
import java.util.*;

public class LongestIncreasingSubsequence {
	static Scanner sc = new Scanner(System.in);

	public static void main(String args[]) throws IOException {
		int t = sc.nextInt();
		while (t > 0) {

			int n = sc.nextInt();
			int array[] = new int[n];

			for (int i = 0; i < n; ++i) {
				array[i] = sc.nextInt();
			}

			Solution ob = new Solution();

			System.out.println(ob.longestSubsequence(n, array));
			t--;
		}
	}
}

class Solution {
	int longestSubsequence(int size, int arr[]) {

		if (arr.length < 2)
			return arr.length;
		int dyna[] = new int[arr.length];
		dyna[0] = 1;
		int finalAns = 1;
		for (int i = 1; i < arr.length; ++i) {
			int ans = 0;
			for (int j = i - 1; j >= 0; --j)
				if (arr[i] > arr[j])
					ans = Math.max(ans, dyna[j]);
			dyna[i] = ans + 1;
			finalAns = Math.max(finalAns, dyna[i]);
		}
		return finalAns;
	}
}