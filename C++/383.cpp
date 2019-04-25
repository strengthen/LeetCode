__________________________________________________________________________________________________
sample 8 ms submission
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> counts(128, 0);
        for (const char c : magazine)
            ++counts[c];

        for (const char c : ransomNote)
            if (--counts[c] < 0) return false;

        return true;
    }
};
__________________________________________________________________________________________________
sample 10748 kb submission
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int count[128]={0};
        if(ransomNote.size()>magazine.size()) return false;
        
        for(int i=0;i<magazine.size();i++) count[magazine[i]]++;
        for(int i=0;i<ransomNote.size();i++) count[ransomNote[i]]--;
        for(int i=0;i<128;i++) if(count[i]<0) return false;
        return true;
    }
    bool canConstruct1(string ransomNote, string magazine) {
        vector<int> count(128, 0);
        for (const auto& c : magazine) {
            count[c]++;
        }
        for (const auto& i : ransomNote) {
            if (count[i] == 0) return false;
            count[i]--;
        }
        return true;
    }
};
__________________________________________________________________________________________________
