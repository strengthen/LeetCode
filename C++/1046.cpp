__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int itm : stones)
            pq.push(itm);

        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if (x != y)
                pq.push(y - x);
        }

        return pq.size() == 0 ? 0 : pq.top();
    }
};
__________________________________________________________________________________________________
Runtime: 0 ms
Memory Usage: 8.7 MB
class Solution {
public:
    int lastStoneWeight(vector<int>& st) {
  multiset<int> s(begin(st), end(st));
  while (s.size() > 1) {
    auto w1 = *prev(s.end());
    s.erase(prev(s.end()));
    auto w2 = *prev(s.end());
    s.erase(prev(s.end()));
    if (abs(w1 - w2) > 0) s.insert(abs(w1 - w2));
  }
  return s.empty() ? 0 : *s.begin();
 }
};
__________________________________________________________________________________________________
