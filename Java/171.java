__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int titleToNumber(String s) {
        int c=0;
        int res=0,n=s.length()-1;
        while(n>=0) {
            res += ((s.charAt(n)-'A'+1)*((int)Math.pow(26,c)));
            n--;
            c++;
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int titleToNumber(String s) {
       String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        int length = s.length();
        int number = before(length);
        for (int i = 0; i < length; i++) {
            int pos = alphabet.indexOf(s.charAt(i));
            int mul =  (int) Math.pow(26, length-i-1);
            number += pos * mul;
        }

        return number+1;  
    }
    
     public int before(int n) {
        int sum = 0;
        for (int i = 0; i < n-1; i++)
            sum += Math.pow(26, i+1);
        return sum;
    }
}
__________________________________________________________________________________________________
