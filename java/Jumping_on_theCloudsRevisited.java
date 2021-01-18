import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Jumping_on_theCloudsRevisited {	
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = in.nextInt();
		List<Integer> list = new ArrayList<Integer>();
		for(int i = 0;i < n;i++) {
			int kk = in.nextInt();
			if( kk == 1 )
				kk = 2;
			list.add(kk);
		}
			
		int i = k % n;
		int val = 100 - list.get(i) - 1;
		while(i != 0)
		{
			i = ( i + k) % n;
			val = val - list.get(i) - 1;
		}
		
		System.out.println(val);
		
	}
}
