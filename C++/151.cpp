__________________________________________________________________________________________________
4ms
static auto _=[](){cin.tie(nullptr);ios::sync_with_stdio(false);return 0;}();
class Solution
{
public:
    string reverseWords(string str)
    {
        string result;
        int left, right;
        int index = 0;
        
        // Trim leading whitespace
        while (index < str.size() && str[index] == ' ')
            ++index;
        
        for (; index < str.size(); ++index)
        {
            left = index;
            while (index < str.size() && str[index] != ' ')
                ++index;
            
            right = index - 1;
            
            for (int ptr = right; ptr >= left; --ptr)
                result.push_back(str[ptr]);
            result.push_back(' ');
            
            // Trim trailing whitespace after any word
            while (index + 1 < str.size() && str[index + 1] == ' ')
                ++index;
        }
        
        if (!result.empty())
            result.pop_back();
        
        reverse(result.begin(), result.end());
        return result;
    }
};
__________________________________________________________________________________________________
8812 kb
class Solution {
public:
    void reverseString(string &s, int start, int end) {
        
        while(start < end) {
            char c = s[start];
            s[start] = s[end];
            s[end] = c;
            start++;
            end--;
        }
    }
    void reverseWords(string &s) {
        
        
        //Remove extra white spaces
        int rd_idx = 0;
        int wr_idx = 0;
        
        for(int i=rd_idx; i < s.size();) {
            
            if (s[i] == ' ') {
                while( (i < s.size()) && s[i] == ' ') {
                    i++;
                }
                if( (i != s.size()) && (wr_idx > 0)) {
                    s[wr_idx++] = ' ';
                }
            }
            else {
                s[wr_idx++] = s[i++];
            }
        }
        
        if( wr_idx == 0) {
            s = "";
            return;
        }
        s[wr_idx] = '\0';
        reverseString(s, 0, wr_idx-1);


        for(int i= 0; i < wr_idx; i++) {            
            int start = i;                
            int end = start;
            while( (end < wr_idx) && (s[end] != ' ')) {
                end++;
            }
            reverseString(s, start, end-1);
            i = end;
            
        }
    }
};
__________________________________________________________________________________________________
