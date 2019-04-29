__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        if(A.empty()) return {};
        int prefix=0;
        vector<bool> res(A.size(), false);
        for(int i=0; i<A.size(); ++i)
        {
            prefix=prefix*2%5+A[i];
            if(prefix%5==0) res[i]=true;
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int s = A.size();
        int n = 0;
        if (s == 0) return res;
        
        for (int i = 0; i<s; i++){
            n = (2*n+A[i]) %5;
            if (n%5 == 0){
                res.push_back(true);
            }  
            else res.push_back(false);
        }
        return res;
    }
};
__________________________________________________________________________________________________
