__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
	int tallestBillboard(vector<int>& rods) {
		sort(rods.begin(), rods.end(), greater<int>());
		int sum = 0;
		for (const auto& r : rods) {
			sum += r;
		}	
		int result = 0;
		dfs(rods, 0, 0, sum, 0, result);
		return result;
	}

	// left/right is billboard height of each side
	// index points to next rod
	void dfs(vector<int>& rods, int left, int right, int remain, int index, int& result) {
		if (abs(left - right) > remain ||
			left + right + remain <= result * 2) {
			return;
		}

		if (left == right && result < left) {
			result = left;
		}

		if (index == rods.size()) {
			return;
		}

		remain -= rods[index];
		dfs(rods, left + rods[index], right, remain, index + 1, result);
		dfs(rods, left, right + rods[index], remain, index + 1, result);
		dfs(rods, left, right, remain, index + 1, result);
	}
};
__________________________________________________________________________________________________
sample 8680 kb submission
class Solution {
public:
    int tallestBillboard(vector<int>& rods)
    {
        int n=rods.size();
        int dp[2][10001];
       
        for(int i=0;i<=10000;i++)dp[0][i]=-100000;
         dp[0][5000]=0;
        for(int i=1;i<=n;i++)
        {
            int sz=rods[i-1];
            for(int j=0;j<=10000;j++)
            {
                dp[i%2][j]=dp[1-i%2][j];
                if(j-sz>=0)dp[i%2][j]=max(dp[i%2][j],dp[1-i%2][j-sz]+sz);
                if(j+sz<=10000)dp[i%2][j]=max(dp[i%2][j],dp[1-i%2][j+sz]+sz);
            }
        }
        return max(dp[n%2][5000]/2,0);
    }
};
__________________________________________________________________________________________________
