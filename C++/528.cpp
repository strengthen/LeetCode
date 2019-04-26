__________________________________________________________________________________________________
sample 104 ms submission
class Solution {
public:
    vector <int> prefSum;
    
    Solution(vector<int> w) {
        prefSum.emplace_back(0);
        for (int n: w) prefSum.emplace_back(n + prefSum.back());
    }
    
    int pickIndex() {
        int randomPick = rand() % prefSum.back();
        // cout << randomPick << " " << RAND_MAX << endl;
        int lo = 1, hi = prefSum.size() - 1, ret = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (prefSum[mid] <= randomPick) {
                lo = mid + 1;
                ret = mid;
            } else hi = mid - 1;
        }
        return ret;
    }
};

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();


/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
__________________________________________________________________________________________________
sample 32652 kb submission
class Solution {
private:
  vector<int> w;
  vector<int> diffs;
  int pos = 0;
  int count = 0;
  int min_val = 0;
  int getFirstNonZero(int pos) {
    while(w[pos % w.size()] == 0) {
      ++pos;
    }
    return pos % w.size();
  }
public:
  Solution(vector<int> w):w(w), diffs(vector<int>(w.size())){
    pos = getFirstNonZero(0);
    count = w[pos];
    min_val = *std::min_element(w.begin(), w.end());
  }

  int pickIndex() {
    if (count < min_val) {
      diffs[pos] = count;
      pos = getFirstNonZero(pos + 1);
      count = w[pos] + diffs[pos];
    }
    count -= min_val;
    return pos;
  }
};

static int desyncio = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
__________________________________________________________________________________________________
