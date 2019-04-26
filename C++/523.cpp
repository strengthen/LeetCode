__________________________________________________________________________________________________
sample 16 ms submission
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
	if (nums.size() < 2) return false;

	for (int i = 0; i < nums.size() - 1; ++i) 
	  if (nums[i] == 0 && nums[i + 1] == 0) return true;

	if (k == 0) return false;
	else if (k < 0) k = -k;

	unordered_map<int, int> store{{0, -1}, {nums[0], 0}};
	int sum = nums[0];
	for (int i = 1; i < nums.size(); ++i) {
	  sum += nums[i];
	  for (int j = (sum / k) * k; j >= k; j -= k) {
		auto it = store.find(sum - j);
		if (it != store.end() && (i - it->second > 1)) return true;
	  }
	  auto it = store.find(sum);
	  if (it == store.end()) store[sum] = i;
	}

	return false;
  }
};
__________________________________________________________________________________________________
× Close
sample 10712 kb submission
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for(int i = 0; i <nums.size(); ++i){
            int sum = nums[i];
            for(int j = i + 1; j <nums.size(); ++j){
                sum += nums[j];
                if(k==0){
                    if(sum == 0)
                        return true;
                }
                else if(sum%k ==0)
                    return true;
                
            }
        }
        return false;
    }
};
__________________________________________________________________________________________________
