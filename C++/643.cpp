__________________________________________________________________________________________________
sample 60 ms submission
auto speedup =[]() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        sum = accumulate(nums.begin(), nums.begin()+k, 0);
        int max = sum;
        for (auto it = nums.begin() + k; it < nums.end(); it++) {
            sum += *it;
            sum -= *(it - k);
            max = std::max(max, sum);
        }
        return (double)max / k;
    }
};
__________________________________________________________________________________________________
sample 16820 kb submission
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double resultTemp=LONG_MIN;
        for(int i=0;i<nums.size()-k+1;i++){
            double temp=0;
            for(int j=0;j<k;j++){
                temp+=nums[i+j];
            }
            resultTemp=max(resultTemp,temp);
        }
        return resultTemp/k;
    }
};
static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
