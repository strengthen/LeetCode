__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int[] diStringMatch(String S) {
        char[] input = S.toCharArray();
        int max = input.length;
        int min = 0;

        int[] result = new int[max + 1];

        //IDID
        for (int i = 0; i < input.length; i++) {

            if(input[i] == 'D'){
                result[i] = max--;
            }else{
                result[i] = min++;
            }
        }
        result[input.length] = min;
        return result;
    }
}
__________________________________________________________________________________________________
sample 38200 kb submission
class Solution {
    public int[] diStringMatch(String S) {
        int[] res = new int[S.length()+1];
        int low = 0;
        int high = S.length();
        int cur = 0;
        
        while(low < high && cur < S.length()) {
            if(S.charAt(cur) == 'I') {
                res[cur] = low;
                low++;
            } else {
                res[cur] = high;
                high--;
            }
            cur++;
        }
        res[cur] = low;
        return res;        
    }
}
__________________________________________________________________________________________________
