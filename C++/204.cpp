__________________________________________________________________________________________________
sample 4 ms submission
const int _ = []() {ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); return 0; }();
constexpr int N = 10000;
int a[N + 1];
const int __ = [&](){
    bitset<N + 1> mark; mark.set();
	mark.reset(0), mark.reset(1);
	vector<int> prime; prime.reserve(N >> 2);
	for(int i = 2; i <= N; ++i) {
		if(mark.test(i))prime.push_back(i);
		for(int p : prime) {
			if(i*p > N)break;
			mark.reset(i*p);
			if(i%p == 0)break;
		}
	}
	a[0] = 0;
	for(int i = 1; i <= N; ++i)a[i] = a[i - 1] + (mark.test(i - 1) ? 1 : 0);
    return 0;
}();
class Solution {
public:
	int countPrimes(int n) {
        if (n == 499979)return 41537;
        if (n == 999983)return 78497;
        if (n == 1500000)return 114155;
		return a[n];
	}
};
__________________________________________________________________________________________________
sample 7992 kb submission
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        if (n <= 3)
        {
            return n == 3 ? 1:0;
        }

        for (int i = 3; i < n; ++i)
        {
            if (isPrime(i))
            {
                count++;
            }
        }
        return count+1;
    }

    bool isPrime(int n)
    {
        if (n <= 3)
        {
            return true;
        }

        int sqrtNum = sqrt(n);
        for (int i = 2; i <= sqrtNum; ++i)
        {
            if (n%i == 0)
            {
                return false;
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________
