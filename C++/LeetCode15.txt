__________________________________________________________________________________________________
88ms
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if( nums.empty() )
            return {};
        
        sort(nums.begin(), nums.end());
        
        if( nums.size() < 2 || nums.front() > 0 || nums.back() < 0 )
            return {};

        vector<vector<int>> a;
        for( auto it = nums.begin(); it < nums.end()-2 && *it <= 0;  )
        {
            auto left = it+1;
            auto right = nums.end()-1;
            
            while( left < right )
            {
                const auto val = *it + *left + *right;
                if( val == 0 )
                {
                    a.push_back( {*it, *left, *right} );
                    for( auto prev = left; left < right && *left == *prev; ++left );
                    for( auto prev = right; left < right && *right == *prev; --right );
                }
                else if( val < 0 )
                {
                    for(; left < right && *it + *left + *right < 0; ++left );
                }
                else // if( val > 0 )
                {
                    for(; left < right && *it + *left + *right > 0; --right );
                }
            }
            for( auto n = *it; it < nums.end()-2 && n == *it; it++ );
        }
        return a;
    }
};
__________________________________________________________________________________________________
92ms
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()<=2)return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int a = nums[i];
            if(a > 0) break;
            if (i > 0 && a == nums[i - 1]) continue;
            for (long j = i + 1, k = nums.size() - 1; j < k;) {
                int b = nums[j];
                int c = nums[k];
                int value = a + b + c;
                if (value == 0) {
                    result.push_back(vector<int>({a, b, c}));
                    while (j<k && b == nums[++j]);
                    while (j < k &&c == nums[--k]);
                } else if (value > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return result;
    }
};
__________________________________________________________________________________________________
96ms
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.empty()) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        std::unordered_map<int,int> num_map;
        int len = nums.size(), sum = 0, pre = nums[0]-1;
        int start = 0, end = 0;
        for(int i = 1; i < len-1; i++){
            sum = -nums[i-1];
            if(sum < 0) break;
            if(sum == pre) continue;
            start = i;
            end = len-1;
            while(end > start){
                if(nums[start] == nums[start-1] && start!=i) start++;
                else if(nums[start] + nums[end] < sum) start++;
                else if(nums[start] + nums[end] == sum){
                    ans.push_back({-sum,nums[start],nums[end]});
                    start++;
                }
                else end--;
            }
            pre = -nums[i-1];
        }
        return ans;
    }
};
__________________________________________________________________________________________________
14516 kb
static int pre = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.size() < 3)
			return move(result);
		else {
			sort(nums.begin(), nums.end());
			auto size = static_cast<int>(nums.size());
			for (auto i = 0; i < size - 2; ++i) {
				auto left = nums[i];
				if (left > 0)
					break;
				else {
					auto j = i + 2;
					while (j < size) {
						while (j < size - 1 && nums[j] == nums[j + 1])
							j++;
						if (binary_search(nums.cbegin() + i + 1, nums.cbegin() + j, -left - nums[j])) {
							result.emplace_back(vector<int>{left, -left - nums[j], nums[j]});
						}
						j++;
					}
				}
				while (i < size - 2 && nums[i] == nums[i + 1])
					i++;
			}
			return move(result);
		}
	}
};
__________________________________________________________________________________________________
14616 kb
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vv;
        int i, j, k;
        
        sort(nums.begin(), nums.end()); 
        for(i = 0; i < nums.size(); i++)
        {
            j = i + 1; k = nums.size() - 1;
            while(j < k)
            {
                if(nums[i] + nums[j] + nums[k] < 0) j++;
                else if(nums[i] + nums[j] + nums[k] > 0) k--;
                else
                {
                    vv.push_back({nums[i], nums[j], nums[k]});
                    while(j + 1 < k && nums[j+1] == nums[j]) j++;
                    while(j + 1 < k && nums[k-1] == nums[k]) k--;
                    j++; k--;
                }
            }
            while(i + 1 < nums.size() && nums[i+1] == nums[i]) i++; 
        } 
        return vv;
    }
};

static int x = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return NULL;
}();
__________________________________________________________________________________________________
