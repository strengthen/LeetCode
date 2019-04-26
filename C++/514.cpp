__________________________________________________________________________________________________
sample 8 ms submission
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
  int findRotateSteps(string ring, string key) {
	int len_key = key.size();
	int len_ring = ring.size();

	vector<long long> dp(len_ring, 0LL);
	vector<vector<int>> chars(26, vector<int>());
	for (int i = 0; i < len_ring; ++i) chars[ring[i] - 'a'].push_back(i);

	for (int i = len_key - 2; i >= 0; --i) {
	  if (key[i + 1] == key[i]) continue;
	  for (const auto& index: chars[key[i] - 'a']) {
		long long min_value = std::numeric_limits<long long>::max();
		for (const auto& next_index: chars[key[i + 1] - 'a']) {
		  int value = next_index > index ? (next_index - index) : 
			(index - next_index);
		  value = min(value, len_ring - value);
		  min_value = min(min_value, value + dp[next_index]);
		}
		dp[index] = min_value;
	  }
	}

	int res = std::numeric_limits<int>::max();
	for (const auto& index: chars[key[0] - 'a']) {
	  int step = min(index, len_ring - index);
	  res = min(res, (int)(dp[index] + step + key.size()));
	}

	return res;
  }
};
__________________________________________________________________________________________________
× Close
sample 10324 kb submission
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = key.size(), n = ring.size();
        int dp[m+1][n] = {};
        for (int i = m-1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = INT_MAX;
                for (int k = 0; k < n; ++k) {
                    if (ring[k] == key[i]) {
                        int d = min(abs(j-k),n-abs(j-k));
                        dp[i][j] = min(dp[i][j],d + dp[i+1][k]);
                    }
                }
            }
        }
        return dp[0][0] + key.size();
    }
};
__________________________________________________________________________________________________
