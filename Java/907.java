__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public int sumSubarrayMins(int[] A) {
        int res = 0;
        int mod = (int)1e9 + 7;
        int j, k, top = -1;
        int[] stack = new int[A.length];
        
        for (int i = 0; i <= A.length; i++) {
            
            while(top != -1 && A[stack[top]] > ((i == A.length) ? 0 : A[i])) {
                j = stack[top--];
                k = top == -1 ? -1 : stack[top];
                res = (res + A[j] * (j - k) * (i - j)) % mod;
            }
            stack[++top] = i;
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 40996 kb submission
class Solution {
    public int sumSubarrayMins(int[] A) {
        int MOD = 1_000_000_007;

        Stack<RepInteger> stack = new Stack();
        int ans = 0, dot = 0;
        for (int j = 0; j < A.length; ++j) {
            // Add all answers for subarrays [i, j], i <= j
            int count = 1;
            while (!stack.isEmpty() && stack.peek().val >= A[j]) {
                RepInteger node = stack.pop();
                count += node.count;
                dot -= node.val * node.count;
            }
            stack.push(new RepInteger(A[j], count));
            dot += A[j] * count;
            ans += dot;
            ans %= MOD;
        }

        return ans;
    }
}

class RepInteger {
    int val, count;
    RepInteger(int v, int c) {
        val = v;
        count = c;
    }
}
__________________________________________________________________________________________________
