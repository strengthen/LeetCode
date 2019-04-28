__________________________________________________________________________________________________
sample 24 ms submission
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int64_t quickMod(int64_t a, int64_t b)
{
	int64_t ans = 1;
	while (b)
	{
 
		if (b % 2 == 1)
			ans = (ans * a) % 1000000007;
		b /= 2;
		a = (a * a) % 1000000007;
	}
	return ans;
}

#define MAGIC 1000

class Solution {
public:
	int sumSubseqWidths(std::vector<int>& A) {
        int N = A.size();
        int M = (N+3)/4;
		int64_t res = 0;
        bool flag = N>MAGIC;
        
        uint16_t count[20001];
        if(flag){
            memset(count,0,20001*sizeof(uint16_t));
            for(int i:A){
                count[i]++;
            }
        }else{
            std::sort(A.begin(),A.end());
        }
        
        
		std::vector<uint64_t> dict(4*M);
        dict[0] = 1;
	    dict[M] = quickMod(2, M);
	    dict[2*M] = quickMod(2, 2*M);
	    dict[3*M] = quickMod(2, 3*M);
	    for (int i = 1; i < M; i++) {
		    dict[i] = 2 * dict[i - 1]>1000000007 ? 2 * dict[i - 1] - 1000000007 : 2 * dict[i - 1];
		    dict[M+i] = 2 * dict[M + i-1]>1000000007 ? 2 * dict[M + i -1] - 1000000007 : 2 * dict[M + i - 1];
		    dict[2*M+i] = 2 * dict[2 * M + i - 1]>1000000007 ? 2 * dict[2 * M + i - 1] - 1000000007 : 2 * dict[2 * M + i - 1];
		    dict[3*M+i] = 2 * dict[3 * M + i - 1]>1000000007 ? 2 * dict[3 * M + i - 1] - 1000000007 : 2 * dict[3 * M + i - 1];
	    }
        
        

        
        
        if(flag){
            int big = 20000;
            int small = 1;
		    for (int i = 0; i<N/2; i++) {
                while(!count[big]) big--;
                while(!count[small]) small++;
                        
                res += (big-small)*(dict[N-1-i]-dict[i]);
            
                count[big]--;
                count[small]--;
            }
		}else{
  		    for (int i = 0; i<N/2; i++) {           
                res += (A[N-1-i]-A[i])*(dict[N-1-i]-dict[i]);
            }          
        }
        res %= 1000000007;
        if(res<0) res += 1000000007;
		return res;
	}
};
__________________________________________________________________________________________________
sample 11548 kb submission
class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end());
        int l = 0, r = A.size()-1;
        int lsum = 0, rsum = 0;
        long long d = 1, ans = 0, mod = 1000000007;
        while(l < A.size()){
            lsum += A[l++];
            rsum += A[r--];
            ans += (rsum-lsum)*d;
            ans %= mod;
            d = d * 2 % mod;
        }
        return ans;
    }
};
__________________________________________________________________________________________________
