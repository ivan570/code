package Populate_Inorder_Successor_for_all_nodes;

import java.util.*;
import java.util.Scanner;
import java.util.HashSet;
import java.lang.Math;

class Node {
    int data;
    Node left, right, next;

    Node(int d) {
        data = d;
        left = right = next = null;
    }
}

public class GFG2 {
    public static Node target;

    GFG2() {
        target = null;
    }

    public static void inorder(Node root) {
        if (root == null)
            return;
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    public static void print(Node root) {
        if (root == null)
            return;
        while (root.left != null)
            root = root.left;
        while (root != null) {
            System.out.print(root.data + "->");
            if (root.next != null)
                System.out.print(root.next.data + " ");
            else
                System.out.print("-1 ");
            root = root.next;
        }
    }

    /* Drier program to test above functions */
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            GFG2 llist = new GFG2();
            Node root = null, parent = null;
            HashMap<Integer, Node> m = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int a = sc.nextInt();
                int b = sc.nextInt();
                char c = sc.next().charAt(0);
                if (root == null) {
                    root = new Node(a);
                    switch (c) {
                        case 'L':
                            root.left = new Node(b);
                            break;
                        case 'R':
                            root.right = new Node(b);
                            break;
                    }
                } else {
                    insert(root, a, b, c);
                }
            }
            GFG obj = new GFG();
            obj.populateNext(root);
            //inorder(root);
            print(root);
            System.out.println();
        }
    }

    public static void insert(Node root, int a, int b, char c) {
        if (root == null)
            return;
        if (root.data == a) {
            switch (c) {
                case 'L':
                    root.left = new Node(b);
                    break;
                case 'R':
                    root.right = new Node(b);
                    break;
            }
        } else {
            insert(root.left, a, b, c);
            insert(root.right, a, b, c);
        }
    }
}
// } Driver Code Ends


//User function Template for Java


/*class Node
    {
        int data;
        Node left,right,next;
        Node(int d) {data = d; left =right= next= null; }
    }*/

class GFG {
    public static void inorder(Node root, ArrayList<Node> list) {
        if (root == null)
            return;
        inorder(root.left, list);
        list.add(root);
        inorder(root.right, list);
    }

    public static void populateNext(Node root) {
        ArrayList<Node> list = new ArrayList<>();
        inorder(root, list);
        for (int i = 0; i < list.size() - 1; ++i) {
            Node first = list.get(i);
            Node second = list.get(i + 1);
            first.next = second;
            // System.out.print(first.data + "->" + second.data + " ");
        }
        // System.out.print(list.get(list.size() - 1).data + "->-1");
    }
}