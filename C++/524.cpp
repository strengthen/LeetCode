__________________________________________________________________________________________________
sample 24 ms submission
static auto x = [](){std::ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr;}();

class Solution{
private:
	bool match(const string& str,const string& dir){
		int j=0;
		
		for(int k=0;k<dir.size();k++){
			while(j<str.size()&&dir[k]!=str[j]) j++;
			if(j++==str.size()) return false;
		}
		
		return true;
	}
	
public:
	string findLongestWord(string s, vector<string>& d){
		string ans="";
		
		for(const auto& i: d)
			if(i.size()>ans.size()||i.size()==ans.size()&&i<ans)
				if(match(s,i)) ans=i;
		
		return ans;
	}
};
__________________________________________________________________________________________________
sample 16000 kb submission
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res;
        for (string& str: d) {
            int i = 0;
            for (char c: s) {
                if (i<str.size() && c==str[i])
                    ++i;
            }
            if (i==str.size() && str.size()>=res.size()) {
                if (str<res || str.size()>res.size())
                    res = str;
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
