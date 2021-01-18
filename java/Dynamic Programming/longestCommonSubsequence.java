import java.util.*;

public class longestCommonSubsequence {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {

		int test = sc.nextInt();
		while (test-- > 0) {
			int p = sc.nextInt(); // Take size of both the strings as input
			int q = sc.nextInt();

			String s1 = sc.next(); // Take both the string as input
			String s2 = sc.next();

			LCS obj = new LCS();

			System.out.println(obj.lcs(p, q, s1, s2));
		}
	}
}

class LCS {

	int lcs(int p, int q, String first, String second) {
		int arr[][] = new int[first.length() + 1][second.length() + 1];

		for (int i = 0; i <= first.length(); ++i) {
			for (int j = 0; j <= second.length(); ++j) {
				if (i == 0 || j == 0)
					arr[i][j] = 0;
				else if (first.charAt(i - 1) == second.charAt(j - 1))
					arr[i][j] = arr[i - 1][j - 1] + 1;
				else
					arr[i][j] = Math.max(arr[i][j - 1], arr[i - 1][j]);
			}
		}

		return arr[first.length()][second.length()];
	}
}