__________________________________________________________________________________________________
class Solution {
public:
  int connectSticks(vector<int>& sticks) {
    int res=0;
    priority_queue<int, vector<int>, greater<int> > pq(sticks.begin(),sticks.end());
    while(pq.size()>1u){
      int x=pq.top();pq.pop();
      int y=pq.top();pq.pop();
      res+=x+y;
      pq.emplace(x+y);
    }
    return res;
  }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
