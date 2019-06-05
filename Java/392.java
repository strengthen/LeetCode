__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean isSubsequence(String s, String t) {
        char[] ch = s.toCharArray();
        int index = -1;
        for(char c:ch){
            index = t.indexOf(c, index + 1);
            if(index == -1) return false;
        }
        return true;        
    }
}
__________________________________________________________________________________________________
sample 47848 kb submission
class Solution {
    public boolean isSubsequence(String s, String t) {
        if(s == null || s.length() == 0) return true;
        if(t == null || t.length() == 0){
            if(s == null || s.length() == 0) return true;
            else return false;
        }
        Stack<Character> stack = new Stack<>();
        for(Character ch : s.toCharArray()){
            stack.push(ch);
        }
        char[] longer = new char[t.length()];
        longer = t.toCharArray();
        for(int i = longer.length - 1; i >= 0; i--){
           // if(stack.isEmpty()) return false;
            if(!stack.isEmpty() && longer[i] == stack.peek()){
                stack.pop();
            }
        }
        return stack.isEmpty();
    }
}
__________________________________________________________________________________________________
