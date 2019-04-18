__________________________________________________________________________________________________
3ms
class Solution {
    public String longestPalindrome(String s) {
        String res="";
        int n=s.length();
        char[] ch=s.toCharArray();
        for(int i=0;i<n;i++){
            int j=i;
            while(j+1<n && ch[j]==ch[j+1]) j++;
            int cur=j;
            while(j+1<n && i-1>=0 && ch[j+1]==ch[i-1]){
                j++;
                i--;
            }
            if(j-i+1>res.length()){
                res=s.substring(i,j+1);
            }
            i=cur;
        }
        return res;
    } 
}
__________________________________________________________________________________________________
5ms
class Solution {
    int start = 0;
    int end = 0;
    
    // time O(n^2) 
    // space O(1)
    public String longestPalindrome(String s) {
        if (s.length() == 0) {
            return "";
        }
        
        for(int i=0; i<s.length(); i++) {
            longestPalindromeAtIndex(s,i,i+1);
            longestPalindromeAtIndex(s,i,i);
        }
        
        return s.substring(start, end+1);
    }
    
    private void longestPalindromeAtIndex(String s, int left, int right){
        while(left>=0 && right<s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }

        if (right-left-1 >= end-start+1) {
            start = left+1;
            end = right-1;
        }
    }
}
__________________________________________________________________________________________________
6ms
class Solution {
    public String longestPalindrome(String s) {
    if (s == null || s.length() < 1) return "";
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = Math.max(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substring(start, end + 1);
}

private int expandAroundCenter(String s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
        L--;
        R++;
    }
    return R - L - 1;
  }
}
__________________________________________________________________________________________________
34744 kb
class Solution {
    private int lo, maxLen;
    public String longestPalindrome(String s) {
	    int len = s.length();
	    if (len < 2)
		    return s;
	
        for (int i = 0; i < len-1; i++) {
     	    extendPalindrome(s, i, i);  //assume odd length, try to extend Palindrome as                            possible
     	    extendPalindrome(s, i, i+1); //assume even length.
        }
        return s.substring(lo, lo + maxLen);
    }

    private void extendPalindrome(String s, int j, int k) {
	    while (j >= 0 && k < s.length() && s.charAt(j) == s.charAt(k)) {
		    j--;
		    k++;
	    }
	    if (maxLen < k - j - 1) {
		    lo = j + 1;
		    maxLen = k - j - 1;
	    }
    }
}
__________________________________________________________________________________________________
34748 kb
class Solution {    
    //  Brute force search, expanding around center
    int max = 0;
    int maxl= 0,maxr = 0;
    public String longestPalindrome(String s) {
        int n = s.length();
        if(n < 2)
            return s;        
        // record best
        max = 0;
        maxl = 0;maxr = 0;
        
        // set center
        for(int i = 0; i < n; i++){
            expanding(s,i,i);
        }
        for(int i = 0; i < n-1; i++){
            expanding(s,i,i+1);
        }
        
        return s.substring(maxl,maxr);
    }
    
    void expanding(String s, int l, int r){
        if(s.charAt(l) != s.charAt(r))
            return;
        while(l>0 && r < s.length()-1 && s.charAt(l-1) == s.charAt(r+1)){
            l--;r++;
        }
        int length = r - l + 1;
        if(length > max){
            max = length;
            maxl = l;
            maxr = r+1;
        }
    }
}
__________________________________________________________________________________________________
