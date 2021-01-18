import java.util.Scanner;
import java.util.ArrayList;

public class BracketsinMatrixChainMultiplication {
    public static Scanner scanner = new Scanner(System.in);

    public static void main(String st[]) {
        int n = scanner.nextInt();
        for (int i = 0; i < n; ++i)
            cases();
    }

    static ArrayList<ArrayList<Integer>> dyna = new ArrayList<>(), bracket = new ArrayList<>();

    public static void cases() {
        int n = scanner.nextInt();
        ArrayList<Integer> arrayList = new ArrayList<>();
        for (int i = 0; i < n; ++i)
            arrayList.add(scanner.nextInt());

        dyna.clear();
        bracket.clear();
        dyna = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            dyna.add(new ArrayList<>());
            for (int ii = 0; ii < n; ++ii)
                dyna.get(i).add(-1);
        }
        bracket = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            bracket.add(new ArrayList<>());
            for (int ii = 0; ii < n; ++ii)
                bracket.get(i).add(-1);
        }
        A = 'A';
        getMatrix(arrayList, 1, n - 1);
        printParenthesis(1, n - 1);
    }

    private static char A = 'A';

    private static void printParenthesis(int i, int j) {
        if (i == j) {
            System.out.print(A++);
            return;
        }
        System.out.print('(');
        printParenthesis(i, bracket.get(i).get(j));
        printParenthesis(bracket.get(i).get(j) + 1, j);
        System.out.print(')');
    }

    private static int getMatrix(ArrayList<Integer> arrayList, int i, int j) {

        if (i > j)
            return 0;
        else if (i == j) {
            dyna.get(i).set(j, 0);
            return dyna.get(i).get(j);
        } else if (dyna.get(i).get(j) != -1)
            return dyna.get(i).get(j);

        int ans = Integer.MAX_VALUE;

        for (int k = i; k < j; ++k) {
            int temp = arrayList.get(i - 1) * arrayList.get(k) * arrayList.get(j) + getMatrix(arrayList, i, k)
                    + getMatrix(arrayList, k + 1, j);
            if (temp < ans) {
                bracket.get(i).set(j, k);
                ans = temp;
            }
        }
        dyna.get(i).set(j, ans);
        return ans;
    }
}