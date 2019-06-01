__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public void reverseString(char[] s) {
        char[] tmp=new char[s.length];
        for(int i=0;i<s.length;i++){
            int a=s.length-i-1;
            tmp[i]=s[a];
            
        }
        for(int i=0;i<tmp.length;i++){
            s[i]=tmp[i];
            
        }
    }
}
__________________________________________________________________________________________________
sample 40316 kb submission
class Solution {
    public void reverseString(char[] s) {
        
        for (int i = 0; i < s.length / 2; i++) {
            char temp = s[i];
            s[i] = s[s.length - 1 - i];
            s[s.length - 1 - i] = temp;
        }
    }
}
__________________________________________________________________________________________________
