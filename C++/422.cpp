__________________________________________________________________________________________________
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if (words.empty()) return true;
        if (words.size() != words[0].size()) return false;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                if (j >= words.size() || i >= words[j].size() || words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
