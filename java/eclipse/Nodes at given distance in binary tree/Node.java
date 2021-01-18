import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Node {
	int data;
	Node left, right;

	public Node(int d) {
		data = d;
		left = right = null;
	}
}

class GFG {
	static Node buildTree(String str) {
		// Corner Case
		if (str.length() == 0 || str.equals("N"))
			return null;
		String[] s = str.split(" ");

		Node root = new Node(Integer.parseInt(s[0]));
		Queue<Node> q = new LinkedList<Node>();
		q.add(root);

		// Starting from the second element
		int i = 1;
		while (!q.isEmpty() && i < s.length) {
			// Get and remove the front of the queue
			Node currNode = q.remove();

			// Get the current node's value from the string
			String currVal = s[i];

			// If the left child is not null
			if (!currVal.equals("N")) {

				// Create the left child for the current node
				currNode.left = new Node(Integer.parseInt(currVal));

				// Push it to the queue
				q.add(currNode.left);
			}

			// For the right child
			i++;
			if (i >= s.length)
				break;
			currVal = s[i];

			// If the right child is not null
			if (!currVal.equals("N")) {

				// Create the right child for the current node
				currNode.right = new Node(Integer.parseInt(currVal));

				// Push it to the queue
				q.add(currNode.right);
			}

			i++;
		}

		return root;
	}

	public static void main(String args[]) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim());
		while (t > 0) {
			String s = br.readLine().trim();
			Node root = buildTree(s);
			int target = Integer.parseInt(br.readLine().trim());
			int k = Integer.parseInt(br.readLine().trim());
			ArrayList<Integer> res = new ArrayList<Integer>();
			res = Solution.KDistanceNodes(root, target, k);
			for (int i = 0; i < res.size(); i++)
				System.out.print(res.get(i) + " ");
			System.out.println();
			t--;
		}
	}
}

class Pair {
	Node first;
	int second;

	Pair(Node first, int second) {
		this.second = second;
		this.first = first;
	}
}

class Solution {

	public static void print(Pair pair, ArrayList<Integer> arrayList, int level) {
		if (level == 0) {
			arrayList.add(pair.first.data);
			return;
		}
		
		if (pair.second == 0) {
			System.out.println(pair.first.data + " level " + level);
			addingAll(pair.first, arrayList, level, 1);
		} else if (pair.second == 1) {
			System.out.println(pair.first.data + " level " + level);
			addingAll(pair.first.left, arrayList, level, 1);
		} else if (pair.second == 2) {
			System.out.println(pair.first.data + " level " + level);
			addingAll(pair.first.right, arrayList, level, 1);
		}
	}

	public static void addingAll(Node root, ArrayList<Integer> arrayList, int level, int cur) {
		if (root == null)
			return;
		if (level == cur || level == 0) {
			System.out.println("levellllll ");
			arrayList.add(root.data);
			return;
		}
		addingAll(root.left, arrayList, level, cur + 1);
		addingAll(root.right, arrayList, level, cur + 1);
	}

	public static ArrayList<Integer> KDistanceNodes(Node root, int target, int k) {
		// TODO Auto-generated method stub

		ArrayList<Pair> arrayList = new ArrayList<>();
		preorder(root, arrayList, target);

		ArrayList<Integer> ans = new ArrayList<Integer>();
		int level = 0;
		for (Pair temp : arrayList) {
			print(temp, ans, k - level);
			level += 1;
		}
		System.out.println("ending");
		return ans;
	}

	public static Node preorder(Node root, ArrayList<Pair> arrayList, int target) {
		// TODO Auto-generated method stub
		if (root == null)
			return null;
		if (root.data == target) {
			arrayList.add(new Pair(root, 0));
			return root;
		}
		Node left = preorder(root.left, arrayList, target);
		if (left != null) {
			arrayList.add(new Pair(root, 2));
			return left;
		}
		Node right = preorder(root.right, arrayList, target);
		if (right != null)
			arrayList.add(new Pair(root, 1));
		return right;
	}
};