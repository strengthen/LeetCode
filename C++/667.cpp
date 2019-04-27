__________________________________________________________________________________________________
sample 20 ms submission
class Solution {
public:
    vector<int> constructArray(int n, int k) {
      vector<int> ans(n,0);
      int l=0;
      for (int i=1;i<=n-k-1;i++) 
        ans[l++]=i;
      for (int j=0;j<k+1;j++) 
        ans[l++]= (j%2==0)? (n-k+j/2): (n-j/2);
      return ans;  
    }
};
__________________________________________________________________________________________________
sample 9584 kb submission
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        
        for (int i = n; i >= k+1; i--) {
            res.push_back(i);
        }
        
        int j=k+1, s = -1;
                        
        for (int i = k; i >= 1; i--) {
            j += (i*s);
            res.push_back(j);
            s *= -1;
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
