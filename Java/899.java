__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String orderlyQueue(String S, int K) {
        int[] cs = new int[26];
        StringBuilder sb = new StringBuilder();
        for(char c: S.toCharArray()){
            cs[c - 'a']++;
        }
        int index = -1;
        for(int i = 0; i < 26 && index == -1; i++){
            if(cs[i] > 0){
                while(cs[i] > 0){
                    cs[i]--;
                    sb.append(Character.toString((char)('a' + i)));
                    if(K == 1){
                        index = S.indexOf((char)('a' + i));
                        break;
                    }
                        
                }
            }
        }
        if(K == 1){
            sb = new StringBuilder();
            while(index != -1){
                StringBuilder current = new StringBuilder();
                current.append(S.charAt(index));
                current.append(S.substring(index + 1, S.length()));
                current.append(S.substring(0, index));
                if(sb.length() == 0 || sb.toString().compareTo(current.toString()) > 0)
                    sb = current;
                index = S.indexOf(S.charAt(index), index + 1);
            }
        }
        return sb.toString();
    }
}
__________________________________________________________________________________________________
sample 37404 kb submission
class Solution {
    public String orderlyQueue(String S, int K) {
        if (K >= 2) {
            char[] arr = S.toCharArray();
            Arrays.sort(arr);
            return new String(arr);
        }
        String ret = S;
        int len = S.length();
        for (int i = 0; i < len; ++i) {
            String temp = S.substring(1) + S.charAt(0);
            if (temp.compareTo(ret) < 0) 
                ret = temp;
            S = temp;
        }
        return ret;
    }
}
__________________________________________________________________________________________________
