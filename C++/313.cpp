__________________________________________________________________________________________________
sample 24 ms submission
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ans(n), values(primes), ptr(primes.size(), 0);
        ans[0] = 1;
        int last = 1, min_value, cnt = 1;
        while(cnt < n) {
            min_value = INT_MAX;
            for(int i = 0; i < primes.size(); i++) {
                if(values[i] <= last) {
                    values[i] = primes[i] * ans[++ptr[i]];
                }
                if(min_value > values[i]) {
                    min_value = values[i];
                }
            }
            ans[cnt++] = last = min_value;
        }
        return ans.back();
    }
};
__________________________________________________________________________________________________
sample 9124 kb submission
typedef long long ll;

class Solution {
public:
    	int nthSuperUglyNumber(int n, vector<int>& primes) {
        	vector<int> ptrs(primes.size(), 0), ugly(n, INT_MAX);
		ugly[0] = 1;
		for (int i = 1; i < n; ++i) {
	for (int j = 0; j < primes.size(); ++j) 
		ugly[i] = min(ugly[i], ugly[ptrs[j]] * primes[j]);
	for (int j = 0; j < primes.size(); ++j) 
		ptrs[j] += (ugly[i] == ugly[ptrs[j]] * primes[j]);
}
return ugly[n - 1];
    	}
};
__________________________________________________________________________________________________
