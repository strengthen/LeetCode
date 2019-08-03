__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int superEggDrop(int K, int N) {
        int lo = 1, hi = N;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (f(mi, K, N) < N)
                lo = mi + 1;
            else
                hi = mi;
        }

        return lo;
    }

    public int f(int x, int K, int N) {
        int ans = 0, r = 1;
        for (int i = 1; i <= K; ++i) {
            r *= x-i+1;
            r /= i;
            ans += r;
            if (ans >= N) break;
        }
        return ans;
    }
}
__________________________________________________________________________________________________
sample 31828 kb submission
class Solution {
    public int superEggDrop(int K, int N) {
        int floors[] = new int[K+1];
        int moves = 0;
        for(; floors[K] < N; moves++){
            for(int i = K; i > 0; i--){
                floors[i] = 1+floors[i-1]+floors[i];
            }
        }
        return moves;
    }
}
__________________________________________________________________________________________________
