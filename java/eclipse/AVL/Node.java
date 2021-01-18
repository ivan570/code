
public class Node {
	double data;
	int height;
	Node left, right;
	
	Node (double data) {
		this.data = data;
		left = right = null;
		height = 1;
	}
}
