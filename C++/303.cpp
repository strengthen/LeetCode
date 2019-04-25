__________________________________________________________________________________________________
sample 24 ms submission
static int dividend=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();


class NumArray {
public:
    std::vector<int> _res; 
    NumArray(const vector<int>& nums) {
        _res.resize(nums.size()+1);
        _res[0] = 0;
        for(int i=1;i<=nums.size();i++){
            _res[i] = _res[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return _res[j+1]-_res[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
__________________________________________________________________________________________________
sample 17016 kb submission
auto fio = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;  
};

class NumArray {
public:
    NumArray(vector<int> nums)
    {
        _sumVec = vector<int>(nums.size()+1);
        auto sum = 0;
        _sumVec[0] = sum;
        for(auto ind = 0; ind != nums.size(); ++ind)
        {
            sum += nums[ind];
            _sumVec[ind+1] = sum;
        }
    };
    
    int sumRange(int i, int j)
    {
        return _sumVec[j+1] - _sumVec[i];
    }
private:
    vector<int> _sumVec;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
__________________________________________________________________________________________________
