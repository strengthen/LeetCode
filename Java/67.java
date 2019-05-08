__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int i = a.length() - 1, j = b.length() -1, carry = 0;
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (j >= 0) sum += b.charAt(j--) - '0';
            if (i >= 0) sum += a.charAt(i--) - '0';
            sb.append(sum % 2);
            carry = sum / 2;
        }
        if (carry != 0) sb.append(carry);
        return sb.reverse().toString();
    }
}
__________________________________________________________________________________________________
sample 34264 kb submission
class Solution {
    public String addBinary(String a, String b) {
        int i = a.length() - 1; 
        int j = b.length() - 1;
        int carry = 0;
        
        StringBuilder answer = new StringBuilder();
        while(i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if(i >= 0) {
                sum += a.charAt(i--) - '0';
            }
            if(j >= 0) {
                sum += b.charAt(j--) - '0';
            }
            answer.append(sum % 2);
            carry = sum / 2;
        }
        return answer.reverse().toString();
    }
}
__________________________________________________________________________________________________
