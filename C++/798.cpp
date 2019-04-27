__________________________________________________________________________________________________
sample 12 ms submission
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int bestRotation(vector<int>& A) {
        const int n = A.size();
        
        // Sum of differencials of point contribution of all values with a shift.
        // Give one more room to reduce overflow checking.
        int differencials[n + 1] = {0};
        
        for (int i = 0; i < n; ) {
            const int v = A[i];
            if (v > i) {
                differencials[++i]++;
                differencials[i + n - v]--;
            } else {
                differencials[0]++;
                differencials[++i - v]--;
                differencials[i]++;
            }
        }
            
        int highest_score = differencials[0];
        int highest_score_position = 0;
        
        for (int i = 1, score = highest_score; i < n; i++) {
            const int d = differencials[i];
            if (d == 0) continue;
            score += d;
            if (d > 0 && score > highest_score) {
                highest_score = score;
                highest_score_position = i;
            }
        }
            
        return highest_score_position;
    }
};
__________________________________________________________________________________________________
sample 10448 kb submission
class Solution {
public:
    int bestRotation(vector<int>& A) {
        // Lose point
        // (i - A[i] + N) % N is the value of K making A[i]'s index just equal to A[i].
        // For example, If A[6] = 1, then K = (6 - A[6]) % 6 = 5 making A[6] to index 1 of new array.
        // So when K=5, we get this point for A[6]
        // Then if K is bigger when K = (i - A[i] + 1) % N, we start to lose this point, making our score -= 1
        // All I have done is record the value of K for all A[i] where we will lose points.
        int N = A.size();
        int change[N] = {0};
        for (int i = 0; i < N; ++i) change[(i - A[i] + 1 + N) % N] -= 1;
        for (int i = 1; i < N; ++i) change[i] += change[i - 1] + 1;
        return distance(change, max_element(change, change + N));
    }
};
__________________________________________________________________________________________________
