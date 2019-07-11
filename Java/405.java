__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public String toHex(int num) {
        if(num == 0) return "0";
        StringBuilder sb = new StringBuilder();
        
        while(num != 0) {
            int digit = num & 0xf;
            if(digit >= 0 && digit <= 9) sb.append(digit);
            else sb.append((char)('a' + digit - 10));
            num >>>= 4;
        }
        return sb.reverse().toString();
    }
}
__________________________________________________________________________________________________
sample 35176 kb submission
class Solution {
    public String toHex(int num) {
        char[] map = new char[] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        if (num == 0) return "0";
        StringBuilder ans = new StringBuilder();
        while (num != 0) {
            ans.append(map[num & 15]);
            num >>>= 4;
        }
        return ans.reverse().toString();
    }
}
__________________________________________________________________________________________________
