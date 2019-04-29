__________________________________________________________________________________________________
sample 24 ms submission
static int x=[](){ios::sync_with_stdio(false); cin.tie(NULL); return 0;}();

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
	    // Count no of 1's in the given array
        int countNumberOfOnes = 0;
        for(int c: A)
            if(c == 1)                  
                countNumberOfOnes++;
								
	    // If no 1 is found, that means we can return ans as {0, size-1}
        if(countNumberOfOnes == 0)      
            return {0, A.size()-1};
						
        // If no of 1's is not a multiple of 3, then we can never find a possible partition since
        // there will be atkeast one partition that will have different no of 1's and hence
        // different binary representation
        // For example,
        // Given :
        // 0000110  110  110 
        //       |  |    |
        //       i       j
        // Total no of ones = 6
        // 0000110         110      110
        //     |           |        |
        //     start       mid      end
        // Match starting from first 1, and putting 2 more pointers by skipping k 1's
        
        if(countNumberOfOnes % 3 != 0)            
            return {-1, -1};
						
        // find size of each partition
        int k = countNumberOfOnes/3;
        int i;
        
        // find the first 1 in the array
        for(i=0;i<A.size(); i++)
            if(A[i] == 1)
                break;
        int start = i;
        
        // find (k+1)th 1 in the array
        int count1 = 0;
        for(i=0;i<A.size(); i++)
        {
            if(A[i] == 1)
                count1++;
            if(count1 == k + 1)
                break;
        }
        int mid = i;
        
        //find (2*k +1)th 1 in the array
        count1= 0;
        for(i=0;i<A.size(); i++)
        {
            if(A[i] == 1)
                count1++;
            if(count1 == 2*k + 1)
                break;
        }
        int end = i;
        
        // Match all values till the end of the array
        while(end< A.size() && A[start] == A[mid] && A[mid] == A[end])
        {
            start++; mid++; end++;
        }
        
        // Return appropriate values if all the values have matched till the end
        if(end == A.size()) 
            return {start-1, mid};
        
        // otherwise, no such indices found
        return {-1, -1};
    }
};
__________________________________________________________________________________________________
sample 12680 kb submission
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int cnt = 0, i, a, b, c, val = 0;
        for (auto x : A)
            cnt += x;
        if (cnt == 0)
            return {0, 2};
        if (cnt % 3) // number of 1's are not splittable
            return {-1,-1};
        for (i = A.size() - 1; i >= 0; i--) {
            if (A[i]) {
                val++;
                if (val == cnt/3)
                    c = i; // start of 3rd segment
                else if (val == 2 * (cnt/3))
                    b = i; // start of 2nd segment
                else if (val == cnt) {
                    a = i; // start of 1st segment
                    break;
                }
            }
        }
        for (i = 0; i < (int)A.size() - c; i++) {
            if (a+i >= b || b+i >= c) // overlapping regions
                return {-1, -1};
            if (A[c+i] != A[a+i] || A[c+i] != A[b+i]) // mismatch
                return {-1, -1};
        }
        return {a+i-1, b+i};}
};
__________________________________________________________________________________________________
