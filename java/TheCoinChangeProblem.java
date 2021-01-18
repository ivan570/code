import java.util.Scanner;

public class TheCoinChangeProblem {

    private static Scanner scanner = new Scanner(System.in);

    private static long coinChange(int[] arr, int cap) {
        int n = arr.length;
        long[][] ans = new long[cap + 1][n + 1];
        for (int i = 0; i <= cap; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (j == 0 && i != 0)
                    ans[i][j] = 0;
                else if (i == 0)
                    ans[i][j] = 1;
                else if (arr[j - 1] <= i) {
                    ans[i][j] = ans[i][j - 1] + ans[i - arr[j - 1]][j];
                } else
                    ans[i][j] = ans[i][j - 1];
            }
        }
        return ans[cap][n];
    }

    public static void main(String[] args) {
        int cap = scanner.nextInt();
        int n = scanner.nextInt();

        int[] arr = new int[n];
        for (int i = 0; i < n; ++i)
            arr[i] = scanner.nextInt();

        System.out.println(coinChange(arr, cap));
    }
}
