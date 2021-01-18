import java.util.*;
import java.io.*;
public class LonelyInterger {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int arr[] = new int[n];

        for(int i = 0 ; i < n ; i++)
            arr[i] = scan.nextInt();

        int list[] = new int[101];
        for(int i=0;i<101;i++)
            list[i]=0;

        for(int i = 0 ; i < n ; i++ )
        {
            list[arr[i]]++;
        }

        for(int i=0;i<101;i++)
        {
            if(list[i] == 1)
                System.out.println(i);
        }
    }
}