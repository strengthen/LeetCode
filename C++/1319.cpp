__________________________________________________________________________________________________
sample 56 ms submission
//假如一个图有n个连通分量,则需要(n-1)条多余的线将他们连接起来
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class node{
public:
    int rank;
    int root;
    node():rank(0),root(-1){}
};


int _find_set(std::vector<node> &_set,int index){
    if(_set[index].root==-1) return index;
    int res = _find_set(_set,_set[index].root);
    _set[index].root = res;
    return res;
}

void do_union(std::vector<node> &_set, int a, int b) {
    int index_a = _find_set(_set,a);
    int index_b = _find_set(_set,b);

    if(index_a==index_b) return;

    if(_set[index_a].rank<_set[index_b].rank){
        _set[index_a].root = index_b;
    }else{
        _set[index_b].root = index_a;
        if(_set[index_a].rank==_set[index_b].rank) _set[index_a].rank++;
    }
}


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        std::vector<node> union_set(n);

        for(int i=0;i<connections.size();i++){
            do_union(union_set,connections[i][0],connections[i][1]);
        }
        
        int con = 0;
        
        for(int i=0;i<n;i++){
            if(union_set[i].root==-1) con++;
        }
        
        if(connections.size()+1<n) return -1;
        return con - 1;
    }
};
__________________________________________________________________________________________________
sample 60 ms submission
[[maybe_unused]] static auto const fast = []{return ios_base::sync_with_stdio(false);}();

struct a_disjoint_set
{
 vector<int> roots;
 vector<int> ranks;

 auto totuple () const
 {
  return tie(roots,ranks);
 }

 a_disjoint_set (int const N) : roots(N), ranks(N,1)
 {
  iota(begin(roots),end(roots),0);
 }

 auto size () const
 {
  return roots.size();
 }

 auto operator [] (int const index)
 {
  return root(index);
 }

 int root (int const index)
 {
  return roots[index] == index ? index : roots[index] = root(roots[index]);
 }

 bool join (int const i, int const j)
 {
  auto const [ri,rj] = tuple(root(i),root(j));
  if (ri != rj)
  {
   auto const [m,M] = ranks[ri]<ranks[rj] ? tie(ri,rj) : tie(rj,ri);
   roots[m] = M;
   if (ranks[m] == ranks[M]) { ++ranks[M]; }
  }
  return ri != rj; // whether this joins components.
 }
}; // a_disjoint_set

struct Solution
{
 int makeConnected (int const N, vector<vector<int>>const& connections)
 {
  // the min config is for all nodes forming a tree or list, basically a graph
  // without circles. that requires at least N-1 edges where N is the node
  // count. if we have fewer cables, it's impossible to fully connect.
  if (size(connections) < N-1) { return -1; }

  // once we have enough cables, the job is always doable. the worst case is
  // simply disconnect everything and collect all cables. then put them back to
  // reconnect all nodes into a tree or list. but we can do better, which is to
  // switch only M-1 cables, where M is the number of disconnected components in
  // the initial graph.
  a_disjoint_set ds(N);
  for (auto&& connection : connections)
  {
   ds.join(connection[0],connection[1]);
  }

  vector<int> components(N);
  for (auto i = 0; i < N; ++i)
  {
   ++components[ds.root(i)];
  }
  return count_if(begin(components),end(components),[&](auto&value){return value;})-1;
 }
};
__________________________________________________________________________________________________
sample 76 ms submission
static const auto i=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        //统计这些并查集
        if(connections.size()<n-1){
            return -1;
        }
        vector<int>p(n);
        iota(p.begin(),p.end(),0);
        function<int(int)> find=[&p](int x){
            int son=x;
            while(p[x]!=x){
                x=p[x];
            }
            while(son!=x){
                int tmp=p[son];
                p[son]=x;
                son=tmp;
            }
            return x;
        };
        int size=n;
        for(auto it:connections){
            int p1=find(it[0]);
            int p2=find(it[1]);
            if(p1!=p2){
                p[p1]=p2;
                --size;
            }
        }
        return size-1;
    }
};