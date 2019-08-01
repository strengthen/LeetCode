__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public String reverseStr(String s, int k) {
        char[] res = s.toCharArray();
        for(int i = 0; i < s.length(); i+=2*k){
            swap(res,i,Math.min(i+k-1,s.length()-1));
        }
        return new String(res);
    }
    
    private void swap(char[] res, int start, int end){
        while(start < end){
            char tmp = res[start];
            res[start++]= res[end];
            res[end--]= tmp;
        }
    }
}
__________________________________________________________________________________________________
sample 37388 kb submission
class Solution {
    public String reverseStr(String s, int k) {
       char[] chs = s.toCharArray();
       int len = chs.length;        
       boolean reverseFlag = true;     
       for(int i = 0; i < len; i += k){
           if(reverseFlag){
               int left = i;
               int right = Math.min(left + k - 1, len - 1);
               reversePartOfCharArray(chs, i, right);
           }
           reverseFlag = !reverseFlag;
       } 
         
       return String.valueOf(chs);
    }
    
    public void reversePartOfCharArray(char[] chs, int l, int r){
        while(l < r){
            char tmp = chs[l];
            chs[l] = chs[r];
            chs[r] = tmp;
            l ++;
            r --;
        }
    }
}
__________________________________________________________________________________________________
