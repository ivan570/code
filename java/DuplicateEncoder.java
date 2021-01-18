public class DuplicateEncoder {
	public static int isDuplicate(String s,char a) {
		int bool = 0;
		for(int i = 0;i < s.length();i++)
		{
			if(s.charAt(i) == a) {
				bool++;
			}
			if(bool > 1) {
				return -1;
			}
		}
		return 0;
	}
	public static String encode(String word) {
		String ans = "";
		word = word.toLowerCase();
		for(int i = 0;i < word.length();i++) {
			if(isDuplicate(word,word.charAt(i)) == 0){
				ans += '(';
			}
			else {
				ans += ')';
			}
		}
		return ans;
	}
	public static void main(String[] args) {
		System.out.println(encode("Success"));
	}
}
