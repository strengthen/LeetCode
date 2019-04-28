__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int binaryGap(int N) {
        vector<int> A(32, 0);
        int t{};
        for (int i=0; i<32; ++i) {
            if (((N>>i) & 1) != 0)
                A[t++] = i;
        }
        int ans{};
        for (int i=0; i<t-1; ++i) {
            ans = max(ans, A[i+1] - A[i]);
        }
        return ans;
    }
};
__________________________________________________________________________________________________
× Close
sample 9440 kb submission
class Solution {
public:
    int binaryGap(int N) {
        int last=-1,ans=0;
        for(int i=0;i<32;++i)
        {
            if(((N>>i)&1)>0)
            {
                if(last>=0)
                    ans=max(ans,i-last);
                last=i;
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
