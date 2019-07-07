__________________________________________________________________________________________________
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> levels(n + 1, 0);

        for (int i = 0; i < n; i++)
            levels[i + 1] = levels[i] + (seq[i] == '(' ? +1 : -1);

        int max_level = *max_element(levels.begin(), levels.end());
        int half = max_level / 2;
        vector<int> answer(n, 0);

        for (int i = 0; i < n; i++)
            answer[i] = min(levels[i], levels[i + 1]) < half ? 1 : 0;

        return answer;
    }
};

__________________________________________________________________________________________________

__________________________________________________________________________________________________
