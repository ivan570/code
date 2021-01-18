
public class Find_the_missing_letter {
	@SuppressWarnings("null")
	public static char findMissingLetter(char[] array) {
		for(int i = 0;i < array.length;i++) {
			if(array[i+1] == array[i] + 1) {
				continue;
			}
			else {
				return (char)(array[i] + 1);
			}
		}
		return (Character) null;
	}
	public static void main(String[] args) {
		char arr [] = {'a','b','c','d','f'};
		System.out.println(findMissingLetter(arr));
	}
}
