__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public List<List<String>> partition(String s) {
        if(s == null) throw new IllegalArgumentException();
        List<List<String>> res = new ArrayList<>();
        if(s.length() == 0) return res;
        boolean[] dp = new boolean[s.length()];
        Arrays.fill(dp, true);

        char[] ch = s.toCharArray();
        dfs(res, ch, 0, new ArrayList<>(), dp);
        return res;
    }
    public void dfs(List<List<String>> res, char[] ch, int idx, List<String> path, boolean[] dp) {
        if(idx == ch.length) {
            res.add(new ArrayList<>(path));
            return;
        }
        if(dp[idx] = false) return;
        boolean flag = false;
        for(int i = idx+1; i <= ch.length; i++) {
            if(isPalindrome(ch, idx, i-1)) {
                path.add(new String(ch, idx, i-idx));
                dfs(res, ch, i, path, dp);
                path.remove(path.size()-1);
                flag = true;
            }
        }
        if(!flag) {
            dp[idx] = false;
        }
    }

    public boolean isPalindrome(char[] ch, int start, int end) {
        int l = start;
        int r = end;
        while(l < r) {
            if(ch[l] != ch[r]) return false;
            l++;
            r--;
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 35812 kb submission
class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        if (s == null || s.length() == 0) {
            return res;
        }

        int n = s.length();
        boolean[][] palindromes = new boolean[n][n];
        char[] chars = s.toCharArray();
        
        buildPalindromes(palindromes, chars);
        helper(s, palindromes, res, new ArrayList<String>(), 0);
        
        return res;
    }
    
    private void buildPalindromes(boolean[][] palindromes, char[] chars) {
        int len = chars.length;

        for (int i = 0; i < len; i++) { // only one outer loop is needed!
            // odd number of chars
            for (int j = 0; i - j > -1 && i + j < len; j++) {
                if (chars[i - j] != chars[i + j]) {
                    break;
                }
                palindromes[i - j][i + j] = true;
            }
            // even number of chars
            for (int j = 0; i - j > -1 && i + j + 1 < len; j++) {
                if (chars[i - j] != chars[i + j + 1]) {
                    break;
                }
                palindromes[i - j][i + j + 1] = true;
            }
        }
    }

    private void helper(String s, boolean[][] palindromes, List<List<String>> res, List<String> tmp, int index) {
        int len = s.length();
        
        // Base case.
        if (index == len) {
            res.add(new ArrayList<>(tmp));
            return;
        }
        
        for (int i = index; i < len; i++) {
            if (palindromes[index][i]) {
                tmp.add(s.substring(index, i + 1));
                helper(s, palindromes, res, tmp, i + 1);
                tmp.remove(tmp.size() - 1);
            }
        }
    }
}
__________________________________________________________________________________________________
