__________________________________________________________________________________________________
sample 92 ms submission
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S==T) return 0;
        int n=0;
        for(int i=0;i<routes.size();i++)
            for(int j=0;j<routes[i].size();j++)
                n=max(n,routes[i][j]);
        vector<vector<short>> sat(n+1);
        for(int i=0;i<routes.size();i++)
            for(int j=0;j<routes[i].size();j++)
                sat[routes[i][j]].push_back(i);
        vector<bool> find(n+1,0);
        vector<bool> finds(routes.size(),0);
        vector<short> dis(n+1,501);
        queue<int> q;
        q.push(S);
        dis[S]=0;
        while(q.size()){
            int t=q.front();
            q.pop();
            find[t]=1;
            for(auto c:sat[t]){
                if(finds[c]) continue;
                finds[c]=1;
                for(auto k:routes[c]){
                    if(k==T) return dis[t]+1;
                    if(!find[k]){
                        find[k]=1;
                        q.push(k);
                        dis[k]=dis[t]+1;
                    }
                }
            }
        }
        return -1;
    }
};
__________________________________________________________________________________________________
sample 22472 kb submission
class Solution {
public:
  int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    std::unordered_map<int, int> stop_freq;
    std::vector<bool> visit(routes.size(), false);
    bool have_route = true;
    stop_freq[S] = 0;
    while (have_route) {
      have_route = false;
      std::vector<int> tmp_visit(routes.size(), 0);

      for (int i = 0; i < routes.size(); ++i) {
        if (visit[i])
          continue;
        for (int j = 0; j < routes[i].size(); ++j) {
          if (stop_freq.count(routes[i][j])) {
            tmp_visit[i] = stop_freq[routes[i][j]] + 1;
            visit[i] = true;
            break;
          }
        }
      }

      for (int i = 0; i < tmp_visit.size(); ++i) {
        if (!tmp_visit[i])
          continue;
        have_route = true;
        for (int j = 0; j < routes[i].size(); ++j) {
          
          if (stop_freq.count(T))
            return stop_freq[T];

          stop_freq[routes[i][j]] = tmp_visit[i];
        }
      }
    }
    return stop_freq[T] ? stop_freq[T] : -1;
  }
};
__________________________________________________________________________________________________
