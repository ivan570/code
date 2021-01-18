import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Forming_a_MagicSquare {

    static int formingMagicSquare(int[][] s) {
    int[] m = {4,9,2,7,6,1,8,3};

    int[] s1 = new int[8];
    s1[0] = s[0][0];
    s1[1] = s[0][1];
    s1[2] = s[0][2];
    s1[3] = s[1][2];
    s1[4] = s[2][2];
    s1[5] = s[2][1];
    s1[6] = s[2][0];
    s1[7] = s[1][0];

    int min = 45;  // worst case when all zeros
    for (int i=0; i<8; i++){    // select one matrix
        int res = 0;

        if (i < 4){
            int j = Math.floorMod(i*2, 8);
            for (int t = 0; t<8; t++){  // foreach element in the matrix
                res += Math.abs(s1[t] - m[Math.floorMod(j+t,8)]);
            }
        } else {
            // change orientation
            int j = Math.floorMod(-i*2, 8);
            for (int t = 0; t<8; t++){  // foreach element in the matrix
                res += Math.abs(s1[t] - m[Math.floorMod(j-t,8)]);
            }
        }

        // Calculate middle cost (5 is always present in center m(1,1) in all magic squares 3x3)
        res += Math.abs(s[1][1] - 5);

        if (res < min){
            min = res;
        }
    }

    return min;
}

    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in); 
        int[][] s = new int[3][3];

        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                s[i][j]=scan.nextInt();

        int result = formingMagicSquare(s);

        System.out.print(result);
    }
}
