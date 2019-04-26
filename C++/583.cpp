__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    int minDistance(string word1, string word2) {
        
        vector<int> dp(word1.size()+1, 0);
        std::iota(dp.begin(), dp.end(), 0);
        
        for(int i = 1 ; i <= word2.size(); i++)
        {
            int prev = dp[0];
            dp[0] = i;
            for(int j = 1 ; j <= word1.size(); j++)
            {
                int temp = dp[j];
                if(word1[j-1] == word2[i-1])
                {
                    dp[j] = prev;
                }
                else
                {
                     dp[j] = std::min(dp[j], dp[j-1]) + 1;
                }
                prev = temp;
            }
        }
        return dp.back();
    }
};
__________________________________________________________________________________________________
sample 16244 kb submission
class Solution {
public:
int minDistance(string word1, string word2) {
  int len1=word1.size(), len2=word2.size(), ret=0;
  vector<int> dp(len1+1, 0);
  for (int i=0; i<len2; i++) {
    int pre=0;
    for (int j=0; j<len1; j++) {
      int temp=dp[j+1];
      if (word1[j]==word2[i]) {
        dp[j+1]=max(dp[j+1], max(dp[j], pre+1));
      }
      else {
        dp[j+1]=max(dp[j+1], dp[j]);
      }
      pre=temp;
      ret=max(ret, dp[j+1]);
    }
  }
  return len1-ret+len2-ret;
}
};
__________________________________________________________________________________________________
