__________________________________________________________________________________________________
sample 32 ms submission
static int x = []{cin.tie(0); ios::sync_with_stdio(0); return 0;}();

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) 
    {
        if(!A.size()) return 0;
        bool greater = false;
        int currentSize = 1;
        int longestSize = 0;
        for(int i = 0; i < A.size()-1; i++)
        {
            if(greater && A[i] > A[i + 1])
            {
                currentSize++;
            }
            else if(!greater && A[i] < A[i + 1])
            {
                currentSize++;
            }
            else
            {
                greater = A[i] > A[i + 1];
                if(currentSize > longestSize)
                {
                    longestSize = currentSize;
                }
                currentSize = (A[i] == A[i+1]) ? 1 : 2;
            }
            greater = !greater;
        }
        if(currentSize > longestSize)
        {
            longestSize = currentSize;
        }
        return longestSize;
    }
};
__________________________________________________________________________________________________
sample 13576 kb submission
class Solution {
public:
    
   
    int maxTurbulenceSize(vector<int>& A) {
        int i = 0;
        int n = A.size();
        if (!n) {
            return 0;
        }
        int res = 1;
        int expect = -1;
        int len = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (A[i] == A[i + 1]) {
                expect = -1;
                len = 0;
                continue;
            }
            int curr_expect = A[i] > A[i + 1];
            if (expect == -1 || expect != curr_expect) {
                expect = curr_expect;
                len = 2;
            }
            else if (expect == curr_expect) {
                ++len;
            }
            expect = 1 - expect;
            res = max(res, len);
        }
        return res;
    }
};
__________________________________________________________________________________________________
