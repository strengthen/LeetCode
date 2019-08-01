__________________________________________________________________________________________________
sample 61 ms submission
class Solution {
    Random random = new Random();
    int[] wSums;

    public Solution(int[] w) {
        this.random = random;
        for(int i = 1; i<w.length; i++){
            w[i] += w[i-1];
        }
        wSums = w;
    }
    
    public int pickIndex() {
        int len = wSums.length;
        int idx = random.nextInt(wSums[len-1]) + 1;
        int left =0, right = len-1;
        while(left < right){
             int mid = left + (right-left)/2;
            if(wSums[mid] == idx)
                return mid;
            else if(wSums[mid] < idx)
                left = mid + 1;
            else
                right = mid;           
        }
        return left;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
__________________________________________________________________________________________________
sample 43048 kb submission
class Solution {
    int[] weight;
    int sum = 0;
    private Random r = new Random();
    public Solution(int[] w) {
        weight = new int[w.length];
        weight[0] = w[0];
        for (int i = 1; i < w.length; ++i) {
            weight[i] = weight[i - 1] + w[i];
        }
        sum = weight[weight.length - 1];
    }
    
    public int pickIndex() {
        int rnd = r.nextInt(sum) + 1;
        int rst = Arrays.binarySearch(weight, rnd);
        if (rst < 0 ) {
            rst = -rst - 1;
        }
        return rst;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
__________________________________________________________________________________________________
