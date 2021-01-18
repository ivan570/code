public class FindOutlier {
	public static int isOdd(int [] arr) {
		int val = 0;
		for(int i = 0;i < arr.length;i++) {
			if(arr[i]%2 == 0)
				val++;
		}
		return val;
	}
	public static int find(int[] integers) {
		if(isOdd(integers) == 1) {
			for(int i = 0;i < integers.length;i++) {
				if(integers[i]%2 == 0)
					return integers[i];
			}
		}
		else {
			for(int i = 0;i < integers.length;i++) {
				if(integers[i]%2 != 0)
					return integers[i];
			}			
		}
		return 0;
	}
	public static void main(String[] args) {
		int arr[] = {160, 3, 1719, 19, 11, 13, -21};
		System.out.println(find(arr));
	}
}