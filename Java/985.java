__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int sum = 0;
        for (int i = 0; i < A.length; i++) {
            sum += (A[i] & 1 ^ 1) * A[i];
        }
        
        int[] result = new int[queries.length];
        for (int index = 0; index < queries.length; index++) {
            int pos = queries[index][1];
            
            //System.out.println(""+A[pos]+" "+isEven[pos]);
            
            sum -= (A[pos] & 1 ^ 1) * A[pos];
            A[pos] += queries[index][0];
            sum += (A[pos] & 1 ^ 1) * A[pos];
            
            //System.out.println(""+A[pos]+" "+isEven[pos]);

            result[index] = sum;
        }
        return result;
    }
}
__________________________________________________________________________________________________
sample 56432 kb submission
class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int sum = Arrays.stream(A).filter(n -> isEven(n)).sum();
        int[] res = new int[queries.length];
        
        for (int i=0; i<queries.length; i++) {
            int[] q = queries[i];
            int numToAdd = q[0];
            int idx = q[1];
            int before = A[idx];
            A[idx] += numToAdd;
            if (isEven(before)) {
                sum += isEven(A[idx]) ? numToAdd : -before;
            } else {
                sum += isEven(A[idx]) ? A[idx] : 0;
            }
            res[i] = sum;
        }
        
        return res;
    }
    
    private boolean isEven(int num) {
        return Math.abs(num) % 2 == 0;
    }
}
__________________________________________________________________________________________________
