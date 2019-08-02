__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public static String toGoatLatin(String s) {
		if (s == null) {
			return "";
		}

		StringBuilder res = new StringBuilder();
		int fp = 0;
		int wordCounter = 1;

		while (fp < s.length()) {
			char curr = s.charAt(fp);

			if (curr == ' ') {
				res.append(curr);
				fp++;
			} else {
				StringBuilder goatLatinWord = new StringBuilder();
				String word = getWord(s, fp);
				fp += word.length();

				if (beginsWithVowel(word)) {
					goatLatinWord.append(word);
				} else {
					goatLatinWord.append(word.substring(1));
					goatLatinWord.append(word.charAt(0));
				}

				goatLatinWord.append("ma");
				for (int i = 0; i < wordCounter; i++) {
					goatLatinWord.append('a');
				}

				wordCounter++;
				res.append(goatLatinWord);
			}
		}

		return res.toString();
	}

	private static boolean beginsWithVowel(String word) {
        if (word == null || word.isEmpty()) {
            return false;
        }
        
        char first = Character.toLowerCase(word.charAt(0));
        
        return first == 'a' || first == 'e' || 
            first == 'i' || first == 'o' || first == 'u';
    }

    private static String getWord(String s, int fp) {
    	StringBuilder word = new StringBuilder();

    	while (fp < s.length() && s.charAt(fp) != ' ') {
    		word.append(s.charAt(fp++));
    	}

    	return word.toString();
    }
}
__________________________________________________________________________________________________
sample 34808 kb submission
class Solution {
    public String toGoatLatin(String S) {
        String[] tokens = S.split(" ");
        Set<Character> v = new HashSet<Character>("aeiou".chars().mapToObj(e->(char)e).collect(Collectors.toList()));
        List<String> t = new ArrayList<>();
        for (int i = 0; i < tokens.length; i++) {
            if (tokens[i].length() == 0) continue;
            String u = null;
            if (v.contains(Character.toLowerCase(tokens[i].charAt(0)))) {
                u = tokens[i] + "ma";
                
            } else {
                u = tokens[i].substring(1)+tokens[i].charAt(0)+"ma";
            }
            for (int j = 0; j <= i; j++) {
                u+='a';
            }
            t.add(u);
        }
        return String.join(" ", t);
    }
}
__________________________________________________________________________________________________
