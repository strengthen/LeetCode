__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int[][] intervalIntersection(int[][] A, int[][] B) {
        int aindex = 0;
        int bindex = 0;
        
        List<int[]> result = new ArrayList();
        while(aindex < A.length && bindex < B.length) {
            solve(result, A[aindex], B[bindex]);
            
            if (A[aindex][1] < B[bindex][1]) {
                aindex ++;
            } else {
                bindex ++;
            }
        }
        
        return result.toArray(new int[0][0]);
    }
    
    
    public void solve(List<int[]> result, int[] interval1, int[] interval2) {
        int[] left;
        int[] right;
        
        if (interval1[0] < interval2[0]) {
            left = interval1;
            right = interval2;
        } else {
            left = interval2;
            right = interval1;
        }
        
        if (left[1] >= right[1]) {
            result.add(right);
        } else if (left[1] >= right[0]) {
            result.add(new int[] {right[0], left[1]});
        }
    }
}
__________________________________________________________________________________________________
sample 39080 kb submission
class Solution {
    public int[][] intervalIntersection(int[][] A, int[][] B) {
        List<int[]> list = new LinkedList<>();
        int i = 0;
        int j = 0;
        while (i < A.length && j < B.length) {
            if (A[i][1] < B[j][0]) {
                i++;
                continue;
            }
            if (A[i][0] > B[j][1]) {
                j++;
                continue;
            }
            int[] interval = new int[2];
            interval[0] = Math.max(A[i][0], B[j][0]);
            interval[1] = Math.min(A[i][1], B[j][1]);
            list.add(interval);
            if (A[i][1] < B[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        int[][] res = new int[list.size()][2];
        for (int k = 0; k < list.size(); k++) {
            res[k] = list.get(k);
        }
        return res;
    }
}
__________________________________________________________________________________________________
