__________________________________________________________________________________________________
16ms
static const auto io_opt = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        
        int what_now = nums[0];
        int index_to_insert = 1;
        
        for (int i=index_to_insert; i<nums.size(); ++i) {
            if (what_now != nums[i]) {
                what_now = nums[i];
                nums[index_to_insert] = what_now;
                ++index_to_insert;
            }
        }
        
        return index_to_insert;
    }
};
__________________________________________________________________________________________________
20ms
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int writeIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[writeIndex] != nums[i]) {
                writeIndex++;
                nums[writeIndex] = nums[i];  
            }
        }
        writeIndex++;
        return writeIndex;
    }
};
__________________________________________________________________________________________________
24ms
class Solution {
public:
 int removeDuplicates(vector<int>& nums) {
        if(empty(nums))
            return 0;
        int writeIndex = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i-1]!=nums[i]){
                nums[writeIndex++] = nums[i];
            }
        }
        return writeIndex;
    }
};
__________________________________________________________________________________________________
9844 kb
int static fast = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;}();
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        int pivot = 0;
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i]>nums[pivot])
            {
                pivot++;
                swap(nums[i],nums[pivot]);
            }
        }
        return pivot+1;
        
    }
};
__________________________________________________________________________________________________
9868 kb
static vector<int> minh=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return vector<int>{};
}();

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size())
            return 0;
        int record = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[record++] = nums[i];
            }
        }
        return record;
    }
};
__________________________________________________________________________________________________
