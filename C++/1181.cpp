__________________________________________________________________________________________________
class Solution {
private:
    void parse(int index, string& phrase, unordered_map<string, vector<pair<int, string>>>& beginWtih, unordered_map<string, vector<pair<int, string>>>& endWtih) {
        int n = phrase.size();
        int left = 0;
        string first = "";
        for (; left < n; ++left) {
            if (phrase[left] == ' ') {
                break;
            }
            first.push_back(phrase[left]);
        }
        if (left < n) {
            left += 1;
        }
        beginWtih[first].push_back({index, phrase.substr(left)});

        int right = n - 1;
        string last = "";
        for (; right >= 0; --right) {
            if (phrase[right] == ' ') {
                break;
            }
            last.push_back(phrase[right]);
        }
        reverse(last.begin(), last.end());
        if (right < 0) {
            right += 1;
        }
        endWtih[last].push_back({index, phrase.substr(0, right)});
    }
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        unordered_map<string, vector<pair<int, string>>> beginWtih;
        unordered_map<string, vector<pair<int, string>>> endWith;
        for (int i = 0; i < phrases.size(); ++i) {
            parse(i, phrases[i], beginWtih, endWith);
        }

        set<string> result;
        for (auto& eIt: endWith) {
            string last = eIt.first;
            if (beginWtih.find(last) == beginWtih.end()) {
                continue;
            }

            vector<pair<int, string>>& endPhrases = eIt.second;
            vector<pair<int, string>>& beginPhrases = beginWtih[last];
            for (int i = 0; i < endPhrases.size(); ++i) {
                for (int j = 0; j < beginPhrases.size(); ++j) {
                    if (endPhrases[i].first == beginPhrases[j].first) {
                        continue;
                    }

                    string part1 = endPhrases[i].second;
                    if (part1 != "") {
                        part1.push_back(' ');
                    }
                    string part2 = beginPhrases[j].second == "" ? beginPhrases[j].second : " " + beginPhrases[j].second;
                    result.insert(part1 + last + part2);
                }
            }
        }
        return vector<string>(result.begin(), result.end());
    }
};

__________________________________________________________________________________________________
sample 20 ms submission
#include <boost/algorithm/string.hpp>

class Solution {
public:
    int n;
    vector < vector < string > > all;
    vector<string> beforeAndAfterPuzzles(vector<string>& A) {
        n = A.size();
        all.resize(n + 4);
        for(int i = 0;i < A.size();++i) {
            int last = 0;
            for(int j = 0;j < A[i].size();++j) {
                if(A[i][j] == ' ') {
                    all[i].push_back(A[i].substr(last, j - last));
                    last = j + 1;
                }
            }
            all[i].push_back(A[i].substr(last, A[i].size() - last));
            
            // cout << A[i] << ": ";
            // for(int j = 0;j < all[i].size();++j) {
            //     cout << all[i][j] << "-";
            // }
            // cout << "\n";
            
        }
        set < string > ans;
        for(int i = 0;i < n;++i) {
            for(int j = 0;j < n;++j) {
                if(i == j)      continue;
                if(all[i][all[i].size() - 1] == all[j][0]) {
                    string x = all[i][0];
                    for(int k = 1;k < all[i].size();++k) {
                        x += " " + all[i][k];
                    }
                    for(int k = 1;k < all[j].size();++k) {
                        x += " " + all[j][k];
                    }
                    ans.insert(x);
                }
            }
        }
        vector < string > ret;
        for(auto it = ans.begin();it != ans.end();++it) {
            ret.push_back(*it);
        }
        return ret;
    }
};

__________________________________________________________________________________________________
