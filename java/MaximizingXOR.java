import java.util.*;

public class MaximizingXOR {
	static int xor(int x , int y)	{
	int i = ( x | y ) & ( ~x | ~y);
	return i ;
}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int l = scan.nextInt();
		int r = scan.nextInt();
		int max = 0;
		for(int i = l ; i <= r ; i++ ) {
			for(int j = l ; j<= r ; j++) {
				int value = xor(i,j);
				if( value > max )
				{
					max = value;
				}
			}
		}
		System.out.println(max);
	}
}