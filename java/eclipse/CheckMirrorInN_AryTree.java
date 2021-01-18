import java.util.HashMap;
import java.util.ArrayList;
import java.util.Map;
import java.util.Scanner;

public class CheckMirrorInN_AryTree {
    public static Scanner scanner = new Scanner(System.in);

    public static HashMap<Integer, ArrayList<Integer>> tackInput(int edge) {
        HashMap<Integer, ArrayList<Integer>> original = new HashMap<>();
        for (int i = 0; i < edge; ++i) {
            int first = scanner.nextInt();
            int second = scanner.nextInt();
            if (original.get(first) == null) {
                ArrayList<Integer> list = new ArrayList<>();
                list.add(second);
                original.put(first, list);
            } else
                original.get(first).add(second);
        }
        return original;
    }

    public static void test_case() {
        int vertex = scanner.nextInt();
        int edge = scanner.nextInt();
        HashMap<Integer, ArrayList<Integer>> original = tackInput(edge);
        HashMap<Integer, ArrayList<Integer>> mirror = tackInput(edge);

        boolean ans = true;
        for (Map.Entry<Integer, ArrayList<Integer>> temp : original.entrySet()) {
            int originalValue = temp.getKey();
            ArrayList<Integer> originalArrayList = temp.getValue();
            ArrayList<Integer> mirrorArrayList = mirror.get(originalValue);
            if (originalArrayList.size() == 1 && mirrorArrayList.size() == 1)
                continue;

            if (originalArrayList.size() != mirrorArrayList.size()) {
                ans = false;
                break;
            }
            int size = originalArrayList.size();
            for (int i = 0; i < size; ++i) {
                if (!originalArrayList.get(i).equals(mirrorArrayList.get(size - i - 1))) {
                    ans = false;
                    break;
                }
            }
            if (!ans)
                break;

        }

        if (ans)
            System.out.println(1);
        else
            System.out.println(0);
    }

    public static void main(String[] args) {
        int n = scanner.nextInt();
        for (int i = 0; i < n; ++i)
            test_case();
    }
}
