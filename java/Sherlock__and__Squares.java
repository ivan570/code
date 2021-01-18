import java.util.Scanner;

public class Sherlock__and__Squares {
    public static void main(String[] args) {
        @SuppressWarnings("resource")
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int qItr = 0; qItr < q; qItr++) {
            int start = in.nextInt();
            int end = in.nextInt();
            int count = 0;
            count = (int)Math.floor(Math.sqrt(end))-(int)Math.floor(Math.sqrt(start-1));
            System.out.println((int)count);
            
        }
    }
}
