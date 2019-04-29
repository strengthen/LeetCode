__________________________________________________________________________________________________
sample 24 ms submission
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        if (A.empty()) return 0;
    	int n = A.size();
        vector<int> leftMin(n, -1), rightMax(n, -1);

        leftMin[0] = A[0];
        for(int i=1; i<n; i++){
        	leftMin[i] = min(leftMin[i-1], A[i]);
        }
        rightMax[n-1] = A[n-1];
        for(int i=n-2; i>=0; i--){
        	rightMax[i] = max(rightMax[i+1], A[i]);
        }

        int res = 0;
        int i=0, j=1;
        while(i<n && j<n){
            if(leftMin[i]<=rightMax[j]){
                res = max(res, j-i);
                j++;
            }else{
                i++;
            }    
        }

        return res;
    }
};
__________________________________________________________________________________________________
sample 12792 kb submission
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int len = A.size() - 1;
        int i = 0;
        int j = len;
        int currentL = 0;
        while (len - i > currentL)
        {
            int a = A[i];
            while (j - i > currentL && A[j] < a)
                --j;
            
            if (j - i > currentL)
                currentL = j - i;
           
            j = len;
            ++i;
            while (i < len && A[i] >= a)
            {
                ++i;
                if (j - i <= currentL)
                    return currentL;
            }
        }
        
        return currentL;
    }
};
__________________________________________________________________________________________________
