__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        
        int n = S.size();
        int pos = -n;
        vector<int> res(n,n);
      
        for(int i=0;i<n;i++) {
            if( S[i] == C ) {
                pos = i;
            } 
            res[i] = min( res[i], abs(i-pos));
        }
        for(int i=n-1;i>=0;i--) {
            if( S[i] == C ) {
                pos = i;
            } 
            res[i] = min( res[i], abs(i-pos));
        }
        
        return res;
        
    }
};
__________________________________________________________________________________________________
sample 9096 kb submission
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        
        vector<int> retVec;
        retVec.resize(S.length(), INT_MAX);
        
        int prevIdx = INT_MIN / 2;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == C)
                prevIdx = i;            
                        
            retVec[i] = i - prevIdx;
        }
        
        prevIdx = INT_MAX / 2;
        for (int i = S.length() - 1; i >= 0; i--) {
            if (S[i] == C)
                prevIdx = i;            
            
            retVec[i] = min(retVec[i], prevIdx - i);
        }        
                
        return retVec;
    }
};
__________________________________________________________________________________________________
