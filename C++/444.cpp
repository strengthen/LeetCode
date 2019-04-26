__________________________________________________________________________________________________
class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if (seqs.empty()) return false;
        int n = org.size(), cnt = n - 1;
        vector<int> pos(n + 1, 0), flags(n + 1, 0);
        bool existed = false;
        for (int i = 0; i < n; ++i) pos[org[i]] = i;
        for (auto& seq : seqs) {
            for (int i = 0; i < seq.size(); ++i) {
                existed = true;
                if (seq[i] <= 0 || seq[i] > n) return false;
                if (i == 0) continue;
                int pre = seq[i - 1], cur = seq[i];
                if (pos[pre] >= pos[cur]) return false;
                if (flags[cur] == 0 && pos[pre] + 1 == pos[cur]) {
                    flags[cur] = 1; --cnt;
                }
            }
        }
        return cnt == 0 && existed;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, int> m, pre;
        for (int i = 0; i < org.size(); ++i) m[org[i]] = i;
        for (auto& seq : seqs) {
            for (int i = 0; i < seq.size(); ++i) {
                if (!m.count(seq[i])) return false;
                if (i > 0 && m[seq[i - 1]] >= m[seq[i]]) return false;
                if (!pre.count(seq[i])) {
                    pre[seq[i]] = (i > 0) ? m[seq[i - 1]] : -1;
                } else {
                    pre[seq[i]] = max(pre[seq[i]], (i > 0) ? m[seq[i - 1]] : -1);
                }
            }
        }
        for (int i = 0; i < org.size(); ++i) {
            if (pre[org[i]] != i - 1) return false;
        }
        return true;
    }
};
__________________________________________________________________________________________________
