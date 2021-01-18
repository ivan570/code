import java.util.*;
public class XorSequence {
    static int xor(int x , int y)    {
        int i = ( x | y ) & ( ~x | ~y);
        return i ;
    }
    static void setValue(int arr[])
    {
        arr[0] = 0;
        for(int i = 1 ; i < arr.length ; i++ )
            arr[i] = xor(arr[i-1],i);
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int q = scan.nextInt();
        int l[] = new int[q];
        int r[] = new int[q];
        int arr[] = new int[89000000];

        setValue(arr);

        for(int i = 0 ; i < q ; i++) {
            l[i] = scan.nextInt();
            r[i] = scan.nextInt();
        }

        for(int i = 0 ; i < q ; i++) {
            int temp = 0;
            for(int x = l[i] ; x <= r[i] ; x++){
                temp = xor(temp , arr[x]);
            }
            System.out.println(temp);
        }
    }
}
