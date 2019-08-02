__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean splitArraySameAverage(int[] A) {
        return useDFS(A);
    }
    
    private boolean useDFS(int[] a) {
        int n = a.length;
        // claculate the total sum
        int sum = getSum(a);
        // check possibility
        // sum / n == sum1 / k == sum2 / (n - k)
        // k is number of elements, k <= n / 2
        // if possible, there should be some k where (sum * k % n) is 0
        if (!isPossible(a, sum)) {
            return false;
        }
        Arrays.sort(a);
        // i is number of elements
        for (int i = 1; i <= n / 2; ++i) {
            // ensure possibility
            if (sum * i % n == 0 && dfs(a, sum * i / n, i, 0)) {
                return true;
            }
        }
        return false;
    }
    
    private boolean dfs(int[] a, int remainingSum, int curNum, int start) {
        if (curNum == 0) {
            // no available element
            // check remainingSum
            return remainingSum == 0;
        }
        if (a[start] > remainingSum / curNum) {
            // the starting element already exceeds the average in an increasing subarray
            return false;
        }
        // ensure there are (curNum - 1) elements for the next round
        for (int i = start; i < a.length - curNum + 1; ++i) {
            if (i > start && a[i] == a[i - 1]) {
                // de-dupe
                continue;
            }
            // update remainingSum, curNum and starting index
            if (dfs(a, remainingSum - a[i], curNum - 1, i + 1)) {
                return true;
            }
        }
        return false;
    }
    
    private boolean isPossible(int[] a, int sum) {
        int n = a.length;
        boolean possible = false;
        for (int i = 1; i <= n / 2 && !possible; ++i) {
            if (sum * i % n == 0) {
                possible = true;
                break;
            }
        }
        return possible;
    }
    
    private int getSum(int[] a) {
        int sum = 0;
        for (int i : a) {
            sum += i;
        }
        return sum;
    }
}
__________________________________________________________________________________________________
sample 35372 kb submission
class Solution {    
    public boolean check(int[] A, int leftSum, int leftNum, int startIndex) {       
        if (leftNum == 0) return leftSum == 0;
        if ((A[startIndex]) > leftSum / leftNum) return false;
        for (int i = startIndex; i < A.length - leftNum + 1; i ++) {
	    if (i > startIndex && A[i] == A[i - 1]) continue;
            if (check(A, leftSum - A[i], leftNum - 1, i + 1)) return true;
        }
        return false;       
    }
    
    public boolean splitArraySameAverage(int[] A) {
        if (A.length == 1) return false;
        int sumA = 0;
        for (int a: A) sumA += a;
        Arrays.sort(A);
        for (int lenOfB = 1; lenOfB <= A.length / 2; lenOfB ++) {
            if ((sumA * lenOfB) % A.length == 0) {
                if (check(A, (sumA * lenOfB) / A.length, lenOfB, 0)) return true;
            }
        }
        return false;
        
    }
}
__________________________________________________________________________________________________
