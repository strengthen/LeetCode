__________________________________________________________________________________________________
sample 4 ms submission
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return helper(0, n);
    }
    
    int helper(int left, int right)
    {
        while (left <= right)
        {
            int mid = left + (right - left)/2;
            if (isBadVersion(mid) && !isBadVersion(mid-1))
            {
                return mid;
            }
            
            if (!isBadVersion(mid))
            {
                return helper(mid+1, right);
            }
            
            return helper(left, mid-1);
        }
        return -1;
    }
};
__________________________________________________________________________________________________
sample 7872 kb submission
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        
        while (left+1 < right) {
            int mid = (right - left) / 2 + left;
            if (isBadVersion(mid)) 
                right = mid;
            else
                left = mid;
        }
        
        if (isBadVersion(left))
            return left;
        return right;
    }
};
__________________________________________________________________________________________________
