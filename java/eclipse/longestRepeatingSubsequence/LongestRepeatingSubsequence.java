package longestRepeatingSubsequence;

import java.util.Scanner;

public class LongestRepeatingSubsequence {
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        int t = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < t; ++i)
            cases();
    }

    static void cases() {
        int n = scanner.nextInt();
        scanner.nextLine();
        String str = scanner.next();
        System.out.println(repeating(n, str));
    }

    static int repeating(int n, String str) {
        int[][] arr = new int[n + 1][n + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 || j == 0)
                    arr[i][j] = 0;
                else if (i != j && str.charAt(i - 1) == str.charAt(j - 1))
                    arr[i][j] = arr[i - 1][j - 1] + 1;
                else
                    arr[i][j] = Math.max(arr[i][j - 1], arr[i - 1][j]);
            }
        }
        return arr[n][n];
    }
}
