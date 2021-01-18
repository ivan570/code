package dynamic;

import java.util.Scanner;

// 0-1 knapsack problem
public class PizzaMania {
	private static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		int n = scanner.nextInt();
		for (int i = 0; i < n; i++)
			testCase();
	}

	private static void testCase() {
		int capacity = scanner.nextInt();
		int type[] = new int[3];
		int cost[] = new int[3];
		for (int i = 0; i < type.length; i++)
			type[i] = scanner.nextInt();

		for (int i = 0; i < cost.length; i++)
			cost[i] = scanner.nextInt();

		int[][] dynamic = new int[4][capacity + 1];

		for (int i = 0; i < 4; ++i)
			for (int j = 0; j <= capacity; ++j)
				dynamic[i][j] = Integer.MAX_VALUE;

		for (int i = 0; i <= 3; ++i)
			dynamic[i][0] = 0;

		for (int i = 1; i < 4; ++i) {
			for (int j = 1; j <= capacity; j++) {
				if (type[i - 1] <= j) 
					dynamic[i][j] = Math.min(dynamic[i][j - type[i - 1]] + cost[i - 1], dynamic[i - 1][j]);
				else
					dynamic[i][j] = Math.min(dynamic[i - 1][j], cost[i - 1]);
			}
		}
		
		System.out.println(dynamic[3][capacity]);
	}
}
