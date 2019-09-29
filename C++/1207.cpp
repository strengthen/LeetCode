__________________________________________________________________________________________________
sample 92 ms submission
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counter;
        for(int num : arr) ++counter[num];
        unordered_set<int> seen;
        for(auto & p : counter) {
            if (seen.count(p.second)) return false;
            seen.insert(p.second);
        }
        return true;
    }
};
__________________________________________________________________________________________________
sample 100 ms submission
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occMap;
        for (int x: arr) occMap[x]++;
        bool visited[100005];
        memset(visited, 0, sizeof(visited));
        for (auto& p: occMap)
            if (visited[p.second])
                return false;
            else
                visited[p.second] = true;
        return true;
    }
};
__________________________________________________________________________________________________
sample 104 ms submission
class Solution {
public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> C;
    for (int x : arr) {
      ++ C[x];
    }
    vector<int> A;
    for (const auto& kv : C) {
      A.push_back(kv.second);
    }
    sort(A.begin(), A.end());
    for (int i = 1; i < A.size(); ++ i) {
      if (A[i] == A[i - 1]) return false;
    }
    return true;
  }
};
