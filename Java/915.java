__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int partitionDisjoint(int[] A) {
        if (A == null || A.length == 0) {
            return 0;
        }
        if (A.length <= 2) {
            return 1;
        }
        int left = 0;
        int right = 1;
        int leftMax = A[0];
        int globalMax = A[0];
        
        while (right < A.length) {
            if (A[right] >= leftMax) {
                globalMax = Math.max(globalMax, A[right]);
            } else {
                left = right;
                leftMax = globalMax;
            }
            right++;
        }
        
        return left + 1;
    }
}
__________________________________________________________________________________________________
sample 38532 kb submission
class Solution {
    public int partitionDisjoint(int[] A) {
        int n = A.length, i;
        
        int max[] = new int[n];
        int min[] = new int[n];
        max[0] = A[0]; min[n-1] = A[n-1];
        for(i = 1; i < n; i++)
            max[i] = Math.max(max[i-1], A[i]);
        for(i = n-2; i >= 0; i--)
            min[i] = Math.min(min[i+1], A[i]);
        for(i = 0; i < n-2; i++) {
            if(max[i] <= min[i+1])
                return i+1;
        }
        return n-1;
    }
}
__________________________________________________________________________________________________
