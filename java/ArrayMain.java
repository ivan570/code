package boot_array;

public class ArrayMain {
	public static void method(int[] arr) {
		arr[2] = 03;
		arr=new int[] {1,2,3,4};
	}
	public static int[] reversed(int []arr) {
		int j=arr.length;
		int[] rev=new int[arr.length];
		for(int i:arr) {
			j--;
			rev[j]=i;
		}
		return rev;		
	}
	public static void main(String[] args) {
		int arr[] = new int[] { 22,33,44,55};
		method(arr);
		for (int i : arr)
			System.out.println(i);
		
		System.out.println("reversed arr");
		for (int i : reversed(arr))
			System.out.println(i);
	}
}
