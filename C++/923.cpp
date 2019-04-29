__________________________________________________________________________________________________
sample 4 ms submission
struct Solution {
    static int threeSumMulti(vector<int>& A, int target) noexcept {
        long total = 0;
        long count[101] = { };
        int max_n = 0;
        for (int n : A) ++count[n], max_n = max(max_n, n);
        for (int i = 0; i <= max_n; ++i) {
            if (count[i] == 0) continue;
            const int m = target - 2 * i;
            if (m == i) total += count[i] * (count[i] - 1) * (count[i] - 2) / 6;
            else if (m > i && m <= 100) total += count[i] * (count[i] - 1) * count[m] / 2;
            for (int j = i + 1; j <= min(max_n, (target - i) / 2); ++j) {
                if (count[j] == 0) continue;
                if (i + j > target) break;
                const int k = target - i - j;
                if (k < j) break;
                if (k == j) total += count[i] * count[j] * (count[j] - 1) / 2;
                else if (k <= 100) total += count[i] * count[j] * count[k];
            }
            total = total % 1000000007;
        }
        return total;
    }
};

static const auto _ = []() noexcept { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
__________________________________________________________________________________________________
sample 9116 kb submission
class Solution {
public:
    int threeSumMulti(vector<int>& num, int target) {
        int res = 0;
        int cnt = num.size();
        if(cnt < 3) {
            return res;
        }
        int mod = 1e9 + 7;
        std::sort(num.begin(), num.end());
        for(int i = 0; i <= cnt-3; ++i) {
            int start = i+1;
            int end = cnt-1;
            while(start < end) {
                int sum = num[i] + num[start] + num[end];
                if(sum < target) {
                    ++start;
                } else if(sum > target) {
                    --end;
                } else {
                    int a = num[start], b = num[end];
                    int small = 0, big = 0;
                    while(start <= end && num[start] == a) {
                        ++start;
                        ++small;
                    }
                    if(start > end)
                    {
                        res = res % mod + small *(small - 1) / 2 % mod;
                    }
                    else
                    {
                        while(start <= end && num[end] == b) {
                            --end;
                            ++big;
                        } 
                        res = res % mod + small * big % mod;
                    }
                }
            }
        }       
        return res % mod;
    }
};
__________________________________________________________________________________________________
