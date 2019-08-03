__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> result = new ArrayList<String>();
		for (String word : words) {
			if (match(word, pattern)) {
				result.add(word);
			}
		}
		return result;
    }
    
    private boolean match(String word, String pattern) {
		char[] words = word.toCharArray();
		char[] patterns = pattern.toCharArray();
		int[][] record = new int[2][26];
		for (int i = 0; i < words.length; i++) {
			if (record[0][words[i] - 'a'] == record[1][patterns[i] - 'a']) {
				record[0][words[i] - 'a'] = i + 1;
				record[1][patterns[i] - 'a'] = i + 1;
			} else {
				return false;
			}
		}
		return true;
	}
}
__________________________________________________________________________________________________
sample 35048 kb submission
class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        
      List<String> wordsList = Arrays.asList(words);
      
        List<String> result = null;
        
        result =  wordsList.stream().filter(w -> isPatternMatch(w, pattern)).collect(Collectors.toList());
        
      
        
        //System.out.println(isPatternMatch("ccc", "abb"));
        
        return result;
    }
    
    boolean isPatternMatch(String word, String pattern){
        
        if(word.length() != pattern.length())
            return false;

        Map<Character, Character>  map = new HashMap<>();
        Map<Character, Character>  reverseMap = new HashMap<>();
        
        int i=0;
        
        while(i < pattern.length()){
            
           
            
            if(map.containsKey(pattern.charAt(i))){
                
             
                
                if(!map.get(pattern.charAt(i)).equals(word.charAt(i)))
                    return false;
                
            }else
                map.put(pattern.charAt(i), word.charAt(i));
            
            
           if(reverseMap.containsKey(word.charAt(i))){
            
             
                
                if(!reverseMap.get(word.charAt(i)).equals(pattern.charAt(i)))
                    return false;
                
            }else
                reverseMap.put(word.charAt(i), pattern.charAt(i));
            
            
            i++;
        }
        
        return true;
    }
}
__________________________________________________________________________________________________
