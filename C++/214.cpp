__________________________________________________________________________________________________
sample 4 ms submission
class Solution {

public:
    string shortestPalindrome(string s)
{
    int n = s.size();
    int i = 0;
    for (int j = n - 1; j >= 0; j--) {
        if (s[i] == s[j])
            i++;
    }
    if (i == n)
        return s;
    string remain_rev = s.substr(i, n);
    reverse(remain_rev.begin(), remain_rev.end());
    return remain_rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
}
};
__________________________________________________________________________________________________
sample 9184 kb submission
class Solution {
public:
    string shortestPalindrome(string s) {
        string result;
        if(s.length() <= 1)
            return s;
        
        int left = 0;
        int right = s.length() -1;
        int prev = s.length() - 1;
        int pal_len = 0;
        
        while(left <= right)
        {
            if(left == right)
            {
                pal_len++;
                break;
            }
            
            if(s[left] == s[right])
            {
                left++;
                right--;
                pal_len +=2;
            }
            else
            {
                left = 0;
                prev--;
                right = prev;
                pal_len = 0;
            }
        }
        
        result = s;
        reverse(result.begin(), result.end());
        cout << result << " " << pal_len << endl;
        
        for(int i = 0 + pal_len; i < s.length(); i++)
        {
            result.append(1,s[i]);
        }
        
        return result;
    }
};
__________________________________________________________________________________________________
