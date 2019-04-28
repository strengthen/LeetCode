__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int line = 1;
        int last = 0;
        
        for (auto c : S) {
            int idx = widths[c-'a'];
            if (last + idx > 100) {
                ++line;
                last = 0;
            }
            last += idx;
        }
        
        return {line, last};
    }
};
__________________________________________________________________________________________________
sample 8468 kb submission
const static auto ioSpeedUp=[](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return NULL;
}();
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> vResult(2,0);
        if(S.empty())
            return vResult;
        int iTotalLine =1, iLastLienWid = 0, iCurLienWid = 0; 
        for(auto &cValue:S)
        {
            auto iLen=widths[cValue - 'a'];
            if(iCurLienWid+iLen > 100)
                iCurLienWid = iLen, ++iTotalLine;
            else
                iCurLienWid+=iLen;
        }
        vResult[0] = iTotalLine;
        vResult[1] = iCurLienWid;
        return vResult;
    }
};
__________________________________________________________________________________________________
