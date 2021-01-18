import java.io.*;

public class StringSubsequence  {
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(in.readLine().trim());
		while (tc-- > 0) {
			String S1 = in.readLine();
			String S2 = in.readLine();
			Recursive ob = new Recursive();
			System.out.println(ob.countWays(S1, S2));
		}
	}
}

class Recursive {
	int count(String first, String second, int fLast, int sLast) {
		if (fLast == -1 && sLast == -1)
			return 1;
		else if (sLast < 0)
		    return 1;
		else if (fLast < 0)
			return 0;
		if (first.charAt(fLast) == second.charAt(sLast))
			return count(first, second, fLast - 1, sLast - 1) + count(first, second, fLast - 1, sLast);
		else
			return count(first, second, fLast - 1, sLast);
	}

	int countWays(String s1, String s2) {
		return count(s1, s2, s1.length() - 1, s2.length() - 1);
	}
}

class Dynamic {
	int countWays(String first, String second) {
		int arr[][] = new int[first.length() + 1][second.length() + 1];
		for (int i = 0; i <= first.length(); ++i) {
			for (int j = 0; j <= second.length(); ++j) {
				if (j == 0)
					arr[i][j] = 1;
				else if (i == 0 && j != 0)
					arr[i][j] = 0;
				else if (first.charAt(i - 1) == second.charAt(j - 1))
					arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
				else 
					arr[i][j] = arr[i - 1][j];
			}
		}
 		return arr[first.length()][second.length()];
	}
}
