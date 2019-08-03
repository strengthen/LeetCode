__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    
    public int leastOpsExpressTarget(int x, int target) {

        int pos = 0;    // the number of operations needed to get y%(x^(k+1))
        int neg = 0;    // the number of operations needed to get x^(k+1) - y%(x^(k+1))
        int k = 0;  // the power
        int pos2;
        int neg2;
        int cur;
        
        while(target > 0) {
            cur = target % x;   // remainder, 余数
            target /= x;        // quotient, 商
            if(k > 0) {
                pos2 = Math.min(cur * k + pos, (cur + 1) * k + neg);
                neg2 = Math.min((x - cur) * k + pos, (x - cur - 1) * k + neg);
                pos = pos2;
                neg = neg2;
            } else {
                pos = 2 * cur;
                neg = 2 * (x - cur);
            }
            k++;
        }
        return Math.min(pos, k + neg) - 1;
    }
}
__________________________________________________________________________________________________
sample 32072 kb submission
class Solution {
    public int leastOpsExpressTarget(int x, int target) {
        int pos = 0, neg = 0, k = 0;
        while(target > 0) {
            int r = target % x;
            target /= x;
            if(k > 0) {
                int p = Math.min(r*k + pos, (r+1)*k + neg);
                int n = Math.min((x-r)*k + pos, (x-r-1)*k+neg);
                pos = p;
                neg = n;
            } else {
                pos = r * 2;
                neg = (x-r)*2;
            }
            k++;
        }
        return Math.min(pos, k + neg) - 1;
    }
}
__________________________________________________________________________________________________
