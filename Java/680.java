__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public boolean validPalindrome(String s) {
        if(s==null ||s.length()==0){
            return true;
        }
        return validPalindrome(s,0,s.length()-1, 0);
    }
    
    private boolean validPalindrome(String s, int i, int j, int noMatchCount){
        if(noMatchCount>1){
            return false;
        }
        while(j>i){
            if(s.charAt(i) !=s.charAt(j)){
                    return validPalindrome(s, i+1, j, noMatchCount+1) || validPalindrome(s,i, j-1, noMatchCount+1);
            }else {
                i++;
                j--;
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 38704 kb submission
class Solution {
    public boolean validPalindrome(String s) {
        int len=s.length();
        int left=0;
        int right=len-1;
        while(left<right){
            if(s.charAt(left)!=s.charAt(right))
                return isValid(left+1,right,s) || isValid(left,right-1,s);
            left++;
            right--;
        }
        return  true;
    }
    public boolean isValid(int left,int right,String s){
        while(left<right){
            if(s.charAt(left++)!=s.charAt(right--))
                return false;
        }
        return true;
    }
}
__________________________________________________________________________________________________
