__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
	private static boolean match(final String src, final int start, final int end, final String target) {
		final int len = target.length();
		if ((end-start) != (len-1))
			return false;
		for (int i = 0; i < len; ++i)
			if (src.charAt(start+i) != target.charAt(i))
				return false;
		return true;		
	}
	
    public String[] findOcurrences(String text, String first, String second) {
        final int len = text.length();
        int i = 0;
        char ch = 0;
        boolean match1 = false, match2 = false;
        final List<String> results = new ArrayList<>();
        while (i < len) {
            while ((i < len) && (ch = text.charAt(i)) == ' ')
            	++i;
            final int start = i;
            if (i >= len)
            	break;
            while ((i < len) && (ch = text.charAt(i)) != ' ')
            	++i;
            final int end = i-1;
            if (match2) {
            	results.add(text.substring(start, end+1));
            	match1 = match(text, start, end, first);
            	match2 = false;
            } else if (match1 && match(text, start, end, second)) {
            	match2 = true;
            } else {
        		match1 = match(text, start, end, first);
            }
        }
        final String[] r = new String[results.size()];
        for (i = 0; i < r.length; ++i)
        	r[i] = results.get(i);
        return r;
    }
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        ArrayList<String> answer = new ArrayList<>();
        String[] words = text.split(" ");
        
        for(int i = 2; i<words.length; i++){
            if(first.equals(words[i-2]) && second.equals(words[i-1])){
                answer.add(words[i]);
            }
        }
        return answer.toArray(new String[0]);
    }
}
__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
  	public String[] findOcurrences(String text, String first, String second) {

        String merge = first + " " + second;

		String result[] = text.split(merge);

		String finalList[] = new String[result.length - 1];
		int j = 0;
		for (int i = 1; i <= result.length - 1; i++) {

			if (result[i].equalsIgnoreCase(" ")) {
				finalList[j] = first;
				j++;
				continue;
			}

			finalList[j] = result[i].split(" ")[1];
			j++;

		}
		return finalList;
	}
}