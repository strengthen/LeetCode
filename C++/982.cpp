__________________________________________________________________________________________________
sample 16 ms submission

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int countTriplets(vector<int>& A) {
        int nbits = 0;
        
        int maximum = *max_element(A.begin(), A.end());
        while (maximum) {
            maximum >>= 1;
            ++nbits;
        }
        
        int limit = 1 << nbits;
        int counts[limit] = {0};
        
        for (auto a : A) for (auto b : A)
            ++counts[a & b];
        
        int answer = 0;
        for (auto i : A) for (int j = 0; j < limit;)
            if (const int k = i & j; k == 0) 
                answer += counts[j++];
            else
                j += k;
        
        return answer;
    }
};
__________________________________________________________________________________________________
sample 8608 kb submission
class Solution {
public:
    
    int count(int i, int j, int k) {
    	if (i == j && j == k) {
    		return 1;
    	} else if (i == j || j == k || i == k) {
    		return 3;
    	}
    	return 3*2;
    }
    
    int countTriplets(vector<int>& A) {
    	int cnt = 0;
    	for (int i = 0; i < A.size(); ++i) {
    		if (A[i] == 0) {
	    		cnt += 1 + 6 * i + 3 * i * (i - 1);
    			continue;
    		}
	    	for (int j = 0; j <= i; ++j) {
	    		int t = A[i] & A[j];
	    		if (t == 0) {
					cnt += 3 + 6 * j;
		    		continue;
	    		}
		    	for (int k = 0; k <= j; ++k) {
		    		if ((t & A[k]) == 0) {
		    			cnt += count(i,j,k);
		    		}
		    	}
	    	}
        }
        return cnt;
    }
};
__________________________________________________________________________________________________
