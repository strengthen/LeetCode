__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public String reverseOnlyLetters(String S) {
        int l = S.length();
        int i = 0, j = l-1;
        char [] arr = S.toCharArray();
        while (i < j) {
            while (i < l && !isChar(arr[i])) i++;
            while (j >= 0 && !isChar(arr[j])) j--;
            
            if (i > j) break;
            char c = arr[i];
            arr[i] = arr[j];
            arr[j] = c;
            i++;
            j--;
        }
        
        return new String(arr);
    }
    
    private boolean isChar(char c) {
        // System.out.println((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
}
__________________________________________________________________________________________________
sample 35548 kb submission
class Solution {
    public String reverseOnlyLetters(String S) {
        if (S==null || S.length() ==0) return S;
        
        char[] charArray = S.toCharArray();
        int beginIdx = 0, endIdx=S.length()-1;
        
        while(beginIdx < endIdx){
            while(beginIdx<S.length() && !Character.isLetter(S.charAt(beginIdx))) beginIdx++;
            while(endIdx>0 && !Character.isLetter(S.charAt(endIdx))) endIdx--;

            if (beginIdx < endIdx){
                char temp = charArray[beginIdx];
                charArray[beginIdx] = charArray[endIdx];
                charArray[endIdx] = temp;
                beginIdx++;
                endIdx--;
            }
        }
        
        return new String(charArray);
        
    }
}
__________________________________________________________________________________________________
