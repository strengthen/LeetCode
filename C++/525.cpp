__________________________________________________________________________________________________
sample 60 ms submission
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return 0;
        
        vector<int> oldidxes(2*len+1, -2);
        oldidxes[len] = -1;

        int idx = 0;
        int zerocnt = 0;
        int retval = 0;
        for (auto num : nums) {
            if (num == 0) ++zerocnt;
            else --zerocnt;
            if (oldidxes[zerocnt+len] == -2) {
                oldidxes[zerocnt+len] = idx;
            }
            else {
                retval = max(retval, idx - oldidxes[zerocnt+len]);
            }
            idx++;
        }
        
        return retval;
    }
};

static const auto __ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
sample 20604 kb submission
static int x = [](){std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0;}();
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxlen = 0, curr_sum = 0;
        map<int, int> mymap;
        mymap[0] = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            curr_sum += ((nums[i] == 1) ? 1 : -1);
            if(mymap.find(curr_sum) == mymap.end())
                mymap[curr_sum] = i;
            else if((i - mymap[curr_sum]) > maxlen)
                maxlen = i - mymap[curr_sum];            
        }
        return maxlen;
    }
};
__________________________________________________________________________________________________
