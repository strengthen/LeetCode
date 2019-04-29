__________________________________________________________________________________________________
sample 8 ms submission
auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();


class Solution {
public:
    int minDeletionSize(const vector<string>& a) {
        int arrLen = int(a.size());
        if (arrLen <= 1) {
            return 0;
        }
        int strLen = int(a[0].size());
        if (strLen == 0) {
            return 0;
        }
        std::unordered_set<int> deletedIndices;
        foo(deletedIndices, a, strLen, 0, arrLen - 1, 0);
        return int(deletedIndices.size());
    }
private:
    void foo(std::unordered_set<int> & deletedIndices, const vector<string>& a, int strLen, int arrFromIndex, int arrToIndex, int strIndex) {
        while (strIndex < strLen) {
            char lastValue = 0;
            int i = arrFromIndex;
            while (i <= arrToIndex) {
                char curValue = a[i][strIndex];
                if (lastValue < curValue) {
                    ++i;
                } else if (lastValue > curValue) {
                    deletedIndices.insert(strIndex);
                    do {
                        ++strIndex;
                    } while (deletedIndices.find(strIndex) != deletedIndices.end());
                    break;
                } else {
                    int nextFromIndex = i - 1;
                    int nextToIndex = i + 1;
                    while (nextToIndex < arrToIndex && a[nextToIndex][strIndex] == lastValue) {
                        ++nextToIndex;
                    }
                    i = nextToIndex;
                    int nextStrIndex = strIndex;
                    do {
                        ++nextStrIndex;
                    } while (deletedIndices.find(nextStrIndex) != deletedIndices.end());
                    foo(deletedIndices, a, strLen, nextFromIndex, nextToIndex - 1, nextStrIndex);
                }
                lastValue = curValue;
            }
            if (i > arrToIndex) {
                return;
            }
        }
    }
};
__________________________________________________________________________________________________
sample 10072 kb submission
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int N = (int)A.size(), M = (int)A[0].size();
        int row, col;
        vector<bool>sorted(N,false);
        int res = 0;
        for(col = 0; col < M; col++) {
            for(row = 0; row < N -1; row ++) {
                if(!sorted[row] && A[row][col] > A[row+1][col]){// not sorted, may just =, cannot >, can =
                    res++;
                    break;
                }
            }
            if(row != N - 1) continue;//because res++
            for(row = 0; row < N-1 ;row++) { // already < , so following col = or > is OK
                if(A[row][col] < A[row+1][col])
                    sorted[row] = true;
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
