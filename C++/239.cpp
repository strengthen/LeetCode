__________________________________________________________________________________________________
sample 44 ms submission
static int x = [](){ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> results;
        
        if(nums.empty()) {
            return results;
        }
        
        int candidate = INT_MIN;
        int candidateIdx = 0;
        
        for(int i = 0; i < k; i++) {
            if(candidate <= nums[i]) {
                candidate = nums[i];
                candidateIdx = i;
            }
        }
        
        for(int i = k - 1; i < nums.size(); i++) {
            if(nums[i] >= candidate) {
                candidate = nums[i];
                candidateIdx = i;
            }
            
            if(i - k + 1 > candidateIdx) {
                int follower = i - k + 1;
                candidate = INT_MIN;
                while(follower <= i) {
                    if(candidate <= nums[follower]) {
                        candidate = nums[follower];
                        candidateIdx = follower;
                    }
                    follower++;
                }
            }
            
            results.push_back(candidate);
            
        }
        
        return results;
    }
};
__________________________________________________________________________________________________
sample 12404 kb submission
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()) return vector<int>();
        int count = nums.size() - k + 1;
        vector<int> res(count);
        
        int max_idx = -1;
        
        for(int i = 0; i < count; ++i) {
            if(max_idx < i) {
                max_idx = i;
                for(int j = i; j < i + k; ++j) {
                    if(nums[max_idx] < nums[j]) max_idx = j;
                }
            }
            else {
                max_idx = nums[max_idx] > nums[i + k - 1] ? max_idx : i + k - 1;
            }
            res[i] = nums[max_idx];
        }
        
        return res;
    }
    
   vector<int> maxSlidingWindow_na(vector<int>& nums, int k) {
        deque<int> buffer;
        vector<int> res;

        for(auto i=0; i<nums.size();++i)
        {
            while(!buffer.empty() && nums[i]>=nums[buffer.back()])                              buffer.pop_back();
            
            buffer.push_back(i);

            if(i>=k-1) res.push_back(nums[buffer.front()]);
            if(buffer.front()<= i-k + 1) buffer.pop_front();
        }
        return res;
    }
};
__________________________________________________________________________________________________
