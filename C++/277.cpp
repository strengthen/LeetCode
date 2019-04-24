__________________________________________________________________________________________________
class Solution {
public:
    int findCelebrity(int n) {
        vector<bool> candidate(n, true);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (candidate[i] && i != j) {
                    if (knows(i, j) || !knows(j, i)) {
                        candidate[i] = false;
                        break;
                    } else {
                        candidate[j] = false;
                    }
                }
            }
            if (candidate[i]) return i;
        }
        return -1;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int findCelebrity(int n) {
        for (int i = 0, j = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (i != j && (knows(i, j) || !knows(j, i))) break;
            }
            if (j == n) return i;
        }
        return -1;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int findCelebrity(int n) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (knows(res, i)) res = i;
        }
        for (int i = 0; i < n; ++i) {
            if (res != i && (knows(res, i) || !knows(i, res))) return -1;
        }
        return res;
    }
};