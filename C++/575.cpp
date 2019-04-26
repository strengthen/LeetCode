__________________________________________________________________________________________________
sample 64 ms submission
class Solution {
  public:
  int distributeCandies(vector<int>& candies) {
    int v[200001] = {0};
    int total = 0;
    int n = candies.size();
    for (int i = 0; i < n && total < n / 2; i++) {
      if (v[candies[i] + 100000] == 0) total++;
      v[candies[i] + 100000] = 1;
    }
    return total;
  }
};

int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();
__________________________________________________________________________________________________
sample 17308 kb submission
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int uniq = 1;
        int half;
        half = candies.size()/2;
        sort(candies.begin(), candies.end());
        for (int i = 1; i < candies.size();i++) {
            if (candies[i] != candies[i-1]) {
                uniq++;
            }
        }
        return min(uniq, half);
    }
};
__________________________________________________________________________________________________
