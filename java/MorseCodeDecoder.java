public class MorseCodeDecoder {
	public static String[] split_to_latter(String st) {
		return st.split(" ");
	}
	public static String[] split_to_word(String st) {
		return st.split("   ");
	}
    public static String decode(String morseCode) {
    	String arr[] = split_to_word(morseCode);
		String ans = "";
		if(arr.length == 1) {
			String temp="";
			String srr [] = split_to_latter(arr[0]);
			for(@SuppressWarnings("unused") String k : srr) {
//				Tempt += MorseCode.get(k);
			}
			return temp;
		}
		
		for(int i = 0; i < arr.length ; i++) {
			String temp = "";
			String srr [] = split_to_latter(arr[i]);
			for(@SuppressWarnings("unused") String k : srr) {
//				Tempt += MorseCode.get(k);
			}			
      if(i != arr.length - 1  &&  !temp.equals("") && !temp.equals(null))
			  ans += temp+" ";
      else
        if(!temp.equals("") && !temp.equals(null))
          ans += temp;
		}
		return ans;
    }
}