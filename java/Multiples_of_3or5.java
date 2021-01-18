
public class Multiples_of_3or5 {
	public static int solution(int number) {
		int sum = 0;
		for(int i=3;i<number;i++) {
			if(i%3 == 0 || i%5 ==0)
			{
				sum +=i;
			}
		}
		return sum;
	}
	public static void main(String[] args) {
		System.out.println(solution(10));
	}
}
