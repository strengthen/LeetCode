__________________________________________________________________________________________________
class Solution {
public:
   bool isEscapePossible(set<pair<int, int>>& blocked, vector<int>& s, vector<int>& t) {
  set<pair<int, int>> visited;
  queue<pair<int, int>> q;
  q.push({ s[0], s[1] });
  int max_steps = 50;
  while (!q.empty() && --max_steps >= 0) {
    queue<pair<int, int>> q1;
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      if (p.first >= 0 && p.first < 10 ^ 6 && p.second >= 0 && p.second < 10 ^ 6) {
        if (visited.find(p) != end(visited) || blocked.find(p) != end(blocked)) continue;
        visited.insert(p);
        if (p.first == t[0] && p.second == t[1]) return true;
        q1.push({ p.first + 1, p.second });
        q1.push({ p.first - 1, p.second });
        q1.push({ p.first, p.second + 1 });
        q1.push({ p.first, p.second - 1 });
      }

    }
    swap(q, q1);
  }
  return !q.empty();
}
bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& s, vector<int>& t) {
  set<pair<int, int>> s_blocked;
  for (auto b : blocked) s_blocked.insert({ b[0], b[1] });
  return isEscapePossible(s_blocked, s, t) && isEscapePossible(s_blocked, t, s);
}
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
