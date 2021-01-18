import java.util.Scanner;

public class Knapsack {

    private static Scanner scanner = new Scanner(System.in);

    private static int knapsack(int arr[], int cap) {

        int n = arr.length;
        int[][] ans = new int[cap + 1][n + 1];

        for (int i = 0; i <= cap; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 || j == 0)
                    ans[i][j] = 0;
                else if (arr[j - 1] <= i) {
                    ans[i][j] = Math.max(ans[i][j - 1], arr[j - 1] + ans[i - arr[j - 1]][j]);
                } else
                    ans[i][j] = ans[i][j - 1];
            }
        }
        return ans[cap][n];
    }

    public static void main(String[] args) {
        int t = scanner.nextInt();
        while (t-- > 0) {
            int n = scanner.nextInt();
            int cap = scanner.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; ++i) {
                arr[i] = scanner.nextInt();
            }
            System.out.println(knapsack(arr, cap));
        }
    }
}
