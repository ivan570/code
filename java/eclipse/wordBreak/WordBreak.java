package wordBreak;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class WordBreak {

    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        for (int i = 0; i < n; ++i)
            cases();
    }

    static void cases() {
        int t = scanner.nextInt();
        scanner.nextLine();
        ArrayList<String> arrayList = new ArrayList<>();
        for (int i = 0; i < t; ++i)
            arrayList.add(scanner.next());
        String str = scanner.next();
        System.out.println(wordBreak(str, arrayList));
        map.clear();
    }

    static HashMap<String, Integer> map = new HashMap<>();

    private static int wordBreak(String str, ArrayList<String> arrayList) {
        if (arrayList.contains(str))
            return 1;
        else if (str.length() == 0)
            return 0;
        else if (str.length() == 1)
            return 0;
        if (map.containsKey(str))
            return map.get(str);
        for (int i = 1; i < str.length(); ++i) {
            if ((wordBreak(str.substring(0, i), arrayList) & wordBreak(str.substring(i), arrayList)) == 1) {
                map.put(str, 1);
                return 1;
            }
        }
        map.put(str, 0);
        return 0;
    }
}
