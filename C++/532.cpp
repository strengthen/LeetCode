__________________________________________________________________________________________________
sample 16 ms submission
auto speedup =[]() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        if (k < 0)
            return 0;
        int count = 0;
        if (k == 0) {
            unordered_map<int,int> xs;
            for (auto n : nums)
                xs[n]++;
            for (auto& x : xs)
                if (x.second > 1)
                    ++count;
        } else {
            unordered_set<int> xs(nums.begin(), nums.end());
            for (auto x : xs) 
                if (xs.find(x+k) != xs.end())
                    ++count;
        }
        return count;
    }
};
__________________________________________________________________________________________________
sample 9816 kb submission
static const auto speedup = []() { 
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    return 0; 
}();
class Solution {
public:
    
    
    int findPairs(vector<int>& nums, int k) {
        int cnt = 0;
        sort(nums.begin(), nums.end());
        
        for(int left = 0; left < min(nums.size(), nums.size() - 1); left++) {
            
            if(left && nums[left-1] == nums[left]) continue; // avoid duplicates
            
            int right = left + 1;
            
            //cout << "left: " << left << " right: " << right << endl;
            
            while(right < nums.size() && nums[right] - nums[left] < k) {
                right++;
            }
            if(right < nums.size() && nums[right] - nums[left] == k) cnt++;
        }        
        return cnt;
    }
};
__________________________________________________________________________________________________
