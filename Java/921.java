__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int minAddToMakeValid(String S) {
        int ans = 0,bal = 0;
        for(int i=0;i<S.length();++i){
            bal+=S.charAt(i) == '('? 1:-1;
            //It is guaranteed that bal >= -1
            if(bal == -1){
                ans++;
                bal++;
            }
        }
        return ans+bal;
    }
}
__________________________________________________________________________________________________
sample 35532 kb submission
class Solution {
    public int minAddToMakeValid(String S) {
      
        int left = 0;
        int right = 0;
        for(int i=0; i < S.length();i++){
     
            if(S.charAt(i)=='(') {
                left++;
            }else if(S.charAt(i)==')'){
                if(left > 0 ) left--;
                else right++;
            }
            // skip all other
        }
        return left+right;
    }
}
__________________________________________________________________________________________________
