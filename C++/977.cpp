__________________________________________________________________________________________________
sample 80 ms submission
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        
        int left, right;
        
        auto it = lower_bound(A.begin(), A.end(), 0);
        if( it == A.end())
        {
            left = n-1;
            right = n;
        }
        else if( it == A.begin())
        {
            left = -1;
            right = 0;
        }
        else
        {
            right = it - A.begin();
            left = right-1;
            
        }        
        
        vector<int> result(n);
        for( int i=0; i < n; i++)
        {
            int idx = right;
            if( left < 0)
            {
                idx = right++;
            }
            else if(right >= n)
            {
                idx = left--;
            }
                
            else if( -A[left] <= A[right])
                idx = left--;
            else
                idx = right++;
            
            result[i] = A[idx] * A[idx];
                
        }
        
        return result;
    }
};

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
__________________________________________________________________________________________________
sample 13392 kb submission
auto __=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(int i=0;i<A.size();i++)
        {
            A[i]=A[i]*A[i];
        }
        sort(A.begin(),A.end());
        return A;
        
    }
};
__________________________________________________________________________________________________
