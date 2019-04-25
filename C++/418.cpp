__________________________________________________________________________________________________
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string all = "";
        for (string word : sentence) all += (word + " ");
        int start = 0, len = all.size();
        for (int i = 0; i < rows; ++i) {
            start += cols;
            if (all[start % len] == ' ') {
                ++start;
            } else {
                while (start > 0 && all[(start - 1) % len] != ' ') {
                    --start;
                }
            }
        }
        return start / len;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string all = "";
        for (string word : sentence) all += (word + " ");
        int res = 0, idx = 0, n = sentence.size(), len = all.size();
        for (int i = 0; i < rows; ++i) {
            int colsRemaining = cols;
            while (colsRemaining > 0) {
                if (sentence[idx].size() <= colsRemaining) {
                    colsRemaining -= sentence[idx].size();
                    if (colsRemaining > 0) colsRemaining -= 1;
                    if (++idx >= n) {
                        res += (1 + colsRemaining / len);
                        colsRemaining %= len;
                        idx = 0;
                    }
                } else {
                    break;
                }
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
