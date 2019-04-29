__________________________________________________________________________________________________
sample 4 ms submission
class Solution
{
public:
    int numDupDigitsAtMostN(int N)
    {
        {
            vector<int> L;
            for (int i = N + 1; i > 0; i /= 10)
            {
                L.insert(L.begin(), i % 10);
            }

            int res = 0, n = L.size();
            for (int i = 1; i < n; ++i)
                res += 9 * A(9, i - 1);

            unordered_set<int> seen;
            for (int i = 0; i < n; ++i)
            {
                int cnt = 0;
                int j = i > 0 ? 0 : 1;
                for (; j < L[i]; ++j)
                    cnt += static_cast<int>(!seen.count(j));
                res += cnt * A(9 - i, n - i - 1);
                if (seen.count(L[i]))
                    break;
                seen.insert(L[i]);
            }
            return N - res;
        }
    }

private:
    int
    A(int m, int n)
    {
        return n == 0 ? 1 : A(m, n - 1) * (m - n + 1);
    };
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
private:
    int numOfLength(int k, int len, int preSize) {
        int res = k;
        int i;
        for (i = 1; i < len; i++) {
            res *= 10 - i - preSize;        
        }
        return res;
    }
    
    int pureNumOfLength(int len) {
        int res = 9;
        for (int i = 1; i < len; i++) {
            res *= 10 - i;
        }
        return res;
    }
public:
    int numDupDigitsAtMostN(int N) {
        if (N < 10) return 0;
        int noRepeatedSize = 0;
        vector<int> digits;
        for (int i = N + 1; i > 0; i /= 10) {
            digits.push_back(i % 10);
        }
        reverse(digits.begin(), digits.end());
        
        unordered_set<int> prefixs;
        
        
        int size = digits.size();
        for (int i = 1; i < size; i++) {
            noRepeatedSize += pureNumOfLength(i); 
        }
            
        for (int i = 0; i < size; i++) {
            int digit = digits[i];
            int k = 0;
            for (int j = i == 0 ? 1 : 0; j < digit; j++) {
                if (prefixs.find(j) == prefixs.end()) {
                    k++;
                }
            }
            noRepeatedSize += numOfLength(k, size - i, prefixs.size());
            if (prefixs.find(digit) != prefixs.end()) {
                break;
            }
            prefixs.insert(digit);
        }
        return N  - noRepeatedSize;
    }
};
__________________________________________________________________________________________________
