__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int[] countBits(int num) {
        
        int[] bits = new int[num+1];
        bits[0] = 0;
        
        if(num < 1) {
            return bits;
        }
        
        bits[1] = 1;
        for(int i = 2; i <= num; ++i) {
            bits[i] = (i & 0x1) + bits[i >>> 1];
        }
        
        return bits;
    }
}
__________________________________________________________________________________________________
sample 35608 kb submission
class Solution {
    public int[] countBits(int num) {
        int[] res = new int[num+1];
        for(int i = 0; i <= num; i++){
            int cnt = 0;
            String str = Integer.toBinaryString(i);
            for(int j = 0; j < str.length(); j++){
                char c = str.charAt(j);
                char one = '1';
                if(c == one)
                    cnt++;
            }
            res[i] = cnt;
        }
        return res;
    }
}
__________________________________________________________________________________________________
