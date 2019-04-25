__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<vector<double>> res;
    unordered_map<string, vector<string>> adj;
    unordered_map<string, int> mymap;
    vector<bool> visited;
    void DFS(string src, string start, double val){
        if (!visited[mymap[src]]){
            visited[mymap[src]] = true;
            for(string n: adj[src]){
                double tmp = val * res[mymap[src]][mymap[n]];
                res[mymap[start]][mymap[n]] = tmp;
                DFS(n, start, tmp);
            }
            visited[mymap[src]] = false;
        }
    }
    
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> ans;
        int count = 0;
        for (auto p: equations){
            adj[p.first].push_back(p.second);
            adj[p.second].push_back(p.first);
            if (!mymap.count(p.first))     mymap[p.first] = count++;
            if (!mymap.count(p.second))     mymap[p.second] = count++;
        }
        res = vector<vector<double>>(count, vector<double>(count, -1.0));
        visited = vector<bool>(count, false);
        
        for (int i=0; i < equations.size(); i++){
            string a = equations[i].first;
            string b = equations[i].second;
            res[mymap[a]][mymap[b]] = values[i];
            res[mymap[b]][mymap[a]] = 1.0 / values[i];
            res[mymap[a]][mymap[a]] = 1.0;
            res[mymap[b]][mymap[b]] = 1.0;
        }
        
        unordered_map<string, int>::iterator itr = mymap.begin();
        while(itr != mymap.end()){
            DFS(itr->first, itr->first, 1.0);
            itr++;
        }
        
        for (int i=0; i < queries.size(); i++){
            string a = queries[i].first;
            string b = queries[i].second;
            if (!mymap.count(a) || !mymap.count(b))
                ans.push_back(-1.0);    
            else{
                if (res[mymap[a]][mymap[b]] == -1.0){
                    res[mymap[a]][mymap[b]] = (res[mymap[b]][mymap[a]] == -1.0 ? -1.0 : 1.0/res[mymap[b]][mymap[a]]);
                }
                ans.push_back(res[mymap[a]][mymap[b]]);
            }
        }
        
        return ans;
    }
};
__________________________________________________________________________________________________
sample 9212 kb submission
class Solution {
public:
  vector<double> calcEquation( const vector<pair<string, string>> equations,
                               const vector<double>&              values,
                               const vector<pair<string, string>> queries ) {
    const int neqns = equations.size(), nvalues = values.size(),
              nqueries = queries.size();
    assert( neqns == nvalues );
    vector<double> res( nqueries, -1 );

    unordered_map<string, Node*> map;
    for ( int i = 0; i < neqns; i++ ) {
      const string &s1 = equations[ i ].first, &s2 = equations[ i ].second;
      if(map.count(s1)) {
        if(map.count(s2)) {
          join( map[ s1 ], map[ s2 ], values[ i ], map );
        }
        else{
                  map[ s2 ]         = new Node();
        map[ s2 ]->value  = map[ s1 ]->value / values[ i ];
        map[ s2 ]->parent = map[ s1 ];
        }
      }
      else{
        if(map.count(s2)) {
        map[ s1 ]         = new Node();
        map[ s1 ]->value  = map[ s2 ]->value * values[ i ];
        map[ s1 ]->parent = map[ s2 ];
        }
        else{
        map[ s1 ]         = new Node();
        map[ s2 ]         = new Node();
        map[ s1 ]->value  = values[ i ];
        map[ s2 ]->value  = 1;
        map[ s1 ]->parent = map[ s2 ];
        }
      }
    }

    for ( int i = 0; i < nqueries; i++ ) {
      const pair<string, string>& query = queries[ i ];
      if ( map.count( query.first ) != 0 && map.count( query.second ) != 0 &&
           find( map[ query.first ] ) == find( map[ query.second ] ) ) {
        res[ i ] = map[ query.first ]->value / map[ query.second ]->value;
      }
    }
    return res;
  }

private:
  struct Node {
    Node*  parent;
    double value = 0.0;
    Node() { parent = this; }
  };

  void join( Node* node1, Node* node2, double num,
             unordered_map<string, Node*>& map ) {
    Node * parent1 = find( node1 ), *parent2 = find( node2 );
    double ratio = node2->value * num / node1->value;
    for ( auto it = map.begin(); it != map.end(); it++ ) {
      if ( find( it->second ) == parent1 ) {
        it->second->value *= ratio;
      }
    }
    parent1->parent = parent2;
  }

  Node* find( Node* node ) {
    return node == node->parent ? node : node->parent = find( node->parent );
    ;
  }
};
__________________________________________________________________________________________________
