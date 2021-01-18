import java.util.ArrayList;
import java.util.Collections;

public class text {
	public static void main(String[] args) {
		int x = 10, y, z;
		z = y = x;
		y -= x--;
		z-=--x;
		x-=--x - x--;
		System.out.println(x + " " + y + " " + z);
	}
}