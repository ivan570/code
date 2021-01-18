import java.util.Arrays;
import java.util.Comparator;

public class Sorting {

	public static void main(String[] args) {
		String[] str = { "023", "123", "045", "56", "890" };
		for (String str_e : str)
			System.out.print(str_e + " ");
		Arrays.sort(str, new Comparator<String>() {

			@Override
			public int compare(String one, String two) {
				int one_length = getLength(one), two_length = getLength(two);
				if (one_length > two_length)
					return 1;
				else if (one_length < two_length)
					return -1;
				else
					return one.compareTo(two);

			}

			public int getLength(String str) {
				int ans = 0;
				boolean nonZeroComes = false;
				for (char i : str.toCharArray()) {
					if (nonZeroComes)
						ans++;
					else if (i == '0')
						continue;
					else {
						nonZeroComes = true;
						ans++;
					}
				}
				return ans;
			}
		});

		System.out.println();
		for (String str_e : str)
			System.out.print(str_e + " ");
	}
}
