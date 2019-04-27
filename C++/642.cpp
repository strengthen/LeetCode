__________________________________________________________________________________________________
class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        for (int i = 0; i < sentences.size(); ++i) {
            freq[sentences[i]] += times[i]; 
        }
        data = "";
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            ++freq[data];
            data = "";
            return {};
        }
        data.push_back(c);
        auto cmp = [](pair<string, int>& a, pair<string, int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp) > q(cmp);
        for (auto f : freq) {
            bool matched = true;
            for (int i = 0; i < data.size(); ++i) {
                if (data[i] != f.first[i]) {
                    matched = false;
                    break;
                }
            }
            if (matched) {
                q.push(f);
                if (q.size() > 3) q.pop();
            }
        }
        vector<string> res(q.size());
        for (int i = q.size() - 1; i >= 0; --i) {
            res[i] = q.top().first; q.pop();
        }
        return res;
    }
    
private:
    unordered_map<string, int> freq;
    string data;
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
