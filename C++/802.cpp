__________________________________________________________________________________________________
sample 112 ms submission
auto __ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //how to consider color question about graph
        //To color point we draw white for never visit , gray color means visiting , black color means visited
        
        vector<int> color(graph.size(),0);
        vector<int> retv;
        for(int i =0;i<graph.size();i++)
        {
            if(dfs(graph,i,color))
            {
                retv.push_back(i);
            }
        }
        return retv;
    }
    bool dfs(vector<vector<int> >& edge,int cur,vector<int> & color)
    {
        
        if(color[cur]>0)
        {
            return color[cur] ==2;
        }
        color[cur] = 1;
        for(auto i : edge[cur])
        {
            if(color[i] == 2)
                continue;
            if(color[i] == 1 || !dfs(edge,i,color))
                return false;
        }
        color[cur] =2;
        return true;
    }
};
__________________________________________________________________________________________________
sample 31732 kb submission
static int x = []() {
	// toggle off cout & cin, instead, use printf & scanf
	std::ios::sync_with_stdio(false);
	// untie cin & cout
	cin.tie(NULL);
	return 0;
}();

class Solution {
public:
  
  bool dfs( vector<vector<int> >& graph, int node, vector<int>& color )
  {
    if( color[node] > 0 ) return color[node] == 2;
    color[node] = 1;
    for( auto n : graph[node] )
    {
      if( color[node] == 2 ) continue;
      if( color[n] == 1 || !dfs( graph, n, color) )
        return false;
    }
    color[node] = 2;
    return true;
  }
  
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      vector<int> color( graph.size(), 0 );
      vector<int> res;
      for( int i = 0; i < graph.size(); ++i )
      {
        if( dfs( graph, i, color ) ) res.push_back( i );
      }
      return res;
    }
};
__________________________________________________________________________________________________
