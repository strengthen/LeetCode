__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        
        char result = Character.MIN_VALUE;
        
        for (int i = 0; i < letters.length; i++){
            if(letters[i] > target) {
                return letters[i];
                
            }
        }
        
        for (int i = 0; i < letters.length; i++){
            if(letters[i] >= 'a') {
                return letters[i];
                
            }
        }
        
        return result;
    }
}
__________________________________________________________________________________________________
sample 39408 kb submission
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        if (target >= letters[letters.length - 1]) {
            return letters[0];
        }
        int start = 0, end = letters.length - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (letters[mid] <= target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (letters[start] > target) {
            return letters[start];
        } else {
            return letters[end];
        }         
    }    
}
__________________________________________________________________________________________________
