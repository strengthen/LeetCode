__________________________________________________________________________________________________
4ms
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty())
            return 0;
        string::reverse_iterator i=s.rbegin(),j=s.rbegin(); //类型必须逆向迭代器
        while(i!=s.rend()){
            if(!isspace(*i)){
                j=i+1;
                while(j!=s.rend()&&!isspace(*j))
                    ++j;
                return string(i,j).size();
            }
            else
                ++i;
        }
        return 0;
    }
};
__________________________________________________________________________________________________
4ms
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0)
            return 0;
        int count = 0;
        string::reverse_iterator rit=s.rbegin();
        while(*rit == ' ')
            ++rit;
        for(; rit!=s.rend(); ++rit)
        {
            if(*rit == ' ')
                break;
            count++;
        }
        return count;    
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int left = 0;
        int right = len - 1;
        int count = 0;
        while (s[left] == ' ') ++left;
        while (s[right] == ' ') --right;
        for (int i = left; i <= right; ++i) {
            if (s[i] == ' ') count = 0;
            else ++count;
        }
        return count;
    }
};
__________________________________________________________________________________________________
8796 kb
static int x = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        if (len==0) return 0;
        int result = 0;
        bool first = true;
        
        for (int i=len-1; i>=0; --i) {
            if (s[i] == ' ') {
                if (first) {
                    continue;
                }
                return result;
            } else {
                first = false;
                ++result;
            }
        }
        return result;
    }
};
__________________________________________________________________________________________________
8804 kb
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0) return 0;
        
        int temp = 0;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' '){
                temp++;
            } else {
                if (temp > 0){
                    return temp;
                }
            }
        }
        return temp;
    }
};
__________________________________________________________________________________________________