__________________________________________________________________________________________________
4ms
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1, 0);        
        for (int i = 0; i < n; i++) {
            int curCount = result.size();
            while (curCount) {
                curCount--;
                int curNum = result[curCount];
                curNum += (1<<i);
                result.push_back(curNum);
            } 
        }
        return result;
    }
};
__________________________________________________________________________________________________
8328 kb
class Solution {
public:
 
vector<int> grayCode(int n) 
{
    vector<int> sol={0};
    
    int power=1;
    for (int i=1; i<=n; ++i){
        for(int j=power-1; j>=0; --j)
            sol.push_back(sol[j]+power);
        power<<=1;
    }
    return sol;
}    
};
__________________________________________________________________________________________________
