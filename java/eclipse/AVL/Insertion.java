
public class Insertion {
	public static Node add(Node root, double data) {
		if (root == null)
			return new Node(data);

		if (root.data > data)
			root.left = add(root.left, data);

		else if (root.data < data)
			root.right = add(root.right, data);

		if (bFactor(root) == 2 && bFactor(root.left) == 1)
			root = makeLL(root);

		else if (bFactor(root) == 2 && bFactor(root.left) == -1)
			root = makeLR(root);

		else if (bFactor(root) == -2 && bFactor(root.right) == -1)
			root = makeRR(root);

		else if (bFactor(root) == -2 && bFactor(root.right) == 1)
			root = makeRL(root);

		root.height = getHeight(root);
		return root;
	}

	public static Node makeRL(Node root) {
		Node right = root.right;
	    Node rightLeft = right.left;
	    Node t_left = rightLeft.left;
	    Node t_right = rightLeft.right;

	    rightLeft.height += 1;
	    right.height -= 1;
	    root.height = right.height;

	    rightLeft.right = right;
	    rightLeft.left = root;
	    root.right = t_left;
	    right.left = t_right;
	    return rightLeft;
	}

	public static Node makeRR(Node root) {
		Node right = root.right;
	    Node rightRight = right.right;
	    Node rightLeft = right.left;

	    right.left = root;
	    right.right = rightRight;
	    root.right = rightLeft;
	    root.height = rightRight.height;
	    return right;
	}

	public static Node makeLL(Node root) {
		Node left = root.left;
		Node leftLeft = left.left;
		Node leftRight = left.right;

		root.height = leftLeft.height;
		left.right = root;
		left.left = leftLeft;
		root.left = leftRight;

		return left;
	}

	public static Node makeLR(Node root) {

		Node left = root.left;
		Node leftRight = left.right;
		Node t_left = leftRight.left;
		Node t_right = leftRight.right;
		left.height -= 1;
		root.height = left.height;
		leftRight.height += 1;

		leftRight.right = root;
		leftRight.left = left;
		left.right = t_left;
		root.left = t_right;
		return leftRight;
	}

	private static int bFactor(Node root) {
		if (root == null)
			return 0;

		return getHeight(root.left) - getHeight(root.right);
	}

	private static int getHeight(Node root) {

		if (root == null)
			return 0;
		int left = 0;
		int right = 0;
		if (root.left != null)
			left = root.left.height;
		if (root.right != null)
			right = root.right.height;
		return Math.max(left, right) + 1;
	}

}
