__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    
    int[] goods = {2, 5, 6, 9};
    int[] valids = {0, 1, 2, 5, 6, 8, 9};
    
    public int rotatedDigits(int N) {
        
        int n = N;
        int digitCount = 0;
        while (n > 0) {
            n /= 10;
            digitCount++;
        }
        
        int count = 0;
        for (int len = 1; len <= digitCount; len++) {
            
            int[] num = new int[digitCount];
            count += getCount(0, 0, false, N, len);
        }
        
        return count;
    }
    
    public int getCount(int num, int i, boolean hasGoodSeen, int N, int len) {
        
        if (i == len && hasGoodSeen) {
            return 1;
        }
        if (num > N) return 0;
        
        int count = 0;
        for (int n: valids) {
            boolean nextGoodSeen = hasGoodSeen || n == 2 || n == 5 || n == 6 || n == 9;
            int nextNum = num * 10 + n;
            if (nextNum == 0) continue;
            if (nextNum > N) break;
            count += getCount (nextNum, i + 1, nextGoodSeen, N, len);
        }
        return count;
    }
}
__________________________________________________________________________________________________
sample 31584 kb submission
class Solution {
    public int rotatedDigits(int N) {
        int ret = 0;
        for (int i=1; i<=N; i++) {
            if (rotateAble(i)) ret++;
        }
        return ret;
    }
    
    private boolean rotateAble(int num) {
        boolean changed = false;
        while (num > 0) {
            int res = num % 10;
            if (res == 3 || res == 4 || res == 7) return false;
            if (res == 2 || res == 5 || res == 6 || res == 9) changed = true;
            num /= 10;
        }
        return changed;
    }
}
__________________________________________________________________________________________________
