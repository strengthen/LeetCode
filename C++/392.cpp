__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    bool isSubsequence(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n=t.length();
        int m=s.length();
        if(m==0)return true;
        if(n==0||n<m)return false;
        int i=0,j=0;
        char c=s[j];
        while(i<n)
        {
            while((i<n)&&(t[i]!=c))i++;
            if(i==n)
            {
                return false;
            }
            else
            {
                j++;
                if(j==m)return true;
                else c=s[j];
            }
            i++;
        }
        return false;
    }
};
__________________________________________________________________________________________________
sample 16900 kb submission
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0, m = s.size(), n = t.size(); 
        if (m > n) return false; 
        
        while (i < m && j < n) {
            if (s[i] == t[j]) {
                ++i; 
            } 
            ++j;
        }
        return i == m; 
    }
};
__________________________________________________________________________________________________
