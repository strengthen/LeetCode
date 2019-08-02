__________________________________________________________________________________________________
sample 3 ms submission
class Solution {    
    public int minimumDeleteSum(String s1, String s2) {
        int len = s1.length();
        int total = 0;
        int[][] pos = new int[26][0];
        
        char[] ss1 = s1.toCharArray();
        for (int i = 0; i < len; i++) {
            total += (int)ss1[i];
            int index = ss1[i] - 'a';
            int[] a = pos[index];
            pos[index] = Arrays.copyOf(a, a.length + 1);
            pos[index][a.length] = i;
        }
        
        int[] dp = new int[len];
        for (int i = 0; i < s2.length(); i++) {
            int ch = (int)s2.charAt(i);
            total += ch;
            int[] ps = pos[ch - 'a'];
            for (int j = ps.length - 1; j >= 0; j--) {
                int p = ps[j];
                int v = ch + (p > 0 ? dp[p - 1] : 0);
                while (p < len && v > dp[p]) {
                    dp[p] = v;
                    p += 1;
                }
            }
        }
        
        return total - (dp[len - 1] << 1);
    }
}
__________________________________________________________________________________________________
sample 34568 kb submission
class Solution {
   public int minimumDeleteSum(String s1, String s2) {
    Map<Character, List<Integer>> mp = new HashMap<>();
    int s1Asc = 0, s2Asc = 0;
    for (int i = 0; i < s2.length(); i++) {
      mp.computeIfAbsent(s2.charAt(i), c -> new LinkedList<>()).add(i);
      s2Asc += s2.charAt(i);
    }
    List<List<Integer>> res = new LinkedList<>();
    for (char c : s1.toCharArray()) {
      s1Asc += c;
      if (mp.containsKey(c))
        res.add(mp.get(c));
    }
    int maxAscii = getMaxSubAsc(res,s2);
    return s1Asc + s2Asc - 2 * maxAscii;
  }

  private int getMaxSubAsc( List<List<Integer>> res,String s){
    int n = s.length(),max=0,last;
    int[] ans = new int[n];
    for (int i=res.size()-1;i>=0;i--)
      for (int j:res.get(i)){
        last=0;
        for (int k=j+1;k<n;k++)
          last = Math.max(last,ans[k]);
        ans[j] = Math.max(s.charAt(j)+last,ans[j]);
      }
    for (int i=0;i<n;i++)
      max = Math.max(max,ans[i]);
    return max;
  }
}
__________________________________________________________________________________________________
