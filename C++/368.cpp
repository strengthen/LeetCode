__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
    int bSz=0, sPos=0, nSz, largest;
    vector<int> nums, sol, furthest, best=vector<int>(0);
    
    int passes(int v, int i) {
        if ( sPos==0 ) return 1;
        if ( (sPos>furthest[i]) && ((v%sol[sPos-1])==0) ) {
            furthest[i]=sPos;
            return 1;       // mark the position
        }
        return 0;
    }
    void rec(int i) {
        for ( ; i<nSz; ++i ) {
            if ( bSz>sPos && ((((long)1)<<(bSz-sPos))*nums[i])>largest ) break;
            if ( passes(nums[i],i) ) {
                sol[sPos++]=nums[i];
                rec(i+1);   // w/ num[i] in solution
                --sPos;
            }               // else, w/o num[i] in solution
        }
        if ( bSz < sPos ) {
            bSz = sPos;     // store best
            best = vector<int>(sol.begin(), sol.begin()+sPos);
        }
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& numsOrig) {
        if ( (nSz=numsOrig.size())<=1 ) return numsOrig; 
        nums = numsOrig;
        sol = vector<int>(nSz);
        furthest = vector<int>(nSz,0);
        //
        sort (nums.begin(), nums.end());
        largest = nums.back();
        //
        rec(0);
        return best;
    }
};
__________________________________________________________________________________________________
sample 8788 kb submission
class Solution {
    // 这道题是最长增长子序列的变种，不过要记录parents
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<int> parent(size);
        vector<int> dp(size, 1);
        vector<int> res;
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
        int maxNum = 0;
        int maxInd = 0;
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
        }
        for (int i = 0; i < size; i++) {
            if (dp[i] > maxNum) {
                maxNum = dp[i];
                maxInd = i;
            }
        }
        for (int i = 0; i < maxNum; i++) {
            res.push_back(nums[maxInd]);
            maxInd = parent[maxInd];
        }
        return res;
    }
};
__________________________________________________________________________________________________
