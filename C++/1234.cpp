__________________________________________________________________________________________________
sample 4 ms submission
 [[maybe_unused]] static int const  _ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:   

	int balancedString(std::string_view s) {
		const int N = s.size();
		std::array<int, 256> count = {};
		for (char c : s) {
			count[c]++;
		}
		int res = N;
		int i = 0;
		for (int j = 0; j < N; j++) {
			count[s[j]]--;
			while (i < N && count['Q'] <= N/4 && count['W'] <= N/4  && count['E'] <= N/4  && count['R'] <= N/4 ) {
				res = std::min(res, j - i + 1);
				count[s[i]]++;
				i++;
			}
		}
		return res;
	}

};
__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    int balancedString(string s) {
        int count[128] = {0};
        for (auto c : s)
        {
            count[c]++;
        }
        
        // as long as chars outside the window are <= n/4, we can make the whole string balanced
        int i = 0, res = s.size(), n = s.size(), k = n / 4;
        for (int j = 0; j < n; ++j)
        {
            count[s[j]]--; // move char at j into window
            
            while (i < n && count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k)
            {
                res = min(res, j - i + 1);
                count[s[i++]]++; // move char at i out of window and see
            }
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    int balancedString(string s) {
        int q=0,w=0,e=0,r=0;
        int n=s.size();
        int l=n/4;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='Q')
                q++;
            else if(s[i]=='W')
                w++;
            else if(s[i]=='E')
                e++;
            else
                r++;
        }
        
        if(q==l && w==l && e==l && r==l) // already balanced
            return 0;
        
        if(q>l)
            q=q-l;
        else
            q=0;
        if(w>l)
            w=w-l;
        else 
            w=0;
        if(e>l)
            e=e-l;
        else
            e=0;
        if(r>l)
            r=r-l;
        else
            r=0;
        
        
        int res=n,start=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='Q')
                q--;
            else if(s[i]=='W')
                w--;
            else if(s[i]=='E')
                e--;
            else
                r--;
            // cout<<q<<" "<<w<<" "<<e<<" "<<r<<endl;
            if(q<=0 && w<=0 && e<=0 && r<=0) {
                while(q<=0 && w<=0 && e<=0 && r<=0)
                {
                    res=min(res,i-start+1);
                    if(s[start]=='Q')
                        q++;
                    else if(s[start]=='W')
                        w++;
                    else if(s[start]=='E')
                        e++;
                    else
                        r++;
                    start++;
                }
                start--;
                if(s[start]=='Q')
                    q--;
                else if(s[start]=='W')
                    w--;
                else if(s[start]=='E')
                    e--;
                else
                    r--;
                // cout<<q<<" "<<w<<" "<<e<<" "<<r<<endl;
                // cout<<start<<" "<<i<<endl;
            }
        }
        
        return res;
    }
};