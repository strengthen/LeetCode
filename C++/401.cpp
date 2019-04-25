__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        for(int i = 0; i<12; i++){
            for(int j = 0; j<60; j++){
                if(bitsOne((i<<6)+j) == num){
                    ret.push_back(to_string(i) + (j<10?":0":":") + to_string(j));
                }
            }
        }
        return ret;
    }
    int bitsOne(int n){
        int ret = 0;
        while(n){
            n &=(n-1);
            ret++;
        }
        return ret;
    }
};
__________________________________________________________________________________________________
sample 8504 kb submission
class Solution {
public:
  vector<string> readBinaryWatch(int num) {
    vector<string> ans;
    for (int i = 0; i <= num; ++i)
      for (int h : nums(i, 12))
        for (int m : nums(num - i, 60))
          ans.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
    return ans;
  }
private:
  // Return numbers in [0,r) that has b 1s in their binary format.
  vector<int> nums(int b, int r) {    
    vector<int> ans;
    for (int n = 0; n < r; ++n)
      if (__builtin_popcount(n) == b) ans.push_back(n);
    return ans;
  }  
};
__________________________________________________________________________________________________
