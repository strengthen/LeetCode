__________________________________________________________________________________________________
sample 12 ms submission
class Solution 
{
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) 
    {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        unordered_set<int> bad;
        for(int i = 0; i < fronts.size(); i++)
            if(fronts[i] == backs[i])
                bad.insert(fronts[i]);
        int res = INT_MAX;
        for(int i = 0; i < fronts.size(); i++)
        {
            if(!bad.count(fronts[i]) && fronts[i] < res)
                res = fronts[i];
            if(!bad.count(backs[i]) && backs[i] < res)
                res = backs[i];
        }
        
        return res == INT_MAX ? 0 : res;
    }
};
__________________________________________________________________________________________________
sample 11616 kb submission
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_map<int,int> M;
        int n=fronts.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(fronts[i]==backs[i]){
                M[fronts[i]]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(M.find(fronts[i])==M.end()){
                ans=min(ans,fronts[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(M.find(backs[i])==M.end()){
                ans=min(ans,backs[i]);
            }
        }
        if(ans==INT_MAX){
            ans=0;
        }
        return ans;
    }
};
__________________________________________________________________________________________________
