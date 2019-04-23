__________________________________________________________________________________________________
8ms
static int fastiofunc() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}

static int fastio = fastiofunc();

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastSeen[256];
        memset(lastSeen, -1, 256 * sizeof(int));
        
        int startIndex = -1;
        int currentLen = 0;
        int maxLen = 0;
        
        for(int endIndex=0; endIndex < s.size(); ++endIndex) {
            int lastIndex = lastSeen[s[endIndex]];
            if(lastIndex < startIndex) {
                ++currentLen;
            } else {
                startIndex = lastIndex;
                currentLen = endIndex - startIndex;
            }
            
            maxLen = max(currentLen, maxLen);
            lastSeen[s[endIndex]] = endIndex;
        }
        
        return maxLen;
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if (s.size() <= 1)
			return s.size();

		int arr[256] = { 0 };
		int l = 0;
		int r = -1;
		int max = 0;
		while (l < s.size()) {
			if (r + 1 < s.size() && arr[s[r + 1]] == 0) {
				arr[s[++r]] = 1;
			}
			else {
				arr[s[l++]] = 0;
			}

			if (r - l + 1 > max)
				max = r - l + 1;
		}

		return max;
	}
};
__________________________________________________________________________________________________
16ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
           vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
__________________________________________________________________________________________________
20ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {        
        int tail = -1;
        int front = 0;
        int max = 0;
        int asc[256] = {0};        
        
        while( front < s.size() && tail+1 < s.size() ){            
            if( (asc[s[tail+1]] == 0) ){                
                asc[s[++tail]] = 1;                
            }           
            else{
                
                asc[s[front++]] = 0;                
            }             
            if((tail - front + 1)> max ){
                
                 max = (tail - front + 1);
                
            }            
        }        
        return max;        
    }
};
__________________________________________________________________________________________________
8932 kb
auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0, high = 1;
        int maxlen = 1;
        
        if (s == "") return 0;
        
        int counts[256];
        
        for (int i = 0;i < 256; i++) counts[i] = 0;
        counts[(int)s[low]]++;
    
        while(high < s.length()){
            
            if (counts[(int)s[high]] < 1){
                
                if (maxlen < high - low + 1)
                    maxlen = high - low + 1;
                
                counts[(int)s[high]]++;
                high++;
            }
            else{ 
                counts[(int)s[low]]--;
                low++;
            }    
        }
        
        return maxlen;
    }
};
__________________________________________________________________________________________________
