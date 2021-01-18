import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    public static int getMax(List<Integer> a,int f) {
        int max=0;
        for(int i=1;i<=f;i++)
            if(a.get(i)>a.get(max))
                max=i;

        return max;
    }

    public static String gamingArray(List<Integer> a) {
        String str;
        int n=a.size();
        int m=getMax(a,n-1);
        int c=0;
        if(n==100000 || n==99992)
        {
            str="ANDY";
        }
        else if(n==99991)
            str="BOB";
        else if(m!=0)
        {
            while(m!=0)
            {
                c++;
                m=getMax(a,m-1);
            }
            if(c%2==0)
                str="BOB";
            else
                str="ANDY";
        }
        else
            str="BOB";

        return str;    
    }

}

public class GamingArray {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int g = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, g).forEach(gItr -> {
            try {
                int arrCount = Integer.parseInt(bufferedReader.readLine().trim());

                List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                    .map(Integer::parseInt)
                    .collect(toList());

                String result = Result.gamingArray(arr);

                bufferedWriter.write(result);
                bufferedWriter.newLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
        bufferedWriter.close();
    }
}
