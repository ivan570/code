import static java.lang.System.out;
import java.util.*;

class GFG {
	static Scanner in = new Scanner(System.in);

	public static void main(String[] args) {
		for (int T = in.nextInt(); T-- > 0;) {
			int n = in.nextInt();

			Geeks obj = new Geeks();
			out.println(obj.count(n));
		}
	}
}

class Geeks {
	public long count(int n) {
		long arr[] = new long[n + 1];

		Arrays.fill(arr, 0);
		int value[] = { 3, 5, 10 };
		arr[0] = 1;
		for (int k : value) {
			for (int i = k; i <= n; ++i)
				arr[i] += arr[i - k];
		}
		return arr[n];
	}
}