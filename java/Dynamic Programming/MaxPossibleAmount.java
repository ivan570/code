public class MaxPossibleAmount {
	public static Scanner sc = new Scanner(System.in);
	public static void main(String str[]) {
		int t = sc.nextInt();
		while(t-->0)
		{
			int n = sc.nextInt();
			int Arr[] = new int[n];
			for(int i = 0;i<n;i++)
				Arr[i] = sc.nextInt();
			System.out.println(maxAmount(Arr,n));
		}
	}
	static int maxAmount(int arr[] , int n)
	{
		int dyna[][] = new int[arr.length][arr.length];
		for (int i = arr.length - 1; i >= 0; --i) {
			for (int j = i; j < arr.length; ++j) {
				if (i == j)
					dyna[i][j] = 0;
				if (i > j)
					continue;
				int x = 0, y = 0;
				if (i + 2 <= j) {
					x = dyna[i + 2][j];
					y = dyna[i + 1][j - 1];
				}
				dyna[i][j] = Math.min(x, y) + arr[i];
				if (j - 2 >= 0)
					x = dyna[i][j - 2];
				else
					x = 0;
				dyna[i][j] = Math.max(dyna[i][j], Math.min(x, y) + arr[j]);
				max = Math.max(dyna[i][j], max);
			}
		}
		return dyna[0][arr.length - 1];
	}
}
