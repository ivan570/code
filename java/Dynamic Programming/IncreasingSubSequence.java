import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	static Scanner scanner = new Scanner(System.in);
	public static void main (String[] args) {
		int n = scanner.nextInt();
		for (int i = 0; i < n; ++i)
			testCase();
	}
	static void testCase() {
		String str = scanner.next();
		System.out.println(longestSubsequence(str.length(), str));
	}
	static int longestSubsequence(int size, String arr) {

		if (arr.length() < 2)
			return arr.length();
		int dyna[] = new int[arr.length()];
		dyna[0] = 1;
		int finalAns = 1;
		for (int i = 1; i < arr.length(); ++i) {
			int ans = 0;
			for (int j = i - 1; j >= 0; --j)
				if (arr.charAt(i) > arr.charAt(j))
					ans = Math.max(ans, dyna[j]);
			dyna[i] = ans + 1;
			finalAns = Math.max(finalAns, dyna[i]);
		}
		return finalAns;
	}
}