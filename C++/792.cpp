__________________________________________________________________________________________________
sample 76 ms submission
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int N = words.size();
        int current_index[N] = {0};
        queue <int> next[26];
        for(int i = 0; i < N; i++)
            next[words[i][0] - 'a'].push(i);
        for(const auto& character : S)
        {
            int temp = next[character - 'a'].size();
            for(int i = 0; i < temp; i++)
            {
                int word_index = next[character - 'a'].front();
                next[character - 'a'].pop();
                current_index[word_index]++;
                if(current_index[word_index] < words[word_index].length())
                    next[words[word_index][current_index[word_index]] - 'a'].push(word_index);
            }
        }
        int matching_subsequences = 0;
        for(int i = 0; i < N; i++)
            if(current_index[i] == words[i].length())
                matching_subsequences++;
        return matching_subsequences;
    }
};
__________________________________________________________________________________________________
sample 23860 kb submission
class Solution {
    bool isSub(string const & s, string & word) {
        if (word.length() > s.length())
            return false;
        int i = 0, j = 0;
        while (i < word.length()) {
            if (j >= s.length())
                return false;
            if (word[i] == s[j])
                ++i;
            ++j;
        }
        return true;
    }
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int result = 0;
        for (auto & word : words) {
            if (isSub(S, word)) {
                //cout << "it is " << word << endl;
                ++result;
            }
        }
        return result;
    }
};
__________________________________________________________________________________________________
