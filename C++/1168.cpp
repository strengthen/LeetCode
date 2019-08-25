__________________________________________________________________________________________________
class Solution {
  template<typename T>
  struct Kruskal{

    struct edge{
      int from,to;
      T cost;
      int used;
      edge(int from,int to,T cost):
        from(from),to(to),cost(cost),used(0){}
      bool operator<(const edge& e) const{
        return cost<e.cost;
      }
    };

    int n;
    vector<int> r,p;
    vector<edge> es;

    Kruskal(){}
    Kruskal(int n):n(n),r(n,1),p(n){
      iota(p.begin(),p.end(),0);
    }

    int find(int x){
      return (x==p[x]?x:p[x]=find(p[x]));
    }

    bool same(int x,int y){
      return find(x)==find(y);
    }

    void unite(int x,int y){
      x=find(x);y=find(y);
      if(x==y) return;
      if(r[x]<r[y]) swap(x,y);
      r[x]+=r[y];
      p[y]=x;
    }

    void add_edge(int u,int v,T c){
      es.emplace_back(u,v,c);
    }

    T build(){
      sort(es.begin(),es.end());
      T res=0;
      for(auto &e:es){
        if(!same(e.from,e.to)){
          res+=e.cost;
          unite(e.from,e.to);
          e.used=1;
        }
      }
      return res;
    }
  };
public:
  int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
    Kruskal<int> G(n+1);
    for(int i=0;i<n;i++){
      G.add_edge(n,i,wells[i]);
    }
    for(auto es:pipes){
      int u=es[0],v=es[1],w=es[2];
      u--;v--;
      G.add_edge(u,v,w);
    }
    return G.build();
  }
};

__________________________________________________________________________________________________

__________________________________________________________________________________________________
