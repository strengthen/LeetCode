__________________________________________________________________________________________________
0ms
class Solution {
    
    private static final String[] KEYS = {"","","abc","def","ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    public List<String> letterCombinations(String digits) {
        List<String> ret = new LinkedList<>();
        if (digits == null || digits.length() < 1) {
            return ret;
        }
        combination("",digits,0,ret);
        return ret;
    }
    
    public void combination(String prefix, String digits, int offset, List<String> ret) {
        if (offset >= digits.length()) {
            ret.add(prefix);
            return;
        }
        
        String letters = KEYS[ digits.charAt(offset) - '0' ];
        for (int i=0; i<letters.length(); i++) {
            combination(prefix+letters.charAt(i), digits, offset+1, ret);
        }
    } 
}
__________________________________________________________________________________________________
1ms
class Solution {
    List<String> ans = new ArrayList<>();
    Map<String, List<String>> map = new HashMap<String, List<String>>() {{
        put("2", Arrays.asList("a", "b", "c"));
        put("3", Arrays.asList("d", "e", "f"));
        put("4", Arrays.asList("g", "h", "i"));
        put("5", Arrays.asList("j", "k", "l"));
        put("6", Arrays.asList("m", "n", "o"));
        put("7", Arrays.asList("p", "q", "r", "s"));
        put("8", Arrays.asList("t", "u", "v"));
        put("9", Arrays.asList("w", "x", "y", "z"));
    }};
    
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) {
            return ans;
        }

        letterCombinationHelper(digits, "", 0);
        return ans;
    }
    
    private void letterCombinationHelper(String digits, String s, int i) {
        if (i == digits.length()) {
            ans.add(s);
            return;
        }
        for (String t : map.get(digits.substring(i, i + 1))) {
            letterCombinationHelper(digits, s + t, i + 1);
        }
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    
    private final Map<Character, List<Character>> intCharMap;
    public Solution () {
        intCharMap = new HashMap<>(10);
        intCharMap.put('2', Arrays.asList(new Character[]{'a', 'b', 'c'}));
        intCharMap.put('3', Arrays.asList(new Character[]{'d', 'e', 'f'}));
        intCharMap.put('4', Arrays.asList(new Character[]{'g', 'h', 'i'}));
        intCharMap.put('5', Arrays.asList(new Character[]{'j', 'k', 'l'}));
        intCharMap.put('6', Arrays.asList(new Character[]{'m', 'n', 'o'}));
        intCharMap.put('7', Arrays.asList(new Character[]{'p', 'q', 'r', 's'}));
        intCharMap.put('8', Arrays.asList(new Character[]{'t', 'u', 'v'}));
        intCharMap.put('9', Arrays.asList(new Character[]{'w', 'x', 'y', 'z'}));
    }
    
    public List<String> letterCombinations(String digits) {
        Map<Integer, List<Character>> digitsLookedUp = new HashMap<>();
        for (int i=0; i<digits.length(); i++) {
            digitsLookedUp.put(i, intCharMap.get(digits.charAt(i)));
        }
        int lengthOfWord = digitsLookedUp.size();
        List<String> toReturn = new ArrayList<>();
        for (int i=0; i<lengthOfWord; i++) {
            List<Character> chars = digitsLookedUp.get(i);
            if (toReturn.size()==0) {
                for(char c : chars) {
                    toReturn.add(String.valueOf(c));                    
                }
            } else {
                List<String> toTempReturn = new ArrayList<>();
                for (String s : toReturn) {
                    for (Character c : chars) {
                        toTempReturn.add(s + c);
                    }
                }
                toReturn = toTempReturn;
            }
        }
        return toReturn;
    }
}
__________________________________________________________________________________________________
34516 kb 
class Solution {
    
    Map<Character, String> phone = new HashMap<Character, String>() {{
        put('2', "abc");
        put('3', "def");
        put('4', "ghi");
        put('5', "jkl");
        put('6', "mno");
        put('7', "pqrs");
        put('8', "tuv");
        put('9', "wxyz");
    }};

    List<String> output;
    
    public void backtrack(String combination, String next_digits){

        // if there is no more digits to check
        if(next_digits.length() == 0){
            // the combination is done
            output.add(combination);
        }
        // if there are still digits to check
        else {
            // iterate over all letters which map
            // the next available digit
            char digit = next_digits.charAt(0);
            String letters = phone.get(digit);
            for(int i = 0 ; i < letters.length() ; i++){
                char letter = phone.get(digit).charAt(i);
                // append the current letter to the combination
                // and proceed to the next digits
                backtrack(combination + letter, next_digits.substring(1));
            }
        }
    }
    
    public List<String> letterCombinations(String digits) {
        output = new ArrayList<>();
        if(digits.length() != 0){
            backtrack("", digits);
        }
        return output;
    }
}
__________________________________________________________________________________________________
34548 kb
class Solution {
	    private String[] mapping = new String[] {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	    
	    public List<String> letterCombinations(String digits) {
	        LinkedList<String> ans = new LinkedList<String>();
	        if(digits.length() == 0) return ans;
	        helper(ans, digits, "", 0);
	        return ans;
	    }
	    
	    public void helper(List<String> ans, String digits, String cur, int count){
	        if(count == digits.length()){
	            ans.add(cur);
	            return;
	        }
            String temp = new String(cur);
	        for(char c : mapping[digits.charAt(count)-'0'].toCharArray()){
	            helper(ans, digits, cur+c, count+1);
	            cur = temp;
	        }
	    }
}
__________________________________________________________________________________________________
