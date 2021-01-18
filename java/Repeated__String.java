package warm_up;

import java.util.Scanner;

public class Repeated__String {
	public static long countChar(String s , char ch) {
		long r = 0;
		for(int i = 0 ; i < s.length() ; i++ )
			if(s.charAt(i) == ch) 
				r++;
		return r;
	}

	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner in = new Scanner(System.in);
		String s = in.nextLine();
		long n = in.nextLong();
		if(s.equals("a"))
			System.out.println(n);
		
		else {
			long t = n;
			n = n % s.length();
			t = t/s.length();
			System.out.println("t "+t);
			long l = countChar(s,'a') * t;
			System.out.println("l "+l);
			System.out.println("n "+n);
			long temp = countChar(s.substring(0,(int)(n)),'a');
			l += temp;
			System.out.println(l);
		}
	}
}
