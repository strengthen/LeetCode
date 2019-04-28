__________________________________________________________________________________________________
sample 56 ms submission
class Solution {
    vector<vector<int>> spiralImitate (int R, int C, int r0, int c0) {
        vector<vector<int>> ret;
        /***
         * direction of the move:
         * east, down, west, up
         */
        int dir = 0;
        /* boundary of visited cells, inclusive */
        int rlow = r0, rhigh = r0;
        int clow = c0, chigh = c0;
        
        while (!(rlow == -1 && rhigh == R &&
                 clow == -1 && chigh == C)) {
            dir %= 4;
            switch (dir) {
                /* move east */
                case 0:
                    for (int j = max (0, clow); rlow > -1 && j <= min(chigh, C - 1); j++) {
                        ret.push_back ({rlow, j});
                    }
                    
                    /* chigh at most C */
                    if (chigh < C) {
                        chigh++;
                    }
                    dir++;
                    break;
                case 1:
                    for (int i = max (0, rlow); chigh < C && i <= min(rhigh, R - 1); i++) {
                        ret.push_back ({i, chigh});
                    }
                    
                    if (rhigh < R) {
                        rhigh++;
                    }
                    dir++;
                    break;
                case 2:
                    for (int j = min (C - 1, chigh); rhigh < R && j >= max(clow, 0); j--) {
                        ret.push_back ({rhigh, j});
                    }
                    
                    if (clow > -1) {
                        clow--;
                    }
                    dir++;
                    break;
                case 3:
                    for (int i = min (rhigh, R - 1); clow > -1 && i >= max(0, rlow); i--) {
                        ret.push_back ({i, clow});
                    }
                    
                    if (rlow > -1) {
                        rlow--;
                    }
                    dir++;
                    break;
            }
        }
        
        return ret;
    }
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        return spiralImitate (R, C, r0, c0);
    }
};
__________________________________________________________________________________________________
sample 12592 kb submission
static int fast_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int dir = 0, steps = 1, dist = 1, count = C * R;
        vector<vector<int>> spiral;
        spiral.reserve(count);
        while (spiral.size() < count) {
            if (r0 >= 0 && 
                r0 < R  && 
                c0 >= 0 && 
                c0 < C) {
                spiral.emplace_back(initializer_list<int>{r0, c0});
            }
            if      (dir == 0) ++c0;
            else if (dir == 1) ++r0;
            else if (dir == 2) --c0;
            else               --r0;
            --steps;
            if (steps == 0) {
                if (dir % 2 == 1) ++dist;
                steps = dist;
                ++dir;
                if (dir == 4) dir = 0;
            }
        }
        return spiral;
    }
};
__________________________________________________________________________________________________
