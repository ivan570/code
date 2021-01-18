
public class Travel {
	public static void inorder(Node root) {
		if (root == null)
			return;
		inorder(root.left);

		double left = -1;
		double right = -1;

		if (root.left != null)
			left = root.left.data;
		if (root.right != null)
			right = root.right.data;

		System.out.println("data " + root.data + " height " + root.height + " left " + left + " right " + right);
		inorder(root.right);
	}
}
