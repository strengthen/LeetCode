__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int preimageSizeFZF(int K) {
        long long l = K, r = 5LL * (long long) K;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long k = count(mid);
            // cout<<"count: "<<mid<<"="<<k<<endl;
            if (k == K) {
                return 5;
            } else if (k < K) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return 0;
    }

    long long count(long long N) {
        long long res = 0;
        while (N) {
            N /= 5;
            res += N;
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 8248 kb submission
class Solution {
private:
    bool search(int target, int l, int r, int (*a)(int n)) {
        if (a(l) == target || a(r) == target)
            return true;
        int m;
        while (l + 1 < r) {
            m = l + (r - l)/2;
            if (a(m) == target)
                return true;
            if (a(m) < target)
                l = m;
            else
                r = m;
        }
        return false;
    }
     
public:
    int preimageSizeFZF(int K) {
        auto f = [](int n){
            int result = n;
            while (n > 0) {
                result += n/5;
                n /= 5;
            }
            return result;             
        };
        return (search(K, 0, K, f))? 5 : 0;
    }
};
__________________________________________________________________________________________________
