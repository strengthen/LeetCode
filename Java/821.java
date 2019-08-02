__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int[] shortestToChar(String s, char c) {
        int[] res = new int[s.length()];
        int last = -1;
        while (last != s.length() - 1) {
            int index = s.indexOf(c, last + 1);
            if (index != -1) {
                for (int i = last + 1; i <= index; i++) {
                    if (last != -1) {
                        res[i] = Math.min(i - last, index - i);
                    } else {
                        res[i] = index - i;
                    }
                }
                last = index;
            } else {
                for (int i = last + 1; i < res.length; i++) {
                    res[i] = i - last;
                }
                last = res.length - 1;
            }
        }
        return res;
    } 
}
__________________________________________________________________________________________________
sample 37000 kb submission
class Solution {
    public int[] shortestToChar(String S, char C) {
        if(S==null || S.length() == 0)
        {
            return null;
        }
        int[] ans = new int[S.length()];
        int min = Integer.MIN_VALUE/2;
        for(int i = 0 ; i < S.length();i++)
        {
            if(S.charAt(i)==C)
            {
                min=i;
            }
            ans[i] = i-min;
        }
        
        min = Integer.MAX_VALUE/2;
        for(int i = S.length()-1; i >= 0 ; i--)
        {
            if(S.charAt(i)==C)
            {
                min = i;
            }
            ans[i] = Math.min(ans[i],min-i);
        }
        return ans;
    }
}
__________________________________________________________________________________________________
