__________________________________________________________________________________________________
sample 28 ms submission
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class NumArray
{
private:
    struct Bucket {
        int bSum = 0;
        vector<int> block;
    };
    vector<Bucket> sums;
    int bucketSize;

public:
    NumArray(const vector<int> &nums)
    {
        int size = nums.size();
        int bucketNums = int(sqrt(size << 1));
        bucketSize = (bucketNums >> 1);
        if (bucketNums * bucketSize < size) bucketSize += 1;
        sums.resize(bucketNums);
        for (int i = 0, j = 0; j < bucketNums; ++j) {
            sums[j].block.reserve(bucketSize);
            for (int k = 0; k < bucketSize && i < size; ++i, ++k) {
                sums[j].block.push_back(nums[i]);
                sums[j].bSum += nums[i];
            }
        }
    }

    void update(int i, int val)
    {
        int j = i / bucketSize, k = i % bucketSize;
        sums[j].bSum += val - sums[j].block[k];
        sums[j].block[k] = val;
    }

    int sumRange(int i, int j)
    {
        int i1 = i / bucketSize, j1 = j / bucketSize;
        int i2 = i % bucketSize, j2 = j % bucketSize;
        int res = 0;
        for (int k = i1; k <= j1; ++k) res += sums[k].bSum;
        res -= accumulate(sums[i1].block.begin(), sums[i1].block.begin() + i2, 0);
        res -= accumulate(sums[j1].block.begin() + j2 + 1, sums[j1].block.end(), 0);
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
__________________________________________________________________________________________________
sample 18728 kb submission
class NumArray {
public:
    vector<int>nums;
    
    NumArray(vector<int> nums) {
        this->nums = nums;
    }
    
    void update(int i, int val) {
        nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        int res = accumulate(nums.begin()+i, nums.begin()+j+1, 0);
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
__________________________________________________________________________________________________
