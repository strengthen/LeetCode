__________________________________________________________________________________________________
4ms
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
         if (s1.size() + s2.size() != s3.size()) {
        return false;
    }

    vector< vector<int> > match(s1.size()+1, vector<int>(s2.size()+1, false) );

    match[0][0] = true;
    for(int i=1; i<=s1.size(); i++) {
        if (s1[i-1] == s3[i-1] ) {
            match[i][0] = true;
        }else{
            break;
        }
    }
    for(int i=1; i<=s2.size(); i++) {
        if (s2[i-1] == s3[i-1] ) {
            match[0][i] = true;
        }else{
            break;
        }
    }

    
    for(int i=1; i<=s1.size(); i++) {
        for(int j=1; j<=s2.size(); j++) {
            if (s1[i-1] == s3[i+j-1]) {
                match[i][j] = match[i-1][j] || match[i][j];
            }
            if (s2[j-1] == s3[i+j-1]) {
                match[i][j] = match[i][j-1] || match[i][j];
            }
        }
    }
    return match[s1.size()][s2.size()];
    }
};
__________________________________________________________________________________________________
8028 kb
class Solution 
{
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if(len1 + len2 != len3)
            return false;
        else if(len3 == 0)
            return true;
        
        bool *dp = new bool[len1 + 1]();  // dp[l]: whether using up to length l in str1 is possible
        for(int l = 1; l <= len3; ++l)  // first l chars from s3
            /* !!! reverse order(like backpack) */
            for(int l1 = min(len1, l); l1 >= 0; --l1)  // l1 of l from s1, others from s2
            {
                if(l - l1 < 0 || l - l1 - 1 > len2)  // invalid division
                    dp[l1] = false;
                else if(l1 > 0 && s1[l1 - 1] == s3[l - 1])  // s1 matches(check dp[l1 - 1])
                {
                    if(l == 1)  // init
                        dp[l1] = true;
                    else if(dp[l1 - 1] == true)
                        dp[l1] = true;
                }
                else if(l - l1 - 1 < 0 || s2[l - l1 - 1] != s3[l - 1])  // s1&s2 all mismatch
                    dp[l1] = false;
                else  // s2 matches when s1 doesn't match(check dp[l1] == remain the same)
                {
                    if(l == 1)  // init
                        dp[l1] = true;
                    
                }
            }
        
        // any division
        for(int i = 0; i <= len1; ++i)
            if(dp[i] == true)
                return true;
        
        return false;
    }
};
__________________________________________________________________________________________________
