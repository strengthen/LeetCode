__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        if(n==0) return true;
        
        int low=0; //the smallest possible number of '('
        int high=0; //the largest possible number of '('
        for(int i=0; i<n; ++i){
            if(s[i]=='(') low++;
            else low--;
            low=max(low,0);
            
            if(s[i]==')') high--;
            else high++;
            if(high<0) return false;
        }
        
        return low==0;
    }
};
__________________________________________________________________________________________________
sample 8328 kb submission
class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;
        for (auto c : s) {
            lo += c == '(' ? 1 : -1;
            hi += c == ')' ? -1 : 1;
            if (hi < 0) {return false;}
            lo = max(0, lo);
        }
        return lo <= 0;
    }
};
__________________________________________________________________________________________________
