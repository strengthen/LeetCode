__________________________________________________________________________________________________
sample 16 ms submission
int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int result = 1 ;
        int maxLen = 0 ;
        uint64_t totalNum = 0 ;
        for ( int i = 0 ; i < piles.size() ; ++i ) {
            maxLen = max( maxLen, piles.at( i ) ) ;
            totalNum += piles.at( i ) ;
        } // for
        
        uint64_t time = 0 ;
        
        for ( int i = ((totalNum / H) == 0) ? 1 : (totalNum / H) ; i <= maxLen ; ++i ) {
            for ( int p = 0 ; p < piles.size() ; ++ p ) {
                time += piles.at( p ) / i ; 
                if ( piles.at( p ) % i != 0 )
                    time += 1 ;
            } // for
            
            if( time <= H )
                return i ;
            else 
                time = 0 ;
        } // for 
        
        return 0 ;
    }
};
__________________________________________________________________________________________________
sample 10612 kb submission
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
 	int left = 1;
	int right = INT_MAX;
	
	while (left < right) {
		int mid = left + (right - left) / 2;
		int total = 0;

		for (int i : piles) {
			total += ceil((i +mid-1)/ mid);
		}
		if (total > H)
			left = mid+1;
		else
			right = mid;
	}

	return left;
    }
};
__________________________________________________________________________________________________
