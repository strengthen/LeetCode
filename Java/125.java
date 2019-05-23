__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    private static final char[]charMap = new char[256];
    static{
        for(int i=0;i<10;i++){
            charMap[i+'0'] = (char)(1+i);  // numeric
        }
        for(int i=0;i<26;i++){
            charMap[i+'a'] = charMap[i+'A'] = (char)(11+i);  //alphabetic, ignore cases
        }
    }
    public boolean isPalindrome(String s) {
     char[]pChars = s.toCharArray();
        int start = 0,end=pChars.length-1;
        char cS,cE;
        while(start<end){
            cS = charMap[pChars[start]];
            cE = charMap[pChars[end]];
            if(cS!=0 && cE!=0){
                if(cS!=cE)return false;
                start++;
                end--;
            }else{
                if(cS==0)start++;
                if(cE==0)end--;
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 34484 kb submission
class Solution {
    public boolean isPalindrome(String s) {
        int i = 0;
        int j = s.length() - 1;
        
        
        while(i < j){
            char c1 = s.charAt(i);
            char c2 = s.charAt(j);
            
            if(!isAlphaNumeric(c1)){
                i++;
                continue;
            }
            if(!isAlphaNumeric(c2)){
                j--;
                continue;
            }
            
            if((c1 == c2) || (c1 - 'a' == c2 - 'A' && c1 - 'a' >= 0  &&  c1 - 'a'  <= 25 && c2 - 'A' >= 0 && c2 - 'A' <= 25) || (c1 - 'A' == c2 - 'a' && c2 - 'a' >= 0  &&  c2 - 'a'  <= 25 && c1- 'A' >= 0 && c1 - 'A' <= 25)){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
    
    private boolean isAlphaNumeric(char c){
        return (c - 'a' >= 0 && c - 'a' <= 25) || ((c - 'A' >= 0 && c - 'A' <= 25)) || (c >= '0' && c <= '9');
    }
}
__________________________________________________________________________________________________
