__________________________________________________________________________________________________
sample 28 ms submission
class Solution {

bool poss(vector<int>& w, int D,int x)
{
    
    int n=w.size();
    int sum=0;int ans=1;
    for(int i=0;i<n;i++)
    {
        if(w[i]>x)return false;
        if(sum+w[i]>x)
        {
            ans++;sum=w[i];
        }
        else sum+=w[i];
    }
    if(ans<=D)return true;
    return false;
}
    
public:
    int shipWithinDays(vector<int>& weights, int D) {
        std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
        int start=1;int end=500*25;
        while(start<end)
        {
            int mid=(start+end)>>1;
            if(poss(weights,D,mid))end=mid;
            else start=mid+1;
        }
        return start;
    }
};
__________________________________________________________________________________________________
sample 32 ms submission
/*
Intuition
The largest capacity (r) we may even need is the sum of weights of all packages.
The smallest capacity (l) is the weight of the largest package.
Optimization: the smallest capacity cannot be less than r / D, which reduces the search interval if we have a lot of small packages (and D is small).
Our result is within this interval.
Linearithmic Solution
We use binary search to find the minimum capacity. For each capacity we analyze, we count the number of days required to ship all packages.

We decrease the capacity if it takes less days than D, and increase otherwise. Note that, when the number of days equals D, this algorithm keeps decreasing the capacity while it can, therefore finding the smallest capacity required.

Time - nLOGn
*/

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int D) {
        int st = 0, ed = 0;
        for (const auto& w : weights) {
            ed += w;
            st = max(st, w);
        }
        st = max (st, ed / D);
        while (st < ed) {
            int mid = (st + ed) / 2;
            int cnt = 0;
            int sum = 0;
            int i = 0;
            for (; i < weights.size() && cnt < D; ++i) {
                sum += weights[i];
                if (sum > mid) {
                    sum = 0;
                    ++cnt;
                    --i;
                }
            }
            if (i == weights.size()) {
                ed = mid;
            } else {
                st = mid + 1;
            }
        }
        return ed;
    }
};
__________________________________________________________________________________________________
