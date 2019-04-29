__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
      const int mx = *max_element(A.begin(), A.end());
      const int mn = *min_element(A.begin(), A.end());
      
      if (mx - K <= mn + K)
        return 0;      
      return mx - K - (mn + K);
    }
};

auto ___ = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
__________________________________________________________________________________________________
sample 9864 kb submission
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        if(A.size()<2)
            return 0;
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i = 0;i<A.size();i++){
            if(min>A[i])
                min = A[i];
            if(max<A[i])
                max = A[i];
        }
        if((max-K)<=(min+K))
            return 0;
        else
            return (max-K)-(min+K);
    }
};
__________________________________________________________________________________________________
