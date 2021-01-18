package rodCutting;

import java.util.Scanner;

public class RodCutting {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int t = scanner.nextInt();
        for (int i = 0; i < t; ++i)
            cases();
    }

    static void cases() {
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i)
            arr[i] = scanner.nextInt();
        System.out.println(rodCutting(arr));
    }

    static int rodCutting(int[] arr) {
        int[][] dyna = new int[arr.length + 1][arr.length + 1];
        for (int i = 0; i <= arr.length; ++i) {
            for (int j = 0; j <= arr.length; ++j) {
                if (i == 0 || j == 0)
                    dyna[i][j] = 0;
                else {
                    if (i <= j)
                        dyna[i][j] = Math.max(arr[i - 1] + dyna[i][j - i], dyna[i - 1][j]);
                    else
                        dyna[i][j] = dyna[i - 1][j];
                }
            }
        }
        return dyna[arr.length][arr.length];
    }
}
