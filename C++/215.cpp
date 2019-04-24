__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int partition(vector<int>& nums, int left, int right){
        int pid = left + rand()%(right-left+1);
        swap(nums[right], nums[pid]);
        int write = left;
        for(int i=left; i<right; i++){
            if(nums[i]<nums[right]) swap(nums[i], nums[write++]);
        }
        swap(nums[write], nums[right]);
        return write;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int pivot = -1, target = nums.size() - k, left = 0, right = nums.size()-1;
        while(left<=right){
            pivot = partition(nums, left, right);
            if(pivot==target) return nums[pivot];
            if(pivot<target) left = pivot +1;
            else right = pivot -1;
        }
        return -1;
    }
};
__________________________________________________________________________________________________
sample 8952 kb submission
static const auto speedup = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.end() - k, nums.end());
        return *(nums.end() - k);
    }
};
__________________________________________________________________________________________________
