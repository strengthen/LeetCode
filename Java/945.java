__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int minIncrementForUnique(int[] A) {
        int[] dp = new int[40002];
        for (int a : A) dp[a]++;
        int sum=0;
        for (int i = 0; i < dp.length - 1; i++){
            if (dp[i] > 1) {
                sum += dp[i] - 1;
                dp[i+1] += dp[i] - 1;
            }
        }
        if (dp[40001] > 1) {
            sum += (dp[40001] - 1) * dp[40001] / 2;
        }
        return sum;
    }    
}
__________________________________________________________________________________________________
sample 46736 kb submission
class Solution {
    public int minIncrementForUnique(int[] A) {
        
        if (A.length < 2)
            return 0;
        
        Arrays.sort(A);
        
        Set<Integer> set = new HashSet<>();
        Deque<Integer> dup = new ArrayDeque<>();
        int res = 0;
        for (int i = 0; i < A.length; i++) {
            if (set.contains(A[i])) {
                dup.add(A[i]);
            } else {
                set.add(A[i]);
                
                if (i == 0 || A[i - 1] + 1 == A[i])
                    continue;
 
                for (int j = A[i - 1] + 1; j < A[i] && !dup.isEmpty(); j++) {
                    res += (j - dup.poll());
                }
            }
        }
        
        int last = A[A.length - 1] + 1;
        while (!dup.isEmpty()) {
            res += (last - dup.poll());
            last++;
        }
        
        return res;
    }
}
__________________________________________________________________________________________________
