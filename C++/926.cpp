__________________________________________________________________________________________________
sample 4 ms submission
int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    int minFlipsMonoIncr(string S) {
		int prev_zero_count = 0;
        vector<int> zero_count(S.size(), 0);
		for (int i = 0; i < S.size(); ++i) {
			if (S[i] == '0') {
				zero_count[i] = prev_zero_count + 1;
				++prev_zero_count;
			} else 
				zero_count[i] = prev_zero_count;
		}

		int min_change = prev_zero_count;
		for (int i = 0; i < S.size(); ++i) {
			int change = (i-zero_count[i]+1) + (prev_zero_count-zero_count[i]);
			if (change < min_change)
				min_change = change;
		}

		return min_change;
    }
};
__________________________________________________________________________________________________
sample 9404 kb submission
class Solution {
public:
    int minFlipsMonoIncr(const std::string& S, int counter_one  = 0, int counter_flip = 0) {
        for (auto ch : S) {
            if (ch == '1') {
                ++counter_one;
            } else {
                ++counter_flip;
            }
            counter_flip = std::min(counter_one, counter_flip);
        }
        return counter_flip;
    }
};
__________________________________________________________________________________________________
