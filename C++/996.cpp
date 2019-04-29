__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    void print(const vector<int>& vec) {
        for (int a : vec) cout << a << ' ';
        cout << '\n';
    }
    int N;
    int count;
    unordered_map<int, int> B;
    unordered_map<int, vector<int> > squares;
    vector<int> vec;
    void test() {
        //print(vec);
        if (vec.size() == N) { count++; return; }
        for (int cand : squares[vec.back()]) {
            if (B[cand] == 0) continue;
            B[cand]--;
            vec.push_back(cand);
            test();
            vec.pop_back();
            B[cand]++;
        }
    }
    bool is_square(const int a) {
        const int r = (int)sqrt(a);
        return a == r * r;
    }
public:
    int numSquarefulPerms(vector<int>& A) {
        N = A.size();
        count = 0;
        for (const int& a : A) B[a]++;
        for (auto it : B) {
            for (auto it_ : B) {
                if (it.first <= it_.first) continue;
                if (is_square(it.first + it_.first)) {
                    //cout << "find pair " << it.first << " and " << it_.first << '\n';
                    squares[it.first].push_back(it_.first);
                    squares[it_.first].push_back(it.first);
                }
            }
            if (is_square(it.first * 2)) {
                //cout << "find pair " << it.first << " and " << it.first << '\n';
                squares[it.first].push_back(it.first);
            }
        }
        for (auto it : B) {
            B[it.first]--;
            vec.push_back(it.first);
            test();
            vec.pop_back();
            B[it.first]++;
        }
        return count;
    }
};
__________________________________________________________________________________________________
sample 8528 kb submission
class Solution {
public:
    int numSquarefulPerms(vector<int> &A) {
        preProcess(A);
        dfs(A, 0, 0);
        return result;
    }

    void dfs(vector<int> &A, int depth, int curr) {
        if (depth == A.size()) {
            result++; return;
        }
        int same = -1;
        for (int i = 0; i < A.size(); i++) {
            if (depth > 0 && !isSquare[curr][i]) {
                continue;
            }
            if (A[i] != same && !isVisited[i]) {
                isVisited[i] = 1;
                dfs(A, depth + 1, i);
                isVisited[i] = 0;
                same = A[i];
            }
        }
    }


private:
    static const int MAXN = 14;
    int isSquare[MAXN][MAXN];
    int isVisited[MAXN];
    int result;

    void preProcess(vector<int> &A) {
        sort(A.begin(), A.end());
        memset(isSquare, 0x00, MAXN * MAXN * sizeof(int));
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < i; j++) {
                int y = A[i] + A[j];
                int x = int(sqrt(double(y)));
                if (x * x == y) {
                    isSquare[i][j] = 1;
                    isSquare[j][i] = 1;
                }
            }
        }
        memset(isVisited, 0x00, MAXN * sizeof(int));
        result = 0;
    }
};
__________________________________________________________________________________________________
