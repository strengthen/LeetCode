__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) sum += nums[i];
        return (n * (n + 1)) / 2 - sum;
    }
};

static int ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
__________________________________________________________________________________________________
sample 9572 kb submission
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sum = (1+len)*(0+len)/2;
        cout << sum<<endl;
        for(int i = 0; i < len; ++i){
            sum -= nums[i];
        }
        return sum;
    }
};
__________________________________________________________________________________________________
