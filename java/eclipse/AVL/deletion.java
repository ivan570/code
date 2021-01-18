
public class deletion {
	public static Node delete(Node root, double data) {
		if (root == null)
			return null;

		if (root.data > data)
			root.left = delete(root.left, data);

		else if (root.data < data)
			root.right = delete(root.right, data);

		else if (root.data == data) {
			if (root.left == null && root.right == null)
				return null;
			else if (root.left == null && root.right != null)
				return root.right;
			else if (root.left != null && root.right == null)
				return root.left;
			else if (root.left != null && root.right != null) {
				Node temp = getSuccessor(root.right);
				double d = temp.data;
				temp.data = root.data;
				root.data = d;
				root.right = delete(root.right, temp.data);
			}
		}
		
		if (bFactor(root) == 2 && (bFactor(root.left) == 0 || (bFactor(root.right) == 1)))
			root = Insertion.makeLL(root);
		
		else if (bFactor(root) == 2 && bFactor(root.left) == -1)
			root = Insertion.makeLR(root);
		
		else if (bFactor(root) == -2 && (bFactor(root.right) == 0 || bFactor(root.right) == -1))
			root = Insertion.makeRR(root);
		
		else if (bFactor(root) == -2 && bFactor(root.right) == 1)
			root = Insertion.makeRL(root);
		
		root.height = getHeight(root);
		
		return root;
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

	private static Node getSuccessor(Node root) {
		if (root == null)
			return null;
		while (root != null && root.left != null)
			root = root.left;
		return root;
	}
}
