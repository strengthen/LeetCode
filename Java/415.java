__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String addStrings(String s1, String s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        char[] ans = new char[Math.max(len1, len2) + 1];
        int sum = 0;
        int carry = 0;
        for (int i = 0; i < ans.length; i++) {
            int c1 = i >= len1 ? 0 : s1.charAt(len1 - 1 - i) - '0';
            int c2 = i >= len2 ? 0 : s2.charAt(len2 - 1 - i) - '0';
            sum = c1 + c2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans[ans.length - 1 - i] = (char)(sum + '0');
        }
        return ans[0] == '0' ? String.valueOf(ans, 1, ans.length - 1) : String.valueOf(ans);
    }
}
__________________________________________________________________________________________________
sample 34980 kb submission
class Solution {
    public String addStrings(String num1, String num2) {
    
        int[] n1 = num1.chars().map(c -> (int)(c-'0')).toArray();
        int[] n2 = num2.chars().map(c -> (int)(c-'0')).toArray();
        
        StringBuilder result = new StringBuilder();
        
        int inc = 0;
        int n = Math.max(n1.length, n2.length);
        for(int i=0; i<n; i++) {
            int idx1 = n1.length - i - 1;
            int idx2 = n2.length - i - 1;
            
            int sum = inc;
            if (idx1 >= 0) sum+=n1[idx1];
            if (idx2 >= 0) sum+=n2[idx2];
            
            result.append(sum % 10);
            inc = sum / 10;
        }
        
        if (inc > 0) {
            result.append('1');
        }

        return result.reverse().toString();
    }
}
__________________________________________________________________________________________________
