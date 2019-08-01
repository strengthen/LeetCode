__________________________________________________________________________________________________
sample 26 ms submission
class Solution {
    public List<String> findAllConcatenatedWordsInADict(String[] words) { 
        List<String> res = new LinkedList<>();
        Set<String> set = new HashSet<>();
        int minlen = Integer.MAX_VALUE;
        
        //build dict
        for(String word : words){
            if(word.length()>0){
                set.add(word);
                minlen = Math.min(minlen, word.length());
            }
        }
        
        //check each word and add good ones to dict
        for(String word : words){
            if(canForm(word, 0, minlen, set)){
                res.add(word);
            }
        }
        return res;
    
    }
    
    //no need to remove and add current word in this setup
    private static boolean canForm(String word, int start, int offset, Set<String> set){
        for(int mid=start+offset; mid<=word.length()-offset;mid++){
            if(set.contains(word.substring(start,mid)) &&
              (set.contains(word.substring(mid)) || canForm(word, mid, offset, set))) {//backtrack
                return true;
                }
        }
        return false;
    }
}
__________________________________________________________________________________________________
sample 27 ms submission
class Solution {
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        List<String> rs = new ArrayList<>();
        Set<String> set = new HashSet<>();
        int minLen = Integer.MAX_VALUE;
        for (String w : words) {
            if (w.length() > 0) {
                set.add(w);
            }
            minLen = Math.min(minLen, w.length());
        }
        
        for (String w : words) {
            if (canBreakDfs(0, w.length(), minLen, w, set)) {
                rs.add(w);
            }
        }
        
        return rs;
    }
    
    private boolean canBreakDfs(int left, int right, int minLen, String s, Set<String> words) {
        for (int i=left+minLen; i<=right-minLen; i++) {            
            if (words.contains(s.substring(left, i)) && 
                (words.contains(s.substring(i, right)) || canBreakDfs(i, right, minLen, s, words))) {
                return true;
            }
        }
        
        return false;
    }
}
__________________________________________________________________________________________________
sample 44520 kb submission
class Solution {
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        Arrays.sort(words, (String a, String b) -> a.length()-b.length());
        Set<String> set = new HashSet<String>();
        List<String> ans = new ArrayList<String>();
        
        for(String n : words){
            if(check(set,n)){
                ans.add(n);
            }
            set.add(n);
        }
        
        Collections.sort(ans);
        return ans;
    }
    private boolean check(Set<String> words, String word){
        if(word.equals(""))return false;
        boolean[] dp = new boolean[word.length()+1];
        dp[0]=true;
        for(int end = 1; end <= word.length(); end++){
            for(int beg = 0; beg < end; beg++){
                if(!dp[beg]) continue;
                if(words.contains(word.substring(beg,end))){
                    dp[end]=true;
                    break;
                }
            }
        }
        return dp[word.length()];
    }
}