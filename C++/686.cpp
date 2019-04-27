__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
private:
    inline int mod(int a, int b) {
        int r = a % b;
        if (r < 0)
            r += b;
        return r;
    }
    
    inline int pow(int a, int b, int q) {
        int p = 1;
        while (b--) {
            p = mod(p * a, q);
        }
        return p;
    }
    
    void computePrefixFn(const string& s, vector<int>& pf) {
        int k = 0;
        pf[0] = 0;
        for (int i = 1; i < s.length(); i++) {
            while (k > 0 &&  s[k] != s[i])
                k = pf[k-1];
            if (s[k] == s[i])
                k++;
            pf[i] = k;
        }
    }
    
public:
    int repeatedStringMatch1(string A, string B) {
        int alen = A.length();
        int blen = B.length();
        int times = ceil(blen * 1.0 / alen);
        string temp;
        for (int t = 0; t < times; t++)
            temp += A;
        if (temp.find(B) != string::npos)
            return times;
        temp += A;
        if (temp.find(B) != string::npos)
            return times + 1;
        return -1;
    }
    int repeatedStringMatch2(string A, string B) {
        int alen = A.length();
        int blen = B.length();
        
        for (int i = 0; i < alen; i++) {
            int j;
            for (j = 0; j < blen; j++) {
                if (B[j] != A[(i+j) % alen])
                    break;
            }
            if (j == blen) {
                int minLen = i + j;
                return (minLen / alen) + (minLen % alen ? 1 : 0);
            }
        }
        
        return -1;
    }
    int repeatedStringMatch3(string A, string B) {
        int alen = A.length();
        int blen = B.length();
        
        int ahash = 0, bhash = 0;
        const int d = 256;
        const int q = 101;
    
        int h = pow(d, blen-1, q);
        for (int i = 0; i < blen; i++) {
            bhash = mod((d * bhash) + B[i], q);
            ahash = mod((d * ahash) + A[i % alen], q);
        }
        
        for (int i = 0; i < alen; i++) {
            if (ahash == bhash) {
                int j;
                for (j = 0; j < blen; j++) {
                    if (B[j] != A[(i+j) % alen])
                        break;
                }
                if (j == blen) {
                    int minLen = i + j;
                    return (minLen / alen) + (minLen % alen ? 1 : 0);
                }
            }
            ahash = mod(d * (ahash - h * A[i]) + A[(i+blen) % alen], q);
        }
        
        return -1;
    }
    int repeatedStringMatch(string A, string B) {
        int alen = A.length();
        int blen = B.length();
        int maxTimes = ceil(blen * 1.0 / alen) + 1;
        
        vector<int> prefixFn(blen);
        computePrefixFn(B, prefixFn);
        
        int q = 0;
        for (int i = 0; i < maxTimes * alen; i++) {
            while (q > 0 && B[q] != A[i % alen])
                q = prefixFn[q-1];
            if (B[q] == A[i % alen]) {
                q++;
                if (q == blen) {
                    i++;
                    return (i / alen) + (i % alen ? 1 : 0);
                }
            }
        }
        
        return -1;
    }
};
__________________________________________________________________________________________________
sample 8828 kb submission
class Solution {
public:

int repeatedStringMatch(string A, string B) {
	
	// counter for number of itters of A
	
	int aStartIdx = 0;
	// so long as index is < length of A
	while(aStartIdx < A.length())
	{
		
		// find first instance of B[0]
		int counter = 1;
		
		if(A[aStartIdx]==B[0])
		{
			// check if can accur
			int bIdx = 0;
			int aIdx = aStartIdx;
			while(bIdx < B.length() && A[aIdx] == B[bIdx]) // while we are still within bIdx and letters are matching
			{
				if(bIdx == B.length()-1 && A[aIdx]==B[bIdx]) return counter;
				if(aIdx == A.length()-1) 
				{
					aIdx = 0;
					bIdx++;
					counter++;
				}
				else {
					bIdx++;
					aIdx++;
				}
				
			}
			// check if last letter is reached and still matching to return counter
			
			
		}
		aStartIdx++;
		
	}
	// no possible so return -1
	return -1;
}
};
__________________________________________________________________________________________________
