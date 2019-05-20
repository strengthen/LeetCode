__________________________________________________________________________________________________
sample 20 ms submission
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool predecessor(string &word1, string &word2) {
        bool add = false;
        int L = word1.length();
        int i = 0, j = 0;
        while (i < L) {
            if (word1[i] != word2[j]) {
                if (add)
                    return false;
                add = true;
            }
            else
                i++;
            j++;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        vector <pair <string, int>> W[17];
        for (auto &word : words) {
            int L = word.length();
            W[L].emplace_back(word, 1);
        }
        int ans = 0;
        for (int L = 1; L <= 16; L++) {
            for (auto &P2 : W[L]) {
                for (auto &P1 : W[L - 1]) {
                    if (predecessor(P1.first, P2.first))
                        P2.second = max(P2.second, P1.second + 1);
                }
                ans = max(ans, P2.second);
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 24 ms submission
class Solution {
public:
    int longestStrChain(std::vector<std::string>& words) {
		std::unordered_map<int, std::vector<
			std::pair<std::string, int>>> length_string_map;
		for (auto &word: words) {
			if (length_string_map.find(word.size()) == length_string_map.end()) {
				length_string_map[word.size()] = {};
			}
			length_string_map[word.size()].push_back({word, 0});
		}

		int max_length = 0;
		for (int word_size=1; word_size<=16; ++word_size) {
			if (length_string_map.find(word_size) == length_string_map.end()) {
				continue;
			}
			for (auto &word_cnt_pair: length_string_map[word_size]) {
				if (length_string_map.find(word_size-1) != length_string_map.end()) {
					for (auto &prev_length_pair: length_string_map[word_size-1]) {
						if (this->validChainPair(prev_length_pair.first, word_cnt_pair.first)) {
							word_cnt_pair.second = std::max(word_cnt_pair.second, prev_length_pair.second);
						}
					}
				}
				word_cnt_pair.second++;
				if (word_cnt_pair.second > max_length) {
					max_length = word_cnt_pair.second;
				}
			}
		}
		return max_length;
    }

	bool validChainPair(std::string &s1, std::string &s2) {
		int idx1 = 0;
		int idx2 = 0;
		bool has_different = false;
		while (idx1<s1.size() and idx2<s2.size()) {
			if (s1[idx1] != s2[idx2]) {
				if (has_different) {
					return false;
				}
				has_different = true;
				idx2++;
				continue;
			}
			idx1++;
			idx2++;
		}
		return true;
	}

};
__________________________________________________________________________________________________
sample 28 ms submission
class Solution {
public:
  static bool isPrefix(const string &pred, const string& succ) {

    for(int i = 0, j = 0, n = 0, e = pred.size(); i < e; ++i, ++j) {
      if (pred[i] != succ[j]) {
        ++n;
        if (n > 1)
          return false;
        --i;
      }
    }

      return true;
  }
  
    int longestStrChain(vector<string>& words) {
      vector<vector<pair<int, int>>> ww(1001);
      int longest = 0;
      int maxlen = 1;
        for(int i = 0, e = words.size(); i != e; ++i) {
          int len = words[i].size();
          ww[len].push_back(make_pair(i, 1));
          longest = max(longest, len);
        }

      for(int i = 2; i <= longest; ++i) {
        const auto& preds = ww[i - 1];
        for(auto & curr : ww[i]) {
          for(auto& pred : preds)
          if (isPrefix(words[pred.first], words[curr.first])) {
        
            curr.second = max(curr.second, pred.second + 1);
            maxlen = max(maxlen, curr.second);
          }
        }
      }
      return maxlen;
    }
};