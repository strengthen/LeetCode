__________________________________________________________________________________________________
Runtime: 0 ms
Memory Usage: 33.4 MB
class Solution {
    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) {
            return true;
        } else if (tx == ty || sx > tx || sy > ty) { 
            return false;
        } else if (tx > ty) {
            int subtract = Math.max(1, (tx - sx)/ty);
            return reachingPoints(sx, sy, tx - subtract * ty, ty);                 
        } else {
            int subtract = Math.max(1, (ty - sy)/tx);
            return reachingPoints(sx, sy, tx, ty - subtract * tx);
        }
    }
}
__________________________________________________________________________________________________
sample 31820 kb submission
class Solution {
    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == sx && ty == sy) return true;
            if (tx >= ty) {
                if (ty == sy) return (tx - sx) % ty == 0;
                tx = tx % ty;
            } else {
                if (tx == sx) return (ty - sy) % tx == 0;
                ty = ty % tx;
            }
        }
        if (tx == sx && ty == sy) return true;
        return false;
    }
}
__________________________________________________________________________________________________
