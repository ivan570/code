import java.util.Scanner;

public class MainMethod {

	private static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		Node root = null;
		int n = scanner.nextInt();
		for (int i = 0; i < n; ++i) {
			double temp = scanner.nextDouble();
			root = Insertion.add(root, temp);
		}
		Travel.inorder(root);
		
		System.out.println("numer for deletion");
		n = scanner.nextInt();
		for (int i = 0; i < n; ++i) {
			double temp = scanner.nextDouble();
			root = deletion.delete(root, temp);
		}
		Travel.inorder(root);
	}
}
