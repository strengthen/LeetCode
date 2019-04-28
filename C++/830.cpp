__________________________________________________________________________________________________
sample 8 ms submission
/* Just use two pointers to find window of each group. If group has length no less than 3, add the range of group to result.
The time complexity is O(n) and space complexity is the same.
*/
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        int st = 0;
        char pre = S[0];
        for (int i = 1; i < S.length(); ++i) {
            if (S[i] != pre) {
                if (i - st >= 3) {
                    res.push_back({st, i - 1});
                }
                st = i;
                pre = S[i];
            }
        }
        if (S.length() - st >= 3) {
            res.push_back({st, S.length() - 1});
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 9476 kb submission
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> results;
        if(S.size()>=3){
            int start = 0;
            int count = 1;
            for(int i=1;i<S.size();i++){
                if(S[start]==S[i]){
                    count++;
                }else{
                    if(count>=3){
                        vector<int> result = {start,start+count-1};
                        results.push_back(result);
                    }
                    start = i;
                    count = 1;
                }
            }
            if(count>=3){
                vector<int> result = {start,start+count-1};
                results.push_back(result);
            }
        }
        
        return results;
    }
};

static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
sample 9600 kb submission
static const int desync_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        char a=S[0], b=S[0];
        vector<vector<int>> v;
        int cnt=1;
        int st=0;
        
        for(int i=1; i<S.length(); ++i) {
            if (S[i]==a) 
                ++cnt;
            
            if ((S[i]!=a) || (i==S.length()-1))  {          
                vector<int> temp;
                if (cnt>=3) {
                    temp.push_back(st);
                    
                    if(S[i]!=a) 
                        temp.push_back(i-1);
                    else
                        temp.push_back(i);
                    
                    v.push_back(temp);
                }
                st=i;
                a=S[i];
                cnt=1;
            }
        }            
        return v;
    }
};