import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static Scanner scan = new Scanner(System.in);
	public static void main (String[] args) {
		int t = scan.nextInt();
		for (int i = 0; i < t; ++i)
			test_case();
	}

    
    public static void test_case() {
    	int n = scan.nextInt();
    	ArrayList<Integer> arrayList = new ArrayList<>();
    	for (int i = 0; i < n; ++i)
    		arrayList.add(scan.nextInt());
    	System.out.println(getMax(arrayList));
    }
    
    public static int getMax(ArrayList<Integer> arrayList) {
    	int inc[] = new int[arrayList.size()];
    	int dec[] = new int[arrayList.size()];
    
    	inc[0] = arrayList.get(0);
    	for (int i = 0; i < arrayList.size(); ++i) {
    		int ans = 0;
    		for (int j = i - 1; j >= 0; --j) {
    			if (arrayList.get(i) > arrayList.get(j))
    				ans = Math.max(inc[j], ans);
    		}
    		inc[i] = ans + arrayList.get(i);
    	}
    
    	for (int i = arrayList.size() - 1; i >= 0; --i) {
    		int ans = 0;
    		for (int j = i + 1; j < arrayList.size(); ++i) {
    			if (arrayList.get(i) > arrayList.get(j))
    				ans = Math.max(dec[j], ans);
    		}
    		dec[i] = ans + arrayList.get(i);
    	}
    
    }
}