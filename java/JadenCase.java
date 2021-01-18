import java.util.Scanner;

public class JadenCase {

	public static String toJadenCase(String phrase) {
		if(phrase == null || phrase == "") {
			return null;
		}
		else
		{
			if(phrase.charAt(0) >= 97 && phrase.charAt(0) <= 122)
			{
				phrase = (char)(phrase.charAt(0) - 32) + phrase.substring(1);
	//			System.out.println("in if "+phrase);
			}
			for(int i = 1;i<phrase.length();i++)
			{
				if(phrase.charAt(i-1) == ' ' && phrase.charAt(i) >= 97 && phrase.charAt(i) <= 122)
				{
					phrase = phrase.substring(0,i) + (char)(phrase.charAt(i) - 32) + phrase.substring(i+1);
				}
			}
		}
		return phrase;
	}
	@SuppressWarnings("resource")
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		@SuppressWarnings("unused")
		String s = toJadenCase(scan.nextLine());
		System.out.println(toJadenCase(""));
	}
}