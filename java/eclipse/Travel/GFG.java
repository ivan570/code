import java.util.Scanner;

class GFG {

	public static Scanner sc = new Scanner(System.in);

	public static void main(String args[]) {

		int t = sc.nextInt();
		while (t > 0) {
			int n = sc.nextInt();
			int[] preorder = new int[n];
			int[] inorder = new int[n];
			int[] postorder = new int[n];
			for (int i = 0; i < n; i++)
				preorder[i] = sc.nextInt();
			for (int i = 0; i < n; i++)
				inorder[i] = sc.nextInt();
			for (int i = 0; i < n; i++)
				postorder[i] = sc.nextInt();

			if (Solution.checktree(preorder, inorder, postorder, n))
				System.out.println("Yes");
			else
				System.out.println("No");
			t--;
		}
	}
}
// } Driver Code Ends

class Node {
	int data;
	Node left, right;

	Node(int data) {
		this.data = data;
		left = right = null;
	}
}

class Cur {
	int data;

	Cur(int data) {
		this.data = data;
	}
}

class Solution {
	static boolean checktree(int preorder[], int inorder[], int postorder[], int len) {
		len = preorder.length;
		if (len == 0)
			return true;
		return treeCheck(preorder, inorder, postorder, 0, len - 1, 0, len - 1, 0, len - 1);
	}

	public static boolean treeCheck(int[] pre, int[] in, int[] post, int preStart, int preEnd, int inStart, int inEnd,
			int postStart, int postEnd) {

		if (inStart > inEnd)
			return true;

		if (pre[preStart] != post[postEnd])
			return false;

		int index = -1;
		for (int i = inStart; i <= inEnd; ++i)
			if (in[i] == pre[preStart]) {
				index = i;
				break;
			}
		
		int leftInStart = inStart, leftInEnd = index - 1;
		int leftPreStart = preStart + 1, leftPreEnd = leftInEnd - leftInStart + leftPreStart;
		int leftPostStart = postStart, leftPostEnd = leftInEnd - leftInStart + leftPostStart;
		
		boolean left = treeCheck(pre, in, post, leftPreStart, leftPreEnd, leftInStart, leftInEnd, leftPostStart, leftPostEnd);
		
		if (!left)
			return false;
		
		int rightInStart = index + 1, rightInEnd = inEnd;
		int rightPreStart = leftPreEnd + 1, rightPreEnd = preEnd;
		int rightPostStart = leftPostEnd + 1, rightPostEnd = postEnd - 1;
		
		boolean right = treeCheck(pre, in, post, rightPreStart, rightPreEnd, rightInStart, rightInEnd, rightPostStart, rightPostEnd);
		return left && right;
	}
}
