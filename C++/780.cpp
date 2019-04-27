__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx > ty) {
                if (ty == sy) return (tx - sx) % ty == 0;
                tx %= ty;
            }
            else {
                if (tx == sx) return (ty - sy) % tx == 0;
                else ty %= tx;
            }
        }
        return tx == sx && ty == sy;
    }
};
__________________________________________________________________________________________________
sample 8968 kb submission
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx>tx || sy>ty) return false;    
        if ((tx-sx)%sy==0 && sy==ty) return true;
        if ((ty-sy)%sx==0 && sx==tx) return true;
        return reachingPoints (sx, sy, tx%ty, ty%tx);
    }
};
__________________________________________________________________________________________________
