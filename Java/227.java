__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int calculate(String s) {
        if (s == null || s.length() == 0) return 0;
        char[] a = new char[s.length()];
        int n = 0;
        for (char c : s.toCharArray()) {
            if (c != ' ') a[n++] = c;
        }
        int i = 0, num = 0;
        while (i < n && '0' <= a[i] && a[i] <= '9') {
            num = num * 10 + a[i++] - '0';
        }
        int[] stack = new int[n];
        stack[0] = num;
        int stackLen = 1;
        while (i < n) {
            int c = a[i++];
            num = 0;
            while (i < n && '0' <= a[i] && a[i] <= '9') {
                num = num * 10 + a[i++] - '0';
            }
            switch (c) {
                case '+':
                    stack[stackLen++] = num;
                    break;
                case '-':
                    stack[stackLen++] = -num;
                    break;
                case '*':
                    stack[stackLen - 1] = stack[stackLen - 1] * num;
                    break;
                case '/':
                    stack[stackLen - 1] = stack[stackLen - 1] / num;
                    break;
            }
        }
        int sum = 0;
        for (int x : stack) sum += x;
        return sum;
    }
}
__________________________________________________________________________________________________
sample 34032 kb submission
class Solution {
    public int calculate(String s) {
        if(s == null || s.length() == 0) {
            return 0;
        }
        
        s = s.trim();
        
        long prevNum = 0;
        int sum = 0;
        char prevOp = '+';
        
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(c == ' ') continue;
            if(Character.isDigit(c)) {
                int val = c - '0';
                while(i + 1 < s.length() && Character.isDigit(s.charAt(i+1))) {
                    val = val * 10 + (s.charAt(i+1) - '0');
                    i++;
                }
                if (prevOp == '+') {
                    sum += prevNum;
                    prevNum = val;
                } else if (prevOp == '-') {
                    sum += prevNum;
                    prevNum = -val;
                } else if (prevOp == '*') {
                    prevNum = prevNum * val;
                } else if (prevOp == '/') {
                    prevNum = prevNum/val;
                }
            } else {
                prevOp = c;
            }
        }
        
        sum += prevNum;
        return sum;
    }
}
__________________________________________________________________________________________________
