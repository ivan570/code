import java.util.*;
import java.lang.*;
import java.math.BigInteger;
public class SumXor {

    static BigInteger xor(BigInteger x, BigInteger y) 
    { 
    	BigInteger tX = x.not();
    	BigInteger tY = y.not();
        return (x.or(y)).and(tX.add(tY)); 
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String n = scan.next();
        BigInteger value = new BigInteger(n);
        long c = 0;
        BigInteger i = new BigInteger("1");
        for(i = 0 ; i.compareTo(n) <= 0 ; i.add(1))
            if( (i.add(n)).compareTo(xor(i,x)) == 0 )
                c++;
        
        System.out.print(c);
    }
}