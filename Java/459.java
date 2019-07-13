__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int len = s.length();
        if (len <= 1) {
            return false;
        }
        char last = s.charAt(len - 1);
        int val = s.lastIndexOf(last, len / 2 - 1) + 1;
        while (val > 0) {
            if (len % val == 0) {
                String pat = s.substring(0, val);
                boolean res = true;
                for (int i = val; i < len; i += val) {
                    if (!s.substring(i, i + val).equals(pat)) {
                        res = false;
                        break;
                    }
                }
                if (res) {
                    return res;
                }
            }
            val = s.lastIndexOf(last, val - 2) + 1;
        }
        return false;
    }
}
__________________________________________________________________________________________________
sample 38048 kb submission
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int[] prefix = kmp(s);
        int len = prefix[s.length()-1];
	    int n = s.length();
	    return (len > 0 && n%(n-len) == 0);
    }
    
    public int[] kmp(String s){
        int n = s.length();
        char[] ch = s.toCharArray();
        int[] res = new int[n];
        int i=0;
        int j=1;
        res[0] = 0;
         while(i < ch.length && j < ch.length){
            if(ch[j] == ch[i]){
                res[j] = i+1;
                i++;
                j++;
            }else{
                if(i == 0){
                    res[j] = 0;
                    j++;
                }else{
                    i = res[i-1];
                }
            }
	    }
        return res;
    }
}
__________________________________________________________________________________________________
