import java.util.*;
import java.io.*;
public class SequenceEquation {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int p[] = new int[n];
        for(int i = 0 ; i < n ; i++)
            p[i] = scan.nextInt();

        int j = 1;
        for(int k = 1 ; k <= n ; k++){
            for(int i = 1 ; i <= n ; i++)
            {
                if( p[p[i-1]-1] == j )
                {
                    System.out.println(i);
                    j++;
                }
            }
        }
    }
}