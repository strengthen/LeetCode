__________________________________________________________________________________________________
sample 7 ms submission
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int result = 0;
        int i = 0, j = 0;
        
        while(j < s.length && i < g.length ){
           if(s[j] >= g[i]){
               ++i;
               ++j;
               ++result;
           }else{
               ++j;
           }
        }
        return result;
    }
}
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int count = 0;
        int i = 0;
        int j = 0;
        
        while (i < g.length && j < s.length) {
            if (g[i] <= s[j]) {
                i += 1;
                j += 1;
                count += 1;
            } else {
                j += 1;
            }
        }
        
        return count;
    }
}
__________________________________________________________________________________________________
