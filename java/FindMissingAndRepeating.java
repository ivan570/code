import java.util.Scanner;
import java.util.Vector;

public class FindMissingAndRepeating {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int t = scanner.nextInt();
        for (int r = 0; r < t; ++r) {
            int n = scanner.nextInt();
            int[] vs = new int[n + 1];
            for (int i = 0; i < n; ++i) {
                int temp = scanner.nextInt();
                vs[temp] = vs[temp] + 1;
            }
            int f = 0, s = 0;
            for (int i = 1; i <= n; ++i) {
                if (f == 0 && vs[i] > 1) {
                    f = i;
                }
                if (s == 0 && vs[i] == 0)
                    s = i;
                if (s != 0 && f != 0)
                    break;
            }
            System.out.println(f + " " + s);
        }
    }
}
