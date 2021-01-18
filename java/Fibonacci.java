import java.util.*;
import java.math.*;

public class Fibonacci {
    static int t1, t2;

    static BigInteger fib(int n) {
        BigInteger v;
        BigInteger a = BigInteger.valueOf(t1);
        BigInteger b = BigInteger.valueOf(t2);
        BigInteger c = BigInteger.valueOf((t1 + t2 * t2));
        for (int j = 2; j <= n; j++) {
            v = b.multiply(b);
            c = a.add(v);
            a = b;
            b = c;
        }

        return (a);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        t1 = scan.nextInt();
        t2 = scan.nextInt();
        int n = scan.nextInt();
        System.out.println(fib(n));
        scan.close();
    }
}
