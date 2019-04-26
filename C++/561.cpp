__________________________________________________________________________________________________
sample 24 ms submission
static int x = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int arrayPairSum1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i+=2)
        {
            sum += nums[i];
        }
        return sum;
    }
    
    int arrayPairSum(vector<int>& nums) {
        int bucket[20001] = {0};
        for (int c: nums)
        {
            ++bucket[c + 10000];
        }
        int sum = 0;
        int i = 0;
        bool flag = true;
        while (i < 20001) {
            if (bucket[i])
            {
                sum = flag ? sum + i - 10000 : sum;
                //cout << i << "," << bucket[i] << "," << sum << endl;
                flag = !flag;
                --bucket[i];
            }
            if (!bucket[i]) ++i;
        }
        return sum;
    }
};
__________________________________________________________________________________________________
sample 11440 kb submission
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int64_t sum = 0;
        for(int i = 0; i < nums.size(); i+=2) {
            sum += nums[i];
        }
        return sum;
    }
};

static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
