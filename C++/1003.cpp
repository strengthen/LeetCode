__________________________________________________________________________________________________
sample 8 ms submission
static const auto io_sync_off = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	bool isValid(string S) {
		stack<char> s;
		for(auto c: S) {
			if(c != 'c')
				s.push(c);
			else {
				if(s.size() && s.top() == 'b') s.pop();
				else return false;
				if(s.size() && s.top() == 'a') s.pop();
				else return false;
			}
		}
		return s.empty();
	}
};
__________________________________________________________________________________________________
sample 12 ms submission
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static const int _ = [](){
	ios::sync_with_stdio(false);
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
}();


class Solution {
public:
    bool isValid(string s) {
        if(s == "") return true;
        if(s.size() < 3) return false;
        
        bool ans = false;
        size_t pos = s.find("abc", 0);
        size_t i = 0, diff = 0;
        if(pos == string::npos) return ans;
        
        string helper;
        
        for(; pos != string::npos ; pos = s.find("abc", i)) {
        	//cout << "i: " << i << " pos: " << pos << endl;
        	if(pos != i) {
        		diff = pos - i;
        		helper += s.substr(i, diff);
        		//cout << "helper: " << helper << endl;
			}
        	pos += 2;
        	i = pos + 1;
		}
        
        diff = s.size() - i;
        helper += s.substr(i, diff);
        //cout << "last helper: " << helper << endl;
        
        if(isValid(helper))
        	ans = true;
        	
		return ans;
	}
};
__________________________________________________________________________________________________
