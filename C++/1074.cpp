__________________________________________________________________________________________________
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        vector<int> sum(matrix[0].size(), 0);
        
        int ans = 0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<sum.size(); j++) sum[j]=0;
            
            for(int t=i; t<matrix.size(); t++){
                for(int j=0; j<sum.size(); j++) sum[j]+=matrix[t][j];
                
                map<int, int> preSet;
                int preSum = 0;
                preSet[preSum] = 1;
                
                for(int j=0;j<sum.size();j++){
                    preSum += sum[j];
                    int tmp = preSum - target;
                    if(preSet.find(tmp) != preSet.end()){
                        ans += preSet[tmp];
                    }
                    preSet[preSum]++;
                }
            }
            
        }
        
        return ans;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
