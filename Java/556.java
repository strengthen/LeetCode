__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    
    public int nextGreaterElement(int n) {
        int ans = -1;
        char[] chs = (n+"").toCharArray();
        int len = chs.length;
        if(n < 12) return -1;
        // find  the first chs[i-1] < chs[i] from back to front
        int index = -1;
        for(int i=len-1; i>0; i-- ){
            if(chs[i-1] < chs[i]){
                index = i-1;
                break;
            }
        }
        if(index == -1) return ans;
        
        // reverse the chs from chs[index+1] to chs[len-1]
        reverse(chs, index+1, len-1);
        
        // find the first chs[i] from chs[index+1] to chs[len-1] which is bigger than chs[index]
        // then swap chs[index] and chs[i] so that we get the answer.
        for(int i=index+1; i<len; i++){
            if(chs[i] > chs[index]){
                swap(chs, index, i);
                break;
            }
        }
        try{
            ans = Integer.parseInt(String.valueOf(chs));
        } catch(Exception e){}
        
        
        
        return ans;
    }
    
    private void swap(char[] chs, int i, int j){
        char t = chs[i];
        chs[i] = chs[j];
        chs[j] = t;
    }
    
    private void reverse(char[] chs, int i, int j){
        while( i < j) swap(chs, i++, j--);
    }    
}
__________________________________________________________________________________________________
sample 31596 kb submission
class Solution {
    public int nextGreaterElement(int n) {
        char[] digits = (""+n).toCharArray();
        
        int index = 0;
        for(int i=digits.length-1;i>=1;i--){
            if(digits[i-1]<digits[i]){
                index = i;
                break;
            }
        }
        
        if(index==0){
            return -1;
        }
        
        reverse(digits, index, digits.length-1);
        for(int i=index;i<digits.length;i++){
            if(digits[index-1]<digits[i]){
                swap(digits,index-1,i);
                break;
            }
        }
        
        long ans = Long.parseLong(new String(digits));
        if(ans>Integer.MAX_VALUE){
            return -1;
        }
        return (int)ans;
    }
    
    private void reverse(char digits[], int f, int r){
        while(f<r){
            swap(digits, f, r);
            f++;
            r--;
        }
    }
    
    private void swap(char digits[], int f, int r){
        char t = digits[f];
        digits[f] = digits[r];
        digits[r] = t;
    }
}
__________________________________________________________________________________________________
