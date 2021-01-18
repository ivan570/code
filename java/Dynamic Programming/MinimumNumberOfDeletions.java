// MinimumNumberOfDeletions
import java.util.Scanner;

public class MinimumNumberOfDeletions {
	static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		int test = scanner.nextInt();
		scanner.nextLine();
		while (test-- > 0) {
			int i = scanner.nextInt();
			scanner.nextLine();
			StringBuilder str = new StringBuilder(scanner.next());
			System.out.println(str.length() - lcs(str.length(), str.length(), str.toString(), str.reverse().toString()));
		}
	}

	static int lcs(int p, int q, String first, String second) {
		int arr[][] = new int[first.length() + 1][second.length() + 1];

		for (int i = 0; i <= first.length(); ++i) {
			for (int j = 0; j <= second.length(); ++j) {
				if (i == 0 || j == 0)
					arr[i][j] = 0;
				else if (first.charAt(i - 1) == second.charAt(j - 1))
					arr[i][j] = arr[i - 1][j - 1] + 1;
				else
					arr[i][j] = Math.max(arr[i][j - 1], arr[i - 1][j]);
			}
		}

		return arr[first.length()][second.length()];
	}
}
