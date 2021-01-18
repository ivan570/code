package dynamic;

import java.util.Scanner;

// time complexity is = O(n)
abstract class Solution {
	public static Scanner scanner = new Scanner(System.in);

	// Kadane’s Algorithm
	public static int maxSubstring(String str) {
		int ans = -1;
		int temp = 0;
		for (char ch : str.toCharArray()) {
			int value = -1;
			if (ch == '0') value = 1;
			temp += value;
			ans = Math.max(ans, temp);
			temp = Math.max(0, temp);
		}
		return ans < 0 ? -1 : ans;
	}
}

public class MaximumDifferenceOfZerosAndOncesInBinaryString extends Solution{

	public static void main(String[] args) {
		System.out.println(maxSubstring(scanner.next()));
	}
}
