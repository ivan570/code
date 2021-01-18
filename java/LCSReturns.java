import java.util.Scanner;

public class LCSReturns {

    private static Scanner scanner = new Scanner(System.in);

    private static String LCS(String one, String two) {

        int n = one.length(), m = two.length();
        int[][] ans = new int[n + 1][m + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 || j == 0)
                    ans[i][j] = 0;
                else if (one.charAt(i - 1) == two.charAt(j - 1)) {
                    ans[i][j] = ans[i - 1][j - 1] + 1;
                } else {
                    ans[i][j] = Math.max(ans[i][j - 1], ans[i - 1][j]);
                }
            }
        }
        int i = n, j = m;
        StringBuilder s = new StringBuilder();

        while (i > 0 && j > 0) {
            if (one.charAt(i - 1) == two.charAt(j - 1)) {
                s.append(one.charAt(i - 1));
                i--;
                j--;
            }

            else if (ans[i][j - 1] > ans[i - 1][j]) {
                j--;
            } else {
                i--;
            }
        }
        return s.reverse().toString();
    }

    public static void main(String[] args) {
        String oneString = scanner.next();
        String twoString = scanner.next();

        System.out.println(LCS(oneString, twoString));
    }
}