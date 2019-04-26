__________________________________________________________________________________________________
sample 8 ms submission
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
  int findMinMoves(vector<int>& machines) {
	int len = machines.size();
	if (len < 2) return 0;

	int sum = std::accumulate(machines.cbegin(), machines.cend(), 0);
	if (sum % len != 0) return -1;

	int mean = sum / len;
	vector<int> left(len, 0);
	vector<int> right(len, 0);
	for (int i = 1; i < len; ++i) left[i] = left[i - 1] + machines[i - 1];
	for (int i = len - 2; i >= 0; --i) 
	  right[i] = right[i + 1] + machines[i + 1];

	int res = 0;
	for (int i = 0; i < len; ++i) {
	  int expect_left = i * mean;
	  int expect_right = (len - i - 1) * mean;
	  int left_remain = 0;
	  int right_remain = 0;
	  if (expect_left > left[i]) left_remain = expect_left - left[i];
	  if (expect_right > right[i]) right_remain = expect_right - right[i];
	  res = max(res, left_remain + right_remain);
	}

	return res;
  }
};
__________________________________________________________________________________________________
sample 9868 kb submission
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        if (!machines.size()) return 0;
        int count = 0;
        for (auto m : machines) count += m;
        if  (count % machines.size()) return -1;
        int average = count / machines.size();
        
        int moves = 0;
        for (int i=0, sum=0, expect=0; i < machines.size(); i++) {
            int left  = sum;
            int left_expect = expect;
            sum += machines[i];
            expect += average;
            int right = count - sum;
            int right_expect = count - expect;
            int steps;
            if (machines[i] < average) {
                steps = average - machines[i];
                if (left > left_expect && right > right_expect) steps >>= 1;
            } else {
                int overlay = 0;
                steps = -average + machines[i];
                if (left < left_expect && right > right_expect) {
                    overlay = right - right_expect;
                } else if (left > left_expect && right < right_expect) {
                    overlay = left - left_expect;
                }
                steps += overlay;
            }
            moves = max(moves, steps);
        }
        return moves;
    }
};
__________________________________________________________________________________________________
