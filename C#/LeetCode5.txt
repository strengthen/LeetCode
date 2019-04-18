__________________________________________________________________________________________________
84ms
public class Solution {
    public string LongestPalindrome(string s) {
        if (string.IsNullOrEmpty(s))
        {
            return "";
        }

        int N = s.Length * 2 + 1;
        int[] lps = new int[N];
        lps[0] = 0;
        lps[1] = 1;
        int C = 1;
        int R = 2;
        int maxLen = 1;
        int maxStart = 0;
        for (int i = 2; i < N; i++)
        {
            int l = 2 * C - i;
            lps[i] = Math.Min(R - i, lps[l]);
            while (lps[i] + i < N && i - lps[i] > 0 && ((lps[i] + i) % 2 == 1
                  || (i + lps[i] + 1) / 2 < s.Length && s[(i + lps[i] + 1) / 2] == s[(i - lps[i] - 1) / 2]))
            {
                lps[i]++;
            }
            
            if (lps[i] > maxLen)
            {
                maxLen = lps[i];
                maxStart = (i - lps[i] + 1) / 2;
            }
            
            if (i + lps[i] >= R)
            {
                C = i;
                R = i + lps[i];
            }
        }
        
        return s.Substring(maxStart, maxLen);
    }
}
__________________________________________________________________________________________________
88ms
public class Solution {
    public string LongestPalindrome(string s) {
        if(s == null || s.Length == 0) return s;
        var n = 2*s.Length+1;
        var p = new int[n];
        p[1] = 1;
        var center = 1;
        var rightCenter = 2;
        var maxLength = 1;
        var start = 0;
        for(int right=2;right<n;right++){
            var left = 2*center-right;
            var diff = Math.Max(0,rightCenter-right);
            p[right] = Math.Min(p[left], diff);
            var l = right - p[right]-1;
            var r = right + p[right]+1;
            while(l >=0 && r < n && (l%2==0 || s[l/2] == s[r/2])){
                p[right]++;
                l--;r++;
            }
            if(p[right] > maxLength){
                maxLength = p[right];
                start = (right-p[right])/2;
            }
            if(right+p[right] >= center){
                center = right;
                rightCenter = center+p[center];
            }
        }
        return s.Substring(start, maxLength);
    }
}
__________________________________________________________________________________________________
92ms
public class Solution {
    public string LongestPalindrome(string s) {
        if (string.IsNullOrEmpty(s)) {
            return "";
        }
        
        var start = 0;
        var end = 0;
        
        for (var i = 0; i < s.Length; i ++) {
            var length1 = ExpandAroundCenter(s, i, i);
            var length2 = ExpandAroundCenter(s, i, i+1);
            var length = Math.Max(length1, length2);
            
            if (end - start < length) {
                start = i - (length - 1) / 2;
                end = i + length / 2;
            }
        }
        
        return s.Substring(start, end-start+1);
    }
    
    public int ExpandAroundCenter(string s, int left, int right) {
        while (left >= 0 && right < s.Length && s[left] == s[right]) {
            left--;
            right++;
        }
        
        return right - left - 1;
    }
}
__________________________________________________________________________________________________
20888 kb 
public class Solution {
        public string LongestPalindrome(string s)
        {
            if (string.IsNullOrEmpty(s)) return s;
            int start = 0, end = 0;
            int maxLen = 0;

            for(int i = 0;i<s.Length;i++)
            {
                int len1 = ExpandAroundCenter(s, i, i);
                int len2 = ExpandAroundCenter(s, i, i + 1);

                int len = Math.Max(len1, len2);

                if(len> maxLen)
                {
                    start = i - (len - 1) / 2;
                    end = i + len / 2;
                    maxLen = len;
                }
            }

            return s.Substring(start, end-start+1);

        }

        private int ExpandAroundCenter(string s,int i,int j)
        {
            while(i>=0 && j<s.Length && s[i]==s[j])
            {
                i--;
                j++;
            }

            return j - i - 1;
        }
}
__________________________________________________________________________________________________
21040 kb
public class Solution 
{
    public string LongestPalindrome(string s) 
    {
        var result = "";
        for(var i = 0; i < s.Length; i++)
        {
            for(var j = s.Length - 1; j >= 0; j--)
            {
                var start = i;
                var end = j;
                
                var difference = end - start;
                if(result.Length > difference)
                {
                    break;
                }
                
                while(start <= end && s[start] == s[end])
                {
                    start++;
                    end--;
                }
                
                if(start >= end)
                {
                    var num = j - i + 1;
                    if(num < 0)
                    {
                        num = 1;
                    }
                    var sub = s.Substring(i, num);
                    if(sub.Length > result.Length)
                    {
                        result = sub;
                    }
                }
            }
        }
        
        return result;
    }
}
__________________________________________________________________________________________________
