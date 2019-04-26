__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> check(26,0);
        check[0]=2; check[1]=3; check[2]=3;
        check[3]=2; check[4]=1; check[5]=2;
        check[6]=2; check[7]=2; check[8]=1;
        check[9]=2; check[10]=2; check[11]=2;
        check[12]=3; check[13]=3; check[14]=1;
        check[15]=1; check[16]=1; check[17]=1;
        check[18]=2; check[19]=1; check[20]=1;
        check[21]=3; check[22]=1; check[23]=3;
        check[24]=1; check[25]=3;
        vector<string> ans;
        for(int i=0; i<words.size(); ++i)
        {
            int j=0;
            int first=check[tolower(words[i][j])-'a'];
            for(j=1; j<words[i].length(); ++j)
            {
                if(check[tolower(words[i][j])-'a']!=first){
                    break;
                }
            }
            if(j==words[i].length())
                ans.push_back(words[i]);
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 8424 kb submission
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> dict(26);
        vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        for (int i = 0; i < rows.size(); i++) {
            for (auto c : rows[i]) {
                dict[c-'A'] = 1 << i;
            }
        }
        
        vector<string> res;
        for (auto w : words) {
            int i;
            int prev, cur;
            for (i = 0; i < w.size(); ++i) {
                if (i == 0) {
                    prev = dict[toupper(w[i]) - 'A'];
                    continue;
                }
                cur = dict[toupper(w[i]) - 'A'];
                if (cur != prev) break;
                prev = cur;
            }
            if (i == w.size()) res.push_back(w);
        }
        return res;        
    }
};
__________________________________________________________________________________________________
