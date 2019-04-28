__________________________________________________________________________________________________
sample 112 ms submission
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n=A.size();
        sort(A.begin(),A.end());
        vector<int> ans(n);
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++)vp.emplace_back(make_pair(B[i],i));
        sort(vp.begin(),vp.end());
        int i=n-1;
        int li=0;int ri=n-1;
        while(i>=0)
        {
               if(vp[i].first<A[ri])
               {
                   ans[vp[i].second]=A[ri];
                   ri=ri-1;
               }
               else
               {
                    ans[vp[i].second]=A[li];
                   li=li+1;
               }
            i=i-1;
        }
        return ans;
        
    }
};
__________________________________________________________________________________________________
sample 14440 kb submission
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        vector<int> idx(B.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){return B[a]<B[b];});
        int lo=0, hi = A.size()-1;
        vector<int> res(A.size());
        for(int i=idx.size()-1; i>=0; i--){
            if(B[idx[i]]<A[hi]) res[idx[i]] = A[hi--];
            else res[idx[i]] = A[lo++];
        }
        return res;
    }
};
__________________________________________________________________________________________________
