__________________________________________________________________________________________________
4ms
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1);
        for(int i=0; i<n+1; ++i) cut[i] = i-1; 
        int l = 0, r = 0, st = 0;
        while(st<n){
            l = r = st;
            cut[r+1] = min(cut[r+1], cut[l]+1);
            int ms = cut[l]+1;
            while(r<n-1 && s[l] == s[r+1]){ // skip the repeated chars
                ++r;
                ms = min(ms, cut[r]+1);
                cut[r+1] = min(cut[r+1], ms);   
            }
            st = r+1;
            while(r<n-1 && l>0 && s[--l] == s[++r]){ // augment the repeated core to see whether it remains  Palindrome
                cut[r+1] = min(cut[r+1], cut[l] + 1);
            }
        }
        return cut[n];
    }
};
__________________________________________________________________________________________________
8576 kb
class Solution {
public:
	int minCut(string s) {

		int len = s.size();

		if (len <= 1)
			return 0;

		vector<int> result(len, 0);

		for (int i = len - 1; i >= 0; i--)
			partitionCore(s, len, i, result);

		return result[0];
	}

	void partitionCore(string& s, int& len, int beg, vector<int>& result) {

		if (beg == len - 1)
			return;			

		int cnt = result[beg + 1] + 1;

		for (int end = len - 1; end>beg; end--)
		{
			if (isPalindrome(s, beg, end))
			{
				if (end == len - 1)
					cnt = 0;
				else
				{
					if (cnt > result[end + 1] + 1)
						cnt = result[end + 1] + 1;
				}
			}
		}
		result[beg] = cnt;
	}

	bool isPalindrome(string& s, int beg, int end)
	{
		while (beg < end)
		{
			if (s[beg++] != s[end--])
				return false;
		}
		return true;
	}

};
__________________________________________________________________________________________________
