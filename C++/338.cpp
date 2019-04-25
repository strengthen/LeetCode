__________________________________________________________________________________________________
sample 52 ms submission
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);
        for(int i=1;i<=num;i++){
            res[i]=res[i>>1]+(i&1);
                               }
        return res;
                                   }
};
__________________________________________________________________________________________________
sample 9340 kb submission
class Solution {
public:
    vector<int> countBits(int num) {
      vector<int> ret(num + 1);
      ret[0] = 0;
      for (int i = 1; i <= num; ++i) {
        ret[i] = ret[i/2] + i%2;
      }
      return ret;
    }
};
__________________________________________________________________________________________________
