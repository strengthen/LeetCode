__________________________________________________________________________________________________
4ms
class Solution {
public:
    int strStr(string haystack, string needle) {
      if (needle.size() == 0)
          return 0;
        
      if (needle.size() > haystack.size())
          return -1;

        int pos = 0;
        while(1)
        {
            const char* a = haystack.c_str() + pos;
            const char* b = needle.c_str();
            
            while(*a!='\0' && *b!='\0' && *a==*b)
            {
                ++a;++b;
            }
            if(*b=='\0')
                return pos;
            
            if(*a=='\0')
                return -1;
            
            ++pos;
        }
        
        return -1;
    }
};
__________________________________________________________________________________________________
4ms
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int m = haystack.size(), n = needle.size();
        if (m < n) return -1;
        for (int i = 0; i <= m - n; ++i) {
            int j = 0;
            for (j = 0; j < n; ++j) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == n) return i;
        }
        return -1;
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        int n = needle.size(), m = haystack.size(), j;
        vector<int> next(n, 0);
        for(int i = 1; i < n; i++) {
            j = next[i-1];
            while(j != 0 && needle[j] != needle[i])
                j = next[j-1];
            if(needle[i] == needle[j])
                next[i] = j+1;
        }
        j = 0;
        for(int i = 0; i < m; i++) {
            while(j != 0 && haystack[i] != needle[j])
                j = next[j-1];
            if(haystack[i] == needle[j])
                j++;
            if(j == n)
                return i - n + 1;
        }
        return -1;
    }
};
__________________________________________________________________________________________________
8880 kb 
class Solution {
public:
    int strStr(string haystack, string needle) {
        int N = haystack.size(), M = needle.size();
        if (N < M) return -1;
        for (int i = 0; i <= N - M; i++) {
            bool match = true;
            for (int j = 0; j < M; j++)
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break;
                }
            if (match) return i;
        }
        return -1;
    }
};

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
__________________________________________________________________________________________________
8904 kb
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (!haystack.size()) {
            if (!needle.size())
                return 0;
            else
                return -1;
        }
        if (!needle.size()) return 0;
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] == needle[0] and i + needle.size() <= haystack.size()){
                int posH = i+1;
                int posN = 1;
                while (posH < haystack.length() and posN < needle.size()) {
                    if (haystack[posH++] != needle[posN++])
                        break;
                }
                        
                if (posN == needle.length() && haystack[posH-1] == needle[posN-1])
                    return i;
            }
        }
        return -1;
    }
};
auto fast_io =[](){std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
__________________________________________________________________________________________________
