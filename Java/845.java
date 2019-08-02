__________________________________________________________________________________________________
sample 1 ms submission
class Solution {

    public int longestMountain(int[] A) {
        int n;
        if (A == null || (n = A.length) < 3) {
            return 0;
        }
        int i = 1, max = 0;
        while (i < n) {
            // find the start of the up left mountain foot
            while (i < n && A[i] <= A[i - 1]) {
                i++;
            }
            int start = i - 1;
            while (i < n && A[i] > A[i - 1]) {
                i++;
            }
            if (i >= n) {
                return max;
            }
            if (A[i] == A[i - 1]) {
                continue;
            }
            while (i < n && A[i] < A[i - 1]) {
                i++;
            }
            int end = i - 1;
            max = Math.max(max, end - start + 1);
        }
        return max;
    }
}
__________________________________________________________________________________________________
sample 38832 kb submission
class Solution {
    public int longestMountain(int[] A) {
        int N = A.length;
        int count = 0;
        int j = 0;
        
        while(j < N){
            int end = j;
            
            if(end+1 < N && A[end] < A[end+1]){
                while(end+1 < N && A[end] < A[end+1]){
                    end++;
                }
                
                if(end+1 < N && A[end] > A[end+1]){
                    while(end + 1 < N && A[end] > A[end+1]){
                        end++;
                    }
                    count = Math.max(count, end-j+1);
                }
            }
            j = Math.max(end, j+1);
        }
        return count;
    }
}
__________________________________________________________________________________________________
