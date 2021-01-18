public class NumberFun {
  public static long findNextSquare(long sq) {
	  if( (long) Math.sqrt(sq) != Math.sqrt(sq) )
		  return -1;
      long temp = (long) Math.sqrt(sq) + 1;
      return (long) Math.pow(temp, 2); 
  }
  public static void main(String[] args) {
	 System.out.println(findNextSquare(111));
  }
}