
public class Get_theMiddleCharacter {
	public static String getMiddle(String word) {
		String ch = "";
		if(word.length()%2 == 0) {
			ch += word.charAt(word.length()/2-1);
			ch += word.charAt(word.length()/2);
		}
		else {
			ch += word.charAt(word.length()/2);
		}
		return ch;
	}
	public static void main(String[] args) {
		System.out.println(getMiddle("middle"));
	}
}
