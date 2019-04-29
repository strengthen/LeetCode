__________________________________________________________________________________________________
sample 4 ms submission
int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort( A.begin(), A.end() ) ;
        
        // for ( int i = 0 ; i<A.size() ; ++i )
        //     cout << A[ i ] << endl ;
        for ( int i = 0 ; i < A.size() && K > 0 ; ++i ) {
            --K ;
            if ( A[ i ] > 0 ) {
                A[ i ] *= -1 ;
                --i ;
            } // if
            else if ( A[ i ] == 0 ) {
                --i ;
            } // else if
            else {
                A[ i ] *= -1 ;
                if ( i <= A.size() - 2 && A[ i + 1 ] > 0 && A[ i + 1 ] > A[ i ] && K > 0 )
                    --i ;
            } // else 
        } // for
        
        return accumulate( A.begin(), A.end(), 0 ) ;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        std::sort(A.begin(), A.end());
        int res = 0;
        int minAbs = INT_MAX;
        for (int i = 0 ; i < A.size(); ++i) {
            if (A[i] < 0 && K > 0) {
                res -= A[i];
                --K;
            } else if (K == 0) {
                res += A[i];
            } else { // A[i] > 0 && K > 0
                res += A[i];
                if ((K & 0x1)) {
                    res -= 2 * min(abs(A[i]), i > 0 ? abs(A[i-1]) : INT_MAX);
                    K = 0;
                }
            }
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
