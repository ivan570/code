import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class PairsWithSpecificDifference  {
	static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		int test = scanner.nextInt();
		for (int i = 0; i < test; ++i)
			test_case();
	}

	private static void test_case() {
		int n = scanner.nextInt();
		ArrayList<Integer> arrayList = new ArrayList<Integer>();
		for (int i = 0; i < n; ++i)
			arrayList.add(scanner.nextInt());
		int k = scanner.nextInt();
		Collections.sort(arrayList);
		int ans[] = new int[n];
		ans[0] = 0;
		for (int i = 1; i < n; ++i) {
			if (arrayList.get(i) - arrayList.get(i - 1) < k) {
				if (i == 1)
					ans[i] = arrayList.get(i) + arrayList.get(i - 1);
				else 
					ans[i] = ans[i - 2] + arrayList.get(i) + arrayList.get(i - 1);
			}
			else
				ans[i] = ans[i - 1];
		}
		System.out.println(ans[n - 1]);
	}
}