__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool detectCapitalUse(string word) {
        int cntCap = 0;
        for(int i = 0; i < word.size(); ++i){
            if(isupper(word[i])) ++cntCap;
        }
        if(cntCap==0 || cntCap==word.size() || (cntCap==1 && isupper(word[0]))) return true;
        return false;
    }
};

__________________________________________________________________________________________________
sample 8192 kb submission
//取消scanf,printf的使用,总之就是可以让运行时间变短,cpp代码
static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;        
}();
class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
		for (int i = 0; i < word.size(); i++) {
			if (isupper(word[i]))
				count++;
		}
		if (count == word.size() || count == 0 || ((count == 1) && (isupper(word[0]))))
			return true;
		else
			return false;
    }
};
__________________________________________________________________________________________________
