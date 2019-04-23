__________________________________________________________________________________________________
4ms
class Solution {
public:
    int longestValidParentheses(string s) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        stack<int> st;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(')
                st.push(i);
            else if(!st.empty()) {
                s[i] = '*';
                int n = st.top();
                st.pop();
                s[n] = '*';
            }
        }
        
        int ret = 0;
        int cur = 0;
        s += '.';
        for(char c : s) {
            if(c == '*')
                ++cur;
            else {
                ret = max(ret, cur);
                cur = 0;
            }
        }
        
        return ret;
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
  int i;
  bool delim;
 public:
  int helper(const string& s) {
    int count = 0;
    while (++i < s.size() && s[i] == '(') {
      int val = helper(s);

      if (delim) {
        count = max(count, val);
      } else count += val;
    }

    if (i < s.size()) count += 2;
    else delim = true;
    return count;
  }

  int longestValidParentheses(const string& s) {
    int count = i = delim = 0;
    int result = 0;

    for (; i < s.size(); ++i) {
      if (s[i] == '(') {
        int val = helper(s);

        if (delim)
          result = max(result, val);
        else count += val;
      } else {
        result = max(result, count);
        count = 0;
      }
    }

    return max(result, count);
  }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    int longestValidParentheses(string s) {
        
        int mx=0,open=0,cnt=0,index;
        int n=s.length();
        if(n==0)
            return 0;
        stack<int> st;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                arr[i]=0;
                st.push(i);
            }                
            else
            {
                if(st.size()!=0)
                {
                    index=st.top();
                    st.pop();
                    if(index>0)
                        arr[i]=arr[index-1]+2+arr[i-1];
                    else
                        arr[i]=arr[i-1]+2;
                }
                else
                    arr[i]=0;
            }
            mx=max(mx,arr[i]);
        }
        return mx;
    }
};
__________________________________________________________________________________________________
9032 kb
static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    
    int longestValidParentheses(string s) {
        int len = s.length();
        if(len == 0)return 0;
        int dp[len] = {0};
        int max1 = 0;
        for(int i = 1 ; i < len ; i ++){
            if((i-1-dp[i-1]>=0)&&s[i] == ')'&&s[i-1-dp[i-1]] == '('){
                dp[i] = i-2-dp[i-1]>=0?dp[i-1]+2+dp[i-2-dp[i-1]]:dp[i-1]+2;
                if(max1<dp[i])max1 = dp[i];
            }
        }
        return max1;
    }
};
__________________________________________________________________________________________________
9072 kb
static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    
    int longestValidParentheses(string s) {
        int ans=0;
        int left=0,right=0;
        int len=s.length();
        for(int i=0;i<len;i++){
            if(s[i]=='(')left++;
            else{
                right++;
                if(right==left)ans=max(2*right,ans);
                if(right>left){
                    right=0;
                    left=0;
                }
            }
        }
        left=right=0;
        for(int i=len-1;i>-1;i--){
            if(s[i]==')')left++;
            else{
                right++;
                if(right==left)ans=max(2*left,ans);
                if(right>left){
                    right=0;
                    left=0;
                }
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
