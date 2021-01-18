import java.util.Scanner;

public class Binary_Reversal {

  public static String BinaryReversal(String str) {
    String bin_str = Integer.toBinaryString(Integer.parseInt(str));
    int len = bin_str.length();
    int i;
    for(i = 1;;i++) {
    	if(Math.pow((double) 2,(double) i) >= len)
    		break;
    }
    int bin = (int) Math.pow(2, i);
    bin_str = String.format("%"+bin+"s", bin_str).replace(' ', '0');
    StringBuilder bul_str = new StringBuilder(bin_str);
    bul_str = bul_str.reverse();
    bin_str = bul_str.substring(0, bul_str.length());
    
    return ""+Integer.parseInt(bin_str, 2);
  }

  public static void main (String[] args) {  
    @SuppressWarnings("resource")
	Scanner s = new Scanner(System.in);
    System.out.print(BinaryReversal(s.nextLine())); 
  }

}