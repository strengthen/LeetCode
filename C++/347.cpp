__________________________________________________________________________________________________
sample 12 ms submission
static int fast = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> res;
        int i = 0;

        for(auto num: nums)
            i = max(i,++m[num]);

        while(res.size() != k){
            for(auto p : m)
                if(p.second == i)
                    res.push_back(p.first);
            --i;
        }

        return res;
    }
};
__________________________________________________________________________________________________
sample 10840 kb submission
class NumCount {
public:
    int val;
    int count;
    NumCount(int i) {
        val = i;
        count = 1;
    }
    bool operator<(NumCount &i) {
        return i.count < count;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<NumCount> numbers;
        for(int i = 0; i < nums.size(); i++) {
            int j = 0;
            for(; j < numbers.size(); j++) {
                if(nums[i] == numbers[j].val) {
                    numbers[j].count++;
                    break;
                }
            }
            if(j >= numbers.size()) {
                NumCount num_count(nums[i]);
                numbers.push_back(num_count);
            }
        }
        sort(numbers.begin(), numbers.end());
        vector<int> ret_val;
        for(int i = 0; i < k; i++) {
            ret_val.push_back(numbers[i].val);
        }
        return ret_val;
    }
};
__________________________________________________________________________________________________
