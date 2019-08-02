__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
  public List<Integer> splitIntoFibonacci(String S) {
    List<Integer> ans = new ArrayList<>();
    split(S, 0, ans);
    return ans;
  }
  
  private boolean split(String s, int start, List<Integer> ans) {
    if (start == s.length()) {
      return ans.size() > 2;
    }
    
    long num = 0;
    
    for (int i = start; i < s.length(); i++) {
      num = num * 10 + (s.charAt(i) - '0');
      
      if (num > Integer.MAX_VALUE) return false;
      if (isValidNumber(num, s, start, i, ans)) {
        ans.add((int) num);
        if (split(s, i + 1, ans)) return true;
        ans.remove(ans.size() - 1);
      }      
    }
    
    return false;
  }
  
  private boolean isValidNumber(long num, String s, int start, int end, List<Integer> ans) {
    if (start != end && s.charAt(start) == '0') return false;
    if (ans.size() <= 1) return true;
    
    int i = ans.size() - 1;
    return ans.get(i) + ans.get(i - 1) == (int) num;
  }
}
__________________________________________________________________________________________________
sample 35952 kb submission
class Solution {
    public List<Integer> splitIntoFibonacci(String S) {
        List<Integer> ans = new ArrayList<>();
        helper(ans, S, 0);
        return ans;
    }
    public boolean helper(List<Integer> res, String S, int start) {
        if (start == S.length() && res.size() >= 3)
            return true;
        long num = 0;
        for (int i = start; i < S.length(); i++) {
            if (S.charAt(start) == '0' && i > start)
                break;
            num = num * 10 + (S.charAt(i) - '0');
            if (num > Integer.MAX_VALUE)
                break;
            if (res.size() >= 2 && res.get(res.size() - 1) + res.get(res.size() - 2) < num)
                break;
            if (res.size() <= 1 || res.get(res.size() - 1) + res.get(res.size() - 2) == num) {
                res.add((int) num);
                if (helper(res, S, i + 1))
                    return true;
                res.remove(res.size() - 1);
            }
        }
        return false;
    }
}
__________________________________________________________________________________________________
