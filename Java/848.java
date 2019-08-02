__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public String shiftingLetters(String S, int[] shifts) {
        char[] arr = S.toCharArray();
        int sum = 0;
        for(int i = arr.length -1; i>= 0; i--){
            sum = (sum + shifts[i]) % 26;
            int n = (int)arr[i] + sum;
            if(n > (int)'z'){
                n -= 26;
            }
            arr[i] = (char)n;
        }
        return new String(arr);
    }
}
__________________________________________________________________________________________________
sample 41756 kb submission
class Solution {
    public String shiftingLetters(String S, int[] shifts) {
        for (int i = shifts.length - 1; i>0; i--) {
            shifts[i-1] = (shifts[i-1] + shifts[i]) % 26;
        }
        
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i< shifts.length; i++) {
            sb.append((char) ('a' + (S.charAt(i) - 'a' + shifts[i]) % 26));
        }

        return sb.toString();
    }
}
__________________________________________________________________________________________________
