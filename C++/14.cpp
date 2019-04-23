__________________________________________________________________________________________________
4ms
static auto _=[](){cin.tie(nullptr);ios::sync_with_stdio(false);return 0;}();
class Solution {
public:
string longestCommonPrefix(vector<string> &strs)
    {
        int length = 0;
        int size = strs.empty()?  0: strs.size();
        if(size>0)
        {
            if (size == 1)
            {
                length = strs[0].size();
            }
            else
            {
                sort(strs.begin(), strs.end());
                auto fstElem = strs.front();
                auto lastElem = strs.back();
                for (int i = 0; i <= fstElem.size() || i <= lastElem.size(); ++i)
                {
                    length = i;
                    if (fstElem[i] != lastElem[i])
                    {
                        break;
                    }
                }
            }
            
        }
        return (length > 0) ? strs[0].substr(0,length):"";
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) { return ""; }
		int minLen = strs[0].size();
		for (string str : strs) {
			if (str.size() < minLen) {
				minLen = str.size();
			}
		}
		int low = 0, high = minLen;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (isCommonPrefix(strs, mid)) { low = mid + 1; }
			else { high = mid - 1; }
		}
		return strs[0].substr(0, (low + high) / 2);
	}
	bool isCommonPrefix(vector<string>& strs, int mid) {
		string prefix = strs[0].substr(0, mid);
		for (int i = 1; i < strs.size(); i++) {
			if (strs[i].find(prefix)) { return false; }
		}
		return true;
	}
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        
        // sort so lowest string first;
        sort(strs.begin(), strs.end(), [](string& a, string& b){
            return a.size() < b.size();
        });
        
        int size = strs[0].size();
        int len = 0;
        for(int i = 0; i < size; ++i)
        {
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); ++j)
            {
                if (strs[j][i] != c)
                     return strs[0].substr(0, len);
            }
            ++len;
        }
           
        return strs[0].substr(0, len);
    }
};
__________________________________________________________________________________________________
8656 kb
static int pre = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string result;
		if (strs.empty())
			return move(result);

		auto size = UINT32_MAX;
		for (auto& str : strs) {
			if (str.size() < size)
				size = str.size();
		}
		for (int i = 0; i < size; ++i) {
			auto temp = strs[0][i];
			auto repeat = true;
			for (int j = 1; j < strs.size(); ++j) {
				if (temp != strs[j][i]) {
					repeat = false;
					break;
				}
			}
			if (repeat) {
				result += temp;
			}
			else
				break;
		}
		return move(result);
	}
}; 
__________________________________________________________________________________________________
8864 kb
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string a = strs[0], b = strs.back();
        int i = 0;
        for(; i < a.size(); i++) 
            if(a[i] != b[i]) 
                break;
        return a.substr(0, i);
    }
};
__________________________________________________________________________________________________