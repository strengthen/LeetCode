__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean isValid(String S) {
        if(S.length()<3){
            return false;
        }
        String base="abc";
        if(S.length()==3 && !S.equals(base)){
            return false;
        }
        
        return valid(S.toCharArray(),0,S.length()-1);
        
        
    }
    
    public boolean valid(char[] s, int i, int j){
        if(j-i==2 && s[i]=='a' && s[i+1]=='b' && s[i+2]=='c'){
            return true;
        }else if(j-i<2){
            return false;
        }
        
        if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='c'){
            if(valid(s,i+3,j)){
                return true;
            }
        }
        
        if(s[i]=='a' && s[i+1]=='b' && s[j]=='c'){
            if(valid(s,i+2,j-1)){
                return true;
            }
        }
        
        if(s[i]=='a' && s[j-1]=='b' && s[j]=='c'){
            if(valid(s,i+1,j-2)){
                return true;
            }
        }
        
        if(s[j-2]=='a' && s[j-1]=='b' && s[j]=='c'){
            if(valid(s,i,j-3)){
                return true;
            }
        }
        
        if(s[i]=='a' && s[(j-i)/2]=='b' && s[j]=='c' ){
           int temp= (j-i)/2;
            if(valid(s,i+1,temp-1) && valid(s,temp+1,j-1)){
                return true;
            }
        }
        
        return false;
        
    }
}
__________________________________________________________________________________________________
sample 38024 kb submission
class Solution {
    public boolean isValid(String S) {
        
        Deque<Character> stack = new ArrayDeque<>();
        
        for (char c : S.toCharArray()) {
            if (c == 'c') {
                if (stack.peek() == null || stack.pop() != 'b') {
                    return false;
                }
                
                if (stack.peek() == null || stack.pop() != 'a') {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }
        
        return stack.peek() == null;
    }
}
__________________________________________________________________________________________________
