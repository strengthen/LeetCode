__________________________________________________________________________________________________
4ms
static const auto fast = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
} ();


class Solution {
public:
    
    int findPeakElement(vector<int>& nums) {
        
        int l = 0;
        int r = nums.size()-1;
        
        while (1) {
            
            
            int mid = (l+r)/2;
            
            ///cout << "l: "<<l<<" r: "<<r<<" mid: "<<mid<<endl;
        
            if (mid == l || mid == r) {
                if (l != r) {
                    if (nums[l] > nums[r]) {
                        return l;
                    } else {
                        return r;
                    }
                } else {
                    return l;
                }
            }

            if (nums[mid] < nums[mid+1]) {
                //move right
                l = mid+1;

            } else if (nums[mid] < nums[mid-1]) {
                //move left
                r = mid -1;

            } else {
                //its peak
                return mid;

            }
        }
        
    }
};
__________________________________________________________________________________________________
8584 kb
class Solution {
    // Binary Search
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int res = 0;
        
        while(l<r){
            int mid = l+(r-l)/2;
            int mid2 = mid+1;
            
            if(nums[mid] < nums[mid2])
                l = mid2;
            else
                r = mid;
        }
        return l;
    }
};

// Fast I/O
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
__________________________________________________________________________________________________
