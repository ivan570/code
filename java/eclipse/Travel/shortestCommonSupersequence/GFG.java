package shortestCommonSupersequence;

import java.util.*;

class ShortestCommonSupersequence {
	static Scanner sc=new Scanner(System.in);
	public static void main(String[] args) {

		int t = sc.nextInt();

		sc.nextLine();
		while (t-- > 0) {
			String S[] = sc.nextLine().split(" ");
			String X = S[0];
			String Y = S[1];

			System.out.println(shortestCommonSupersequence(X, Y, X.length(), Y.length()));
		}
	}

	public static int shortestCommonSupersequence(String X, String Y, int m, int n) {
		return X.length() + Y.length() - lcs(X, Y);
	}
	static int lcs(String first, String second) {
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