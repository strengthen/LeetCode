__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int binaryGap(int N) {
        int res = 0;
        for (int d = - 32; N > 0; N /= 2, d++){
            if (N % 2 == 1){
                res = Math.max(res, d);
                d = 0;
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 31976 kb submission
class Solution {
    public int binaryGap(int N) {
        int curPos = 0, lastOnePos = -1, maxDis = 0;
        
        while (N > 0) {
            if (N % 2 == 1) {
                if (lastOnePos != -1) {
                    maxDis = Math.max(maxDis, curPos - lastOnePos);
                }
                lastOnePos = curPos;
            }
            
            N /= 2;
            curPos++;
        }
        
        return maxDis;
    }
}
__________________________________________________________________________________________________
