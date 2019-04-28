__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int N = S.size();
        vector<int> match(N, -1);
        for (int i = 0; i < indexes.size(); i++) {
            int ix = indexes[i];
            if (S.substr(ix, sources[i].size()) == sources[i]) match[ix] = i;
        }
        string ans;
        int ix = 0;
        while (ix < N) {
            if (match[ix] >= 0) {
                ans += targets[match[ix]];
                ix += sources[match[ix]].size();
            }
            else {
                ans += S[ix];
                ix++;
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 9452 kb submission
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string ori = S;
        vector<int> newIndex(S.size());
        for(int i = 0; i < S.size();i++){
            newIndex[i] = i;
        }
        for(int i = 0; i < indexes.size(); i++){
            int s = sources[i].size();
            int t = targets[i].size();
            if(ori.substr(indexes[i], s) == sources[i]){
                int low = newIndex[indexes[i]];
                for(int j = indexes[i]; j < ori.size(); j++){
                    newIndex[j] += targets[i].size()-sources[i].size();
                }
                S.replace(low, s, targets[i]);
            }
        }
        return S;
    }
};
__________________________________________________________________________________________________
