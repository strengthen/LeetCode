__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
           public List<Integer> addToArrayForm(int[] A, int K) {
        int carry = 0;
        for(int i = A.length-1; i >= 0; i--){
            if (K!=0) {
                int a = K%10;
                int b = A[i];
                int sum = a + b + carry;
                carry = sum / 10;
                A[i] = sum % 10;
                K /= 10;
            } else {
                int sum = A[i] + carry;
                if( sum < 10) {
                    A[i] = sum;
                    carry = 0;
                    break;
                } else {
                    A[i] = sum % 10;
                    carry = 1;
                }
            }
        }
        
        List<Integer> ans = new ArrayList<>();
        if(K != 0) {
            K += carry;
            Stack<Integer> stack = new Stack<>();
            
            while(K != 0) {
                stack.push(K % 10);
                K /= 10;
            }
            while(!stack.isEmpty()) {
                ans.add(stack.pop());
            }
        } else if(carry == 1) {
            ans.add(1);
        }
        for(int i = 0; i < A.length; i++) {
            ans.add(A[i]);
        }
        return ans;
    }
}
__________________________________________________________________________________________________
sample 40596 kb submission
class Solution {
    public List<Integer> addToArrayForm(int[] A, int K) {
        int i = A.length-1;
        while (K > 0 && i >= 0){
            int sum = A[i]+K;
            A[i] = sum%10;
            K = sum/10;
            i--;
        }
        List<Integer> res = new ArrayList<>();
        while (K > 0) {
            res.add(0, K%10);
            K = K/10;
        }
        for (int n : A) res.add(n);
        return res;
    }
}
__________________________________________________________________________________________________
