__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int bestRotation(int[] A) {
        int n = A.length;
        int[] score = new int[n + 1];
        for (int i = 0; i < n; i++) {
            if (A[i] > i) {
                score[i + 1]++;
                score[n - (A[i] - i) + 1]--;
            } else {
                score[0]++;
                score[i - A[i] + 1]--;
                score[n - (n - i) + 1]++;
                score[n]--;
            }
        }
        int res = 0;
        int max = score[0];
        for (int i = 1; i < n; i++) {
            score[i] += score[i - 1];
            if (score[i] > max) {
                max = score[i];
                res = i;
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 39336 kb submission
class Solution {
    public int bestRotation(int[] A) {
        int n = A.length;
        int[] rotateLost = new int[n];   
        for(int i = 0; i<n; i++)
            rotateLost[(i-A[i]+n+1)%n]++;
        int[] score = new int[n];
        int max = score[0];
        int result = 0;
        for(int i = 1; i<n; i++){
            score[i] = score[i-1]-rotateLost[i]+1;
            if(max<score[i]){
                max = score[i];
                result = i;
            }
        }
        
        return result;
    }
}
__________________________________________________________________________________________________
