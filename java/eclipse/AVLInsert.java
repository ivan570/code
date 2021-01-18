import java.util.Scanner;

class Tree {
    int data, height;
    Tree left, right;

    Tree(int data) {
        this.data = data;
        left = right = null;
        height = 1;
    }
}

public class AVLInsert {
    private static final Scanner scanner = new Scanner(System.in);

    public static Tree insert(Tree root, int data) {
        if (root == null)
            return new Tree(data);
        if (root.data > data)
            root.left = insert(root.left, data);
        if (root.data < data)
            root.right = insert(root.right, data);

        root.height = getHeight(root);

        if (bFactor(root) == 2 && bFactor(root.left) == 1)
            root = leftLeft(root);
        if (bFactor(root) == 2 && bFactor(root.left) == -1)
            root = leftRight(root);
        if (bFactor(root) == -2 && bFactor(root.right) == -1)
            root = rightRight(root);
        if (bFactor(root) == -2 && bFactor(root.left) == 1)
            root = rightLeft(root);
        return root;
    }

    private static Tree rightLeft(Tree root) {
        if (root == null)
            return null;
        Tree right = root.right;
        Tree rightLeft = root.right.left;

        rightLeft.height = right.height;
        right.height -= 1;
        root.height = right.height;

        rightLeft.right = right;
        rightLeft.left = root;
        root.right = rightLeft.left;
        right.left = rightLeft.right;
        return rightLeft;
    }

    private static Tree rightRight(Tree root) {
        if (root == null)
            return null;

        Tree right = root.right;
        Tree rightRight = right.right;

        root.height = right.height - 1;
        right.left = root;
        right.right = rightRight;
        root.right = right.left;
        return right;
    }

    private static Tree leftRight(Tree root) {
        if (root == null)
            return null;
        Tree left = root.left;
        Tree leftRight = root.left.right;

        leftRight.right = left;
        leftRight.left = root;

        leftRight.height = left.height;
        left.height -= 1;
        root.height = left.height;

        root.right = leftRight.left;
        left.left = leftRight.right;
        return leftRight;
    }

    private static Tree leftLeft(Tree root) {
        if (root == null)
            return null;
        Tree a = root;
        Tree b = a.left;
        Tree c = b.left;
        Tree br = b.right;

        a.left = br;
        a.height = c.height;
        b.left = c;
        b.right = a;
        return b;
    }

    private static int bFactor(Tree root) {
        if (root == null)
            return 0;
        return (getHeight(root.left) - getHeight(root.right));
    }

    private static int getHeight(Tree root) {
        if (root == null)
            return 0;
        int left = 0, right = 0;
        if (root.left != null)
            left = root.left.height;
        if (root.right != null)
            right = root.right.height;
        return Math.max(left, right) + 1;
    }

    public static void main(String[] args) {
        int n = scanner.nextInt();
        Tree root = null;
        for (int i = 0; i < n; ++i)
            root = insert(root, scanner.nextInt());

        inorder(root);
    }

    private static void inorder(Tree root) {
        if (root == null)
            return;
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }
}
