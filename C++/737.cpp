__________________________________________________________________________________________________
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_map<string, unordered_set<string>> m;
        for (auto pair : pairs) {
            m[pair.first].insert(pair.second);
            m[pair.second].insert(pair.first);
        }    
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            unordered_set<string> visited;
            queue<string> q{{words1[i]}};
            bool succ = false;
            while (!q.empty()) {
                auto t = q.front(); q.pop();
                if (m[t].count(words2[i])) {
                    succ = true; break;
                }
                visited.insert(t);
                for (auto a : m[t]) {
                    if (!visited.count(a)) q.push(a);
                }
            }
            if (!succ) return false;
        }    
        return true;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_map<string, unordered_set<string>> m;
        for (auto pair : pairs) {
            m[pair.first].insert(pair.second);
            m[pair.second].insert(pair.first);
        }
        for (int i = 0; i < words1.size(); ++i) {
            unordered_set<string> visited;
            if (!helper(m, words1[i], words2[i], visited)) return false;
        }
        return true;
    }
    bool helper(unordered_map<string, unordered_set<string>>& m, string& cur, string& target, unordered_set<string>& visited) {
        if (cur == target) return true;
        visited.insert(cur);
        for (string word : m[cur]) {
            if (!visited.count(word) && helper(m, word, target, visited)) return true;
        }
        return false;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_map<string, string> m;       
        for (auto pair : pairs) {
            string x = getRoot(pair.first, m), y = getRoot(pair.second, m);
            if (x != y) m[x] = y;
        }
        for (int i = 0; i < words1.size(); ++i) {
            if (getRoot(words1[i], m) != getRoot(words2[i], m)) return false;
        }
        return true;
    }
    string getRoot(string word, unordered_map<string, string>& m) {
        if (!m.count(word)) m[word] = word;
        return word == m[word] ? word : getRoot(m[word], m);
    }
};