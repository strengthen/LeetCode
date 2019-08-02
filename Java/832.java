__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        for(int i = 0; i < A.length; i++){
            for(int j = 0, k = A[0].length - 1; j <= k; j++, k--){
                int temp = (A[i][j] > 0 ? 0 : 1);
                A[i][j] = (A[i][k] > 0 ? 0 : 1);
                A[i][k] = temp;
            }
        }

        return A;
    }
}
__________________________________________________________________________________________________
sample 35228 kb submission
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        for(int i = 0; i< A.length; i++){
            int[] a = A[i];
            ArrayList<Integer> list = new ArrayList<Integer>();
            for(int j = 0; j < a.length; j++){
                int v = a[a.length - 1 - j];
                list.add(v ^ 1);
            }
            A[i] = list.stream().mapToInt(x -> x).toArray();
        }
        return A;
    }
}
__________________________________________________________________________________________________
