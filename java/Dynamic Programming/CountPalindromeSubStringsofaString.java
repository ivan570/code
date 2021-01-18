import java.util.Scanner;

public class CountPalindromeSubStringsofaString {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        for (int i = 0; i < n; ++i)
            cases();
    }

    static void cases() {
        int len = scanner.nextInt();scanner.nextLine();
        String str = scanner.nextLine();
        System.out.println(countPS(str, len));
    }

    static int countPS(String str, int len) {
        int[][] dyna= new int[len][len];
        for (int i = len - 1; i >= 0; --i) {
            for (int j = 0; j < len; ++j) {
                if (i > j)
                    dyna[i][j] = 0;
                else if (i == j)
                    dyna[i][j] = 0;
                else {
                    dyna[i][j] = dyna[i + 1][j] + dyna[i][j - 1] - dyna[i + 1][j - 1] + isP(str, i, j);
                }
            }
        }
        for (int[] arr : dyna) {
            for (int k : arr)
                System.out.print(k + " ");
            System.out.println();
        }
        return dyna[0][len - 1];
    }

    private static int isP(String str, int i, int j) {
        while (i <= j && i < str.length() && j >= 0) {
            if (str.charAt(i) != str.charAt(j))
                return 0;
            i++;
            j--;
        }
        return 1;
    }
}
