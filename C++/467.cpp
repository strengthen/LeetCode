__________________________________________________________________________________________________
sample 4 ms submission
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
  int findSubstringInWraproundString(string p) {
	int len = p.size();
	if (len < 2) return len;

	vector<int> alphabet(26, 0);
	int count = 0;
	int result = 0;
	for (int i = 0; i < len; ++i) {
	  int index = p[i] - 'a';
	  bool consecutive = i == 0 || 
		(p[i] == 'a' ? (p[i - 1] == 'z') : (p[i - 1] + 1 == p[i]));
	  if (!consecutive) count = 0;
	  if (++count > alphabet[index]) {
		result += count - alphabet[index];
		alphabet[index] = count;
	  }
	}

	return result;
  }
};
__________________________________________________________________________________________________
sample 9736 kb submission
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> c(26, 0);
        
        int len=0;
        
        for(int i=0;i<p.size();i++){
            if(i>0 && (p[i]-p[i-1]==1 || p[i-1]-p[i]==25))
                len++;
            else
                len=1;
            
            c[p[i]-'a']=max(c[p[i]-'a'], len);
        }
        
        return accumulate(c.begin(), c.end(), 0);
    }
};
__________________________________________________________________________________________________
