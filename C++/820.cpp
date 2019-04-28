__________________________________________________________________________________________________
sample 36 ms submission
class Solution {
static inline bool startsWith(const string& str, const string& prefix)
{
    return str.size() >= prefix.size() && 0 == str.compare(0, prefix.size(), prefix);
}

public:
    int minimumLengthEncoding(vector<string>& words) {
        for (auto &word : words)
            reverse(word.begin(), word.end());
        sort(words.begin(), words.end());
        int ans = 0, cnt = 0;
        for (int i = 0; i < words.size() - 1; i++)
        {
            if (!startsWith(words[i + 1], words[i]))
                ans += words[i].length();
            else
                cnt++;
        }
        return ans + words.size() - cnt + words.back().length();
    }
};

static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
__________________________________________________________________________________________________
sample 12192 kb submission
class Solution {
public:
    static bool myComp(string a, string b){
        return a.size()>b.size();
    }
    bool isSubstr(string a,string b){
        if(a.size()<b.size()) return false;
        int n1=a.size();
        int n2=b.size();
        for(int i=1;i<=n2;i++){
            if(a[n1-i]!=b[n2-i]){
                return false;
            }
        }
        return true;
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),myComp);
        int len=0;
        int n=words.size();
        bool flag;
        for(int i=0;i<n;i++){
            flag=false;
            for(int j=0;j<i;j++){
                if(isSubstr(words[j],words[i])){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                len+=words[i].size()+1;
            }
        }
        return len;
    }
};
__________________________________________________________________________________________________
