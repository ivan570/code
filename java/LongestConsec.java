class LongestConsec {
    
    public static String longestConsec(String[] strarr, int k) {
        String str = "";
        for(int i = 0;i < strarr.length - k;i++) {
        	String temp = "";
        	for(int n = 0;n < k;n++) {
        		temp += strarr[i+n];
        	}
        	if( temp.length() > str.length() )
        		str = temp;
        }
    	return str;
    }
    public static void main(String[] args) {
		String str[] = {"wlwsasphmxx","owiaxujylentrklctozmymu","wpgozvxxiu"};
		System.out.println(longestConsec(str, 2));
	}
}