package TEMP;

import java.io.*;
import java.util.*;

public class pair {
	int first;
	boolean second;

	pair(int first, boolean second) {
		this.first = first;
		this.second = second;
	}
}

class Node {
	int data, height;
	Node left, right;

	Node(int x) {
		data = x;
		left = right = null;
		height = 1;
	}
}

class GfG {

	public static int setHeights(Node n) {
		if (n == null)
			return 0;
		n.height = 1 + Math.max(setHeights(n.left), setHeights(n.right));
		return n.height;
	}

	static Node buildTree(String str) {

		if (str.length() == 0 || str.charAt(0) == 'N') {
			return null;
		}

		String ip[] = str.split(" ");
		// Create the root of the tree
		Node root = new Node(Integer.parseInt(ip[0]));
		// Push the root to the queue

		Queue<Node> queue = new LinkedList<>();

		queue.add(root);
		// Starting from the second element

		int i = 1;
		while (queue.size() > 0 && i < ip.length) {

			// Get and remove the front of the queue
			Node currNode = queue.peek();
			queue.remove();

			// Get the current node's value from the string
			String currVal = ip[i];

			// If the left child is not null
			if (!currVal.equals("N")) {

				// Create the left child for the current node
				currNode.left = new Node(Integer.parseInt(currVal));
				// Push it to the queue
				queue.add(currNode.left);
			}

			// For the right child
			i++;
			if (i >= ip.length)
				break;

			currVal = ip[i];

			// If the right child is not null
			if (!currVal.equals("N")) {

				// Create the right child for the current node
				currNode.right = new Node(Integer.parseInt(currVal));

				// Push it to the queue
				queue.add(currNode.right);
			}
			i++;
		}

		setHeights(root);
		return root;
	}

	public static boolean isBST(Node n, int lower, int upper) {
		if (n == null)
			return true;
		if (n.data <= lower || n.data >= upper)
			return false;
		return isBST(n.left, lower, n.data) && isBST(n.right, n.data, upper);
	}

	public static pair isBalanced(Node n) {
		if (n == null) {
			return new pair(0, true);
		}

		pair l = isBalanced(n.left);
		pair r = isBalanced(n.right);

		if (Math.abs(l.first - r.first) > 1)
			return new pair(0, false);

		return new pair(1 + Math.max(l.first, r.first), l.second && r.second);
	}

	public static boolean isBalancedBST(Node root) {
		if (isBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE) == false)
			System.out.print("BST voilated, inorder traversal : ");

		else if (isBalanced(root).second == false)
			System.out.print("Unbalanced BST, inorder traversal : ");

		else
			return true;
		return false;
	}

	public static void printInorder(Node n) {
		if (n == null)
			return;
		printInorder(n.left);
		System.out.print(n.data + " ");
		printInorder(n.right);
	}

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());

		while (t-- > 0) {
			String s = br.readLine();
			Node root = buildTree(s);

			int n = Integer.parseInt(br.readLine());
			int ip[] = new int[n];

			String[] in = br.readLine().trim().split("\\s+");

			for (int i = 0; i < n; i++)
				ip[i] = Integer.parseInt(in[i]);

			
			for (int i = 0; i < n; i++) {
				root = Sol.deleteNode(root, ip[i]);

				if (isBalancedBST(root) == false)
					break;
			}

			if (root == null)
				System.out.print("null");
			else
				printInorder(root);
			System.out.println();

		}

	}
}

class Insertion {

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
		root.height = Sol.getHeight(root);
		return right;
	}

	public static Node makeLL(Node root) {
		Node left = root.left;
		Node leftRight = left.right;

		left.right = root;
		root.left = leftRight;

		root.height = Sol.getHeight(root);
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

}

class Sol {
	public static Node delete(Node root, int data) {
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
				int d = temp.data;
				temp.data = root.data;
				root.data = d;
				root.right = delete(root.right, temp.data);
			}
		}

		if (bFactor(root) == 2 && (bFactor(root.left) == 0 || (bFactor(root.left) == 1)))
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

	public static int bFactor(Node root) {
		if (root == null)
			return 0;

		return getHeight(root.left) - getHeight(root.right);
	}

	public static int getHeight(Node root) {

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

	public static Node deleteNode(Node root, int data) {
		return delete(root, data);
	}
}
