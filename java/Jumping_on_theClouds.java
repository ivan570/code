package warm_up;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Jumping_on_theClouds {
	public static void main(String[] args) {
		List<Integer> list = new ArrayList<Integer>();
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for(int i = 0 ; i < n ; i++) {
			list.add(in.nextInt());
		}
		
		if(list.get(0) == 1 || list.get(n-1) == 1) {
			System.out.println(-1);
			System.exit(0);
		}
		int c = 0;
		
		for(int i = 0 ; i < n ; i++) {
			if(i < n-2 && list.get(i+2) == 0) {
				c++;
				i++;
				continue;
			}
			else if(i < n-1 && list.get(i+1) == 0) {
				c++;
			}
		}
		
		System.out.println(c);
	}
}
