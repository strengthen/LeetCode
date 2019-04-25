__________________________________________________________________________________________________
sample 40 ms submission
class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int start = 0;
        int end = s.size()-1;
        
        while( start < end){
            char ch = s[start];
            s[start] = s[end];
            s[end] = ch;
            ++start;
            --end;
        }
        
    }
    
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
__________________________________________________________________________________________________
sample 15076 kb submission
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        std::reverse(s.begin(), s.end());
    }
};
__________________________________________________________________________________________________
