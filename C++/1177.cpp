__________________________________________________________________________________________________

sample 84 ms submission
static const auto s = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<int> bitmasks{0};
        int mask = 0;
        for(auto &ch : s) {
            mask ^= (1<<(ch-'a'));
            bitmasks.push_back(mask);
        }
       
        vector<bool> results;
        for(auto &q : queries) {
            int m = bitmasks[q[0]] ^ bitmasks[q[1]+1];
            int bits = __builtin_popcount(m)/2;
            results.push_back(bits<=q[2]);
        } 
       
        return results;
    }
};
__________________________________________________________________________________________________
sample 96 ms submission

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("inline")

static const int _ = []() {
	ios::sync_with_stdio(false);
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
}();

short a[100007][26];

class Solution {
public:
    
    
    bool isp(int l, int r, int k){
        register short o=0,s=0;
        for(int i=0;i<26;i++) {
            int ci = a[r][i]-a[l][i];
            s+=ci;
            if(ci&1) o++;
        }
        if(s&1) o--;
        return o/2<=k;
    }
    
    inline
    vector<bool> canMakePaliQueries(string& s, vector<vector<int>>& queries) {
        for(int i=0;i<s.size();i++){
            memcpy(a[i+1],a[i],26*sizeof(short));
            a[i+1][s[i]-'a']++;
        }
        vector<bool> ans(queries.size());
        int i = 0;
        for(auto& q:queries){
            ans[i++] = isp(q[0],q[1]+1,q[2]);
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 100 ms submission

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("inline")

static const int _ = []() {
	ios::sync_with_stdio(false);
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
}();

short a[100007][26];

class Solution {
public:
    
    
    bool isp(int l, int r, int k){
        register short o=0,s=0;
        for(int i=0;i<26;i++) {
            int ci = a[r][i]-a[l][i];
            s+=ci;
            if(ci&1) o++;
        }
        if(s&1) o--;
        return o/2<=k;
    }
    
    inline
    vector<bool> canMakePaliQueries(string& s, vector<vector<int>>& q) {
        for(int i=0;i<s.size();i++){
            memcpy(a[i+1],a[i],26*sizeof(short));
            a[i+1][s[i]-'a']++;
        }
        vector<bool> ans(q.size());
        for(int i=0;i<q.size();i++){
            ans[i] = isp(q[i][0],q[i][1]+1,q[i][2]);
        }
        return ans;
    }
};