__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    int longestMountain(vector<int>& A) {
        if (A.size() < 3) return 0;
        int i = 0;
        int length = A.size();
        int ml = 0;
        while (i < length) {
            while (i < length - 1 && A[i] >= A[i+1]) ++i;
            if (i == length - 1) break;
            int j = i;
            while (j < length - 1 && A[j] < A[j+1]) ++j;
            if (j == length - 1) break;
            while (j < length - 1 && A[j] > A[j+1]) ++j;
            ++j;
            // cout << "i: " << i << " j: " << j << endl;
            ml = max(ml, j - i);
            i = j - 1;
        }
        return ml >= 3 ? ml : 0;
    }
};

auto ___ = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
__________________________________________________________________________________________________
sample 10144 kb submission
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int flag=0,asize=A.size(),cnt=1,ans=0;
        for(int i=0;i<asize-1;i++)
        {
            if(!flag)
            {
                if(A[i]>A[i+1]&&cnt>1)
                {
                    flag=1;cnt++;
                }
                if(A[i]==A[i+1])
                {
                    cnt=1;continue;
                }
                if(A[i]<A[i+1])
                {
                    cnt++;
                }
            }
            else
            {
                if(A[i]==A[i+1])
                {
                    ans=max(ans,cnt);
                    cnt=1;flag=0;
                }
                if(A[i]>A[i+1])
                    cnt++;
                if(A[i]<A[i+1])
                {
                    ans=max(ans,cnt);
                    cnt=2;flag=0;
                }
            }
        }
        if(flag)
            ans=max(ans,cnt);
        return ans;
    }
};
__________________________________________________________________________________________________
