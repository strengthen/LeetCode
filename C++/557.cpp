__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    string reverseWords(string s) {
        size_t idx_start = 0;
        size_t idx_wip = idx_start;
        while (idx_wip < s.size()) {
            if (s[idx_wip] == ' ') {
                for (int i=idx_start, j=idx_wip-1; i<j; ++i, --j) {
                    char t = s[i];
                    s[i] = s[j];
                    s[j] = t;
                }
                idx_start = idx_wip+1;
            }
            ++idx_wip;
        }
        for (int i=idx_start, j=idx_wip-1; i<j; ++i, --j) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
        }        
        return s;
    }
};

static auto ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
__________________________________________________________________________________________________
sample 11436 kb submission
//取消scanf,printf的使用,总之就是可以让运行时间变短,cpp代码
static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;        
}();

class Solution {
public:
//     以空格为分界,把前面的一个单词反转
    string reverseWords(string s) {
        int i = 0 ,j = 0,len = s.size();
        while(i<len){
            while(j<len && s[j]!=' ')
                j++;
            int k = j - 1;
            while(i<k){
                swap(s[i],s[k]);
                i++,k--;
            }
            i = ++j;
        }
        return s;
    }
};
__________________________________________________________________________________________________
