__________________________________________________________________________________________________
4ms
int optimization = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int l = 0, r = numbers.size() - 1;
        
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                ans.push_back(l + 1);
                ans.push_back(r + 1);
                break;
            } else if (sum < target) {
                ++l;
            } else if (sum > target) {
                --r;
            }
        }
            
        return ans;
    }
};
__________________________________________________________________________________________________
9296 kb
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r)
        {
            int sum = numbers[l] + numbers[r];
            if(sum == target)
            {
                return {l + 1, r + 1};
            }else if (sum < target)
            {
                ++l;
            }else
            {
                --r;
            }
        }
        
        return {};
    }
};
__________________________________________________________________________________________________
