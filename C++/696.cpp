__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    int countBinarySubstrings(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n=s.length();
        if(n==1)return 0;
        char curr=s[0];
        int i=1;
        int cnt=0;
        int l=-1,r=-1;
        while(i<n)
        {
            while((i<n)&&(s[i]==curr))i++;
            if(i==n)break;
            l=i-1;
            r=i;
            while((l>=0)&&(r<n)&&(s[r]!=curr)&&(s[l]==curr))
            {
                cnt++;
                r++;l--;
            }
            curr=s[i];
        }
        return cnt;
    }
};
__________________________________________________________________________________________________
sample 12588 kb submission
static int speedup = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int countBinarySubstrings(string s) {
        int cur=1,pre=0,res=0;
        for(int i=1;i<s.size();i++){
            if(s[i] == s[i-1]){
                cur++;
            }else{
                res += min(cur,pre);
                pre = cur;
                cur = 1;
            }
        }
        return res + min(cur,pre);
    }
};
__________________________________________________________________________________________________
