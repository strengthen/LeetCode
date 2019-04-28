__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        if (N == 1) {
            return 1;
        }
        int n = sqrt(N * 2);
        if (n * (n + 1) > N * 2) {
            --n;
        }
        const auto factors = get_factors(N);
        int count = 0;
        get_all(factors, 0, 1, n, count);
        return count;
    }
private:
    struct FactorInfo {
        int factor;
        int power;
    };

    vector<FactorInfo> get_factors(int N) {
        vector<FactorInfo> factors{{2, 0}};  // start with a dummy factor 2
        while (N > 1) {
            int factor = get_one_factor(N);
            if (!factors.empty() && factors.back().factor == factor) {
                factors.back().power++;
            } else {
                factors.push_back({factor, 1});
            }
            N /= factor;
        }
        return factors;
    }

    int get_one_factor(int N) {
        int m = sqrt(N);
        for (int i = 2; i <= m; i++) {
            if (N % i == 0) {
                return i;
            }
        }
        return N;
    }

    void get_all(const vector<FactorInfo>& factors, int i, int64_t prod, int n, int& count) {
        if (prod > n) {
            return;
        }
        if (i == factors.size()) {
            ++count;
            return;
        }
        if (factors[i].factor == 2) {
            get_all(factors, i + 1, prod, n, count);
            get_all(factors, i + 1, prod << (factors[i].power + 1), n, count);
            return;
        }
        for (int j = 0; j <= factors[i].power; ++j) {
            get_all(factors, i + 1, prod, n, count);
            prod *= factors[i].factor;
        }
    }
};
__________________________________________________________________________________________________
sample 8352 kb submission
static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int sum = 0, ans = 0;
        for(int i = 1; sum < N; i++) {
            sum += i;
            if (((N-sum) % i) == 0)
                ans++;
        }
        return ans;
    }
};
__________________________________________________________________________________________________
