__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ret;
        if(nums.empty())
            return ret;
        int cur = nums[0];
        for(int i = 0;i<nums.size();i++){
            int cur = nums[i];
            int nex= nums[i];
            string range = to_string(cur);
            while(i+1<nums.size() && nums[i+1] == nex+1){
                i++;
                nex = nums[i]; 
            }
            if(cur == nex)
                ret.push_back(range);
            else
                ret.push_back(range + "->"+to_string(nex));
        }
        return ret;
    }
};
__________________________________________________________________________________________________
sample 8384 kb submission
class Solution {
private:
  string encode(int low, int high) {
    if (low == high) {
      return to_string(low);
    }
    return to_string(low) + "->" + to_string(high);
  }
public:
  vector<string> summaryRanges(vector<int>& nums) {
    if (nums.empty()) {
      return vector<string>();
    }
    int low = nums[0];
    int high = nums[0];
    vector<string> result;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] != (high + 1)) {
        result.push_back(encode(low, high));
        low = nums[i];
        high = nums[i];
      } else {
        high = nums[i];
      }
    }
    result.push_back(encode(low, high));
    return result;
  }
};
__________________________________________________________________________________________________
