__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        S = S.substr(1, S.length() - 2);
        
        const int totalLength = S.length();
        vector<string> results;
        
        vector<string> parsedLeft;
        vector<string> parsedRight;
        for (int i = 1; i < totalLength; ++i) {
            string sLeft = S.substr(0, i);
            string sRight = S.substr(i);
            
            Parse(sLeft, parsedLeft);
            Parse(sRight, parsedRight);
            
            if (parsedLeft.size() > 0 && parsedRight.size() > 0) {
                for (int iLeft = 0; iLeft < parsedLeft.size(); ++iLeft) {
                    for (int iRight = 0; iRight < parsedRight.size(); ++iRight) {
                        results.push_back(
                            "(" + parsedLeft[iLeft] + ", " + parsedRight[iRight] + ")"
                        );
                    }
                }
            }
        }
        return results;
    }
    
    void Parse(string & input, vector<string> & parsedStrings) {
        parsedStrings.clear();
        
        const int sLength = input.length();
        if (sLength == 1) {
            parsedStrings.push_back(input);
            return;
        }
        
        const bool isLeadBy0 = input[0] == '0';
        const bool isTrailBy0 = input[sLength-1] == '0';
        if (isLeadBy0 && isTrailBy0) {
            return;
        }
        
        if (isLeadBy0) {
            parsedStrings.push_back("0." + input.substr(1));
            return;
        }
        parsedStrings.push_back(input);
        if (isTrailBy0) {
            return;
        }
        for (int i = 1; i < sLength; ++i) {
            parsedStrings.push_back(input.substr(0, i) + "." + input.substr(i));
        }
    }
};
__________________________________________________________________________________________________
sample 12596 kb submission
auto __ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
bool valid(string s)
{
    if(s.size() == 1)
        return false;
    if(s[0] == '0')
        return true;
    for(auto e:s)
    {
        if(e !='0')
        {
            return false;
        }
    }
    return true;
}
bool zeros(string s)
{
    if(s.size() == 1)
        return false;
    for(auto e :s)
    {
        if(e!='0')
        {
            return false;
        }
    }
    return true;
}
void dfs(string s,vector<string> &retv)
{
    if(s.size() == 1)
    {
        retv.push_back(s);
        return ;
    }
    if(zeros(s))
    {
        return;
    }
    for(int i = 1;i<=s.size();i++)
    {
        string left = s.substr(0,i);
        string right =s.substr(i);
        //zero_valid
        if(valid(left))
        {
            break;
        }
        if(right.size() == 0)
        {
            retv.push_back(left);
            break;
        }
        if(right.back() =='0')
        {
            continue;
        }
        string temp = left+"."+right;
        retv.push_back(temp);
    }
}
class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> retv;
        //ordinary ,this question is dfs,so we must consider dfs method to deal with this problem
        S.erase(S.begin());
        S.pop_back();
        for(int i = 1;i<S.size();i++)
        {
            vector<string> left_con;
            vector<string> right_con;
            string left =S.substr(0,i);
            string right = S.substr(i);
            dfs(left,left_con);
            dfs(right,right_con);
            for(auto s1:left_con)
            {
                for(auto s2:right_con)
                {
                    string temp = "("+s1+", "+s2+")";
                    retv.push_back(temp);
                }
            }       
        }
        return retv;
        
    }
};
__________________________________________________________________________________________________
