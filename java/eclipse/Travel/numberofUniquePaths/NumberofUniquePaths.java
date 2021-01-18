package numberofUniquePaths;

import java.util.Scanner;

public class NumberofUniquePaths  {
	static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		int test = scanner.nextInt();
		for (int i = 0; i < test; ++i)
			test_case();
	}

	static void test_case() {
		int m = scanner.nextInt();
		int n = scanner.nextInt();

		System.out.println(function(m, n));
	}

	private static int function(int m, int n) {

		int arr[][] = new int[m + 1][n + 1];
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == 1 || j == 1)
					arr[i][j] = 1;
				else
					arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			}
		}
		return arr[m][n];
	}
}