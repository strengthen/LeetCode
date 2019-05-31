__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int hIndex(int[] citations) {
        int check[] = new int[citations.length + 1];
        for (int i = 0; i < citations.length; i++){
            if (citations[i] < citations.length){
                check[citations[i]] += 1;
            } else {
                check[check.length - 1] += 1;
            }
        }
        int sum = 0;
        for (int j = check.length - 1; j > 0; j--){
            sum = sum + check[j];
            if (sum >= j){
                return j;
            }
        }
        return 0;
    }
}
__________________________________________________________________________________________________
sample 34592 kb submission
class Solution {
    public int hIndex(int[] citations) {
        if (citations == null || citations.length == 0) {
            return 0;
        }
        int min = 0;
        int max = citations.length;
        int mid;
        while (min + 1 < max) {
            mid = min + (max - min) / 2;
            if (findRes(citations, mid) < mid) {
                max = mid;
            } else {
                min = mid;
            }
        }
        if (findRes(citations, max) >= max) {
            return max;
        } else {
            return min;
        }
    }
    private int findRes(int[] citations, int mid) {
        int cnt = 0;
        for (int i = 0; i < citations.length; i++) {
            if (citations[i] >= mid) {
                cnt++;
            }
        }
        return cnt;
    }
}
__________________________________________________________________________________________________
