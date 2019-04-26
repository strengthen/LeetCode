__________________________________________________________________________________________________
sample 8 ms submission
int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();

class Solution {
    int fmx_(vector<int>::iterator& i1, 
             vector<int>::iterator& j1, 
             vector<int>::iterator& i2, 
             vector<int>::iterator& j2,
             unsigned int mask) {
        // the input makes sure that i1<j1 and i2<j2
        // Three special cases:
        if (mask==0) return *i1 ^ *i2;
        
        int res = INT_MIN;
        if (distance(i1,j1)==1) {
            //int res = INT_MIN;
            for(auto i = i2; i!=j2; i++) {
                if ((*i1^*i) > res)
                    res = *i1 ^ *i;
            }
            return res;
        }
        
        if (distance(i2,j2)==1) {
            //int res = INT_MIN;
            for(auto i=i1; i!=j1; i++) {		
                if ((*i2^*i) > res)
                    res = *i2 ^ *i;
            }
            return res;
        }
        
        // Then partition i1 to j1
        auto m1 = partition(i1,j1, [&mask](int x) { return (x&mask)==0; });
        auto m2 = partition(i2,j2, [&mask](int x) { return (x&mask)==0; });
        
        // recursion
        int r1=INT_MIN, r2=INT_MIN;
        if (m1!=i1 and m2!=j2) {
            r1 = fmx_(i1,m1,m2,j2,mask>>1);
        }
        if (m1!=j1 and m2!=i2) {
            r2 = fmx_(m1,j1,i2,m2,mask>>1);
        }
        
        res = max(r1,r2);
        
        if (res==INT_MIN) {
            //means this two cannot be separated at this level
            return fmx_(i1,j1,i2,j2,mask>>2);
        } else {
            return res;
        }
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        
        if (nums.size()==2) return nums[0]^nums[1];
        
        unsigned int mask = 0x80000000;
        vector<int>::iterator iter;
        iter = nums.begin();
        while((iter==nums.begin() or iter==nums.end()) and mask!=0) {
            iter = partition(nums.begin(), nums.end(), 
			     [&mask](int x){ return (x&mask)==0; });
	        mask >>= 1;
        }
        
        if (mask==0) return 0; // all the numbers are the same
        
        auto i1 = nums.begin();
        auto j2 = nums.end();
        //return fmx_(nums.begin(), iter, iter, nums.end(), mask);
        return fmx_(i1, iter, iter, j2, mask);
    }
};
__________________________________________________________________________________________________
sample 9628 kb submission
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) 
    {
        if(nums.size() <= 1)
            return 0;
        int maxXor = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                int xor1 = nums[i] ^ nums[j];
                if(xor1 > maxXor)
                    maxXor = xor1;
            }
        }
        
        return maxXor;
    }
};
__________________________________________________________________________________________________
