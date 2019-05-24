__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        return dfs(s, wordDict, 0, new int[s.length()]);
    }

    private boolean dfs(String s, List<String> dict, int begin, int[] memo) {
        if (begin >= s.length() || memo[begin] == -1) return false;
        for (int i = 0; i < dict.size(); i++) {
            int end = isSubStr(s, begin, dict.get(i));
            if (end != -1) {
                if (end == s.length() - 1 || dfs(s, dict, end + 1, memo)) return true;
            }
        }
        memo[begin] = -1;
        return false;
    }

    private int isSubStr(String s, int begin, String p) {
        if (begin + p.length() > s.length()) return -1;
        for (int i = 0; i < p.length(); i++) {
            if (p.charAt(i) != s.charAt(begin + i)) return -1;
        }
        return begin + p.length() - 1;
    }
}
__________________________________________________________________________________________________
sample 33088 kb submission
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Collections.sort(wordDict, (l, r) -> Integer.compare(r.length(), l.length()));
        Boolean[] cache = new Boolean[s.length() + 1];
        return match(s, 0, wordDict, cache);
    }
    
    public boolean match(String s, int offset, List<String> wordDict, Boolean[] cache) {
        if (offset == s.length()) return true;
        if (cache[offset] != null) return cache[offset];
        
        for (String word : wordDict) {
            if (s.startsWith(word, offset) && match(s, offset + word.length(), wordDict, cache)) {
                cache[offset] = true;
                return true;        
            }
        }
        
        return cache[offset] = false;
    }
}
__________________________________________________________________________________________________
