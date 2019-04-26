__________________________________________________________________________________________________
sample 52 ms submission
struct Solution final {
    static vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) noexcept {
        if (list1.size() > list2.size()) swap(list1, list2);
        unordered_map<string, int> indexes(list1.size());
        for (int i = 0; i < list1.size(); ++i)
            indexes.emplace(move(list1[i]), i);
        int min_index_sum = INT_MAX;
        vector<string> best_choices;
        best_choices.reserve(list1.size());
        for (int i = 0; i < list2.size(); ++i) {
            if (i > min_index_sum) break;
            const auto it = indexes.find(list2[i]);
            if (it == indexes.end()) continue;
            const int index_sum = i + it->second;
            if (index_sum == min_index_sum) best_choices.emplace_back(move(list2[i]));
            else if (index_sum < min_index_sum)
                best_choices.clear(),
                best_choices.emplace_back(move(list2[i])),
                min_index_sum = index_sum;
        }
        return best_choices;
    }
};

static const auto speedup = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
__________________________________________________________________________________________________
sample 21792 kb submission
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        int minIdx = INT_MAX;
        for (int i = 0; i < list1.size(); i++) {
            for (int j = 0; j < list2.size(); j++) {
                if (list1[i] == list2[j]) {
                    if (minIdx == INT_MAX) {
                        minIdx = i + j;
                        ans.push_back(list1[i]);
                    }
                    else if (minIdx == i + j) {
                        ans.push_back(list1[i]);
                    }

                }
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
