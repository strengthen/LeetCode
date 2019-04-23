__________________________________________________________________________________________________
4ms
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        int min_start = 0, max_len = 1;
        for (int i = 0; i < s.size();) {
          int j = i, k = i;
          while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
          i = k+1;
          while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
          int new_len = k - j + 1;
          if (new_len > max_len) { min_start = j; max_len = new_len; }
        }
        return s.substr(min_start, max_len);
    }
};
__________________________________________________________________________________________________
4ms
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int n = s.size(), maxLen = 0, start = 0;
        for (int i = 0; i < n;) {
            if (n - i <= maxLen / 2) break;
            int left = i, right = i;
            while (right < n - 1 && s[right + 1] == s[right]) ++right;
            i = right + 1;
            while (right < n - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right; --left;
            }
            if (maxLen < right - left + 1) {
                maxLen = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, maxLen);
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    tuple<int, int, int> find_max_pal(const string &s, int left, int right) {
        if (left-1 >= 0 && right+1 < s.size() && s[left-1] == s[right+1])
            return find_max_pal(s, left-1, right+1);
        return make_tuple(right - left + 1, left, right);
    }

    string expand(string s) {
        if (s.size() < 1) return "";
        string result = "#";
        for (int i=0; i<s.size(); i++) {
            result += s[i];
            result += "#";
        }
        return result;
    }

    string longestPalindrome(string s) {
        s = expand(s);
        cout << s << endl;
        vector<int> pal(s.size(), 0);

        int c=-1, r=-1;

        for (int i=0; i<s.size(); i++) {
            int mirror = c - (i - c);
            int offset = 0;
            if (i < r) 
                offset = min(r - i, pal[mirror]);

            auto result = find_max_pal(s, i-offset, i+offset);
            int left = get<1>(result), right = get<2>(result);

            int len = (right - left) / 2;
            pal[i] = len;

            if (r < right) {
                c = i;
                r = right;
            }
        }

        int len = 0, index = -1;
        for (int i=0; i<pal.size(); i++) {
            if (len < pal[i]) {
                 len = pal[i];
                 index = i;
            }
        }

        stringstream ss;
        int last = min(index + len, (int) s.size());
        for (int i=index-len; i<=last; i++) {
            if (s[i] == '#') continue;
            ss << s[i];
        }

        return ss.str();
    }
};
__________________________________________________________________________________________________
8708 kb
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(0);
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<1)
            return "";
        int start = 0, end = 0;
        for(int i=0; i<s.size(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i+1);
            int len = max(len1, len2);
            if(len>end-start) {
                start = i - (len-1) / 2;
                end = i + len / 2;
            }            
        }
        return s.substr(start, end-start+1);
    }
    
    int expandAroundCenter(string &s, int left, int right) {
        int L = left, R = right;
        while(L>=0 && R<s.size() && s[L]==s[R]) {
            L--;
            R++;
        }
        return R-L-1;
    }
};
__________________________________________________________________________________________________
8788 kb
class Solution {
public:
    string longestPalindrome(string s) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        int l_max = 1;
        string sp(s.end()-1,s.end());
        int i = 0, j;
        while(s.size()-i > l_max)
        {
            for(j = s.size()-1; j-i+1>=l_max; j--)
            {
                if( s[i] == s[j] )
                {
                    if(isPalindrome(&s[i],j-i+1))
                    {
                        l_max = j-i+1;
                        sp = s.substr(i,l_max);
                        break;
                    }
                }
            }
            i++;
        }
        return sp;
    }
    bool isPalindrome(char* s, int sz) {
        for(int i=0; i<sz/2; i++)
        {
            if(s[i] != s[sz-i-1])
                return false;
        }
        return true;
    }
};
__________________________________________________________________________________________________
