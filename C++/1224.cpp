__________________________________________________________________________________________________
sample 20 ms submission
static const auto _ = [](){
    ios::sync_with_stdio(false);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int cnt[100001] = {0};
        int freq[100001] = {0};
        int maxF = 0;
        int res = 0;
        int len = nums.size();
        for(int i=0;i<len;i++)
        {
            int v = nums[i];
            cnt[v]++;
            freq[cnt[v]]++;
            freq[cnt[v] - 1]--;
            maxF = max(maxF , cnt[v]);
            if(maxF == 1 || (maxF * freq[maxF]) + 1 == i + 1 || (maxF-1)*(freq[maxF-1]) + maxF == i+1) res = i+1;
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 24 ms submission
static const auto _ = [](){
    ios::sync_with_stdio(false);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int cnt[100001] = {0};
        int freq[100001] = {0};
        int maxF = 0;
        int res = 0;
        int len = nums.size();
        for(int i=0;i<len;i++)
        {
            int v = nums[i];
            cnt[v]++;
            freq[cnt[v]]++;
            freq[cnt[v] - 1]--;
            maxF = max(maxF , cnt[v]);
            if(maxF == 1 || (maxF * freq[maxF]) + 1 == i + 1 || (maxF-1)*(freq[maxF-1]) + maxF == i+1) res = i+1;
        }
        return res;
    }
};
__________________________________________________________________________________________________
