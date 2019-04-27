__________________________________________________________________________________________________
sample 12 ms submission
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    typedef enum{
        none = 0,
      blue = 1,
      red =2
    }color_t;
    bool isBipartite(vector<vector<int>>& graph) {
        bool r = true;
        //cout<<"Input a graph of length "<<graph.size()<<endl;
        uint8_t * color = new uint8_t[graph.size()];
        memset(color,0x0,sizeof(uint8_t)* graph.size());
        queue<int> q{};
        map<int,bool> v{};
        
        
        for(uint32_t c = 0; c < graph.size(); c++)
        {
            
            //this was never visited
            if(color[c] != 0) continue;
            //else this node was not visited
            q.push(c);
            //at the root, start with red.
            color[c] = (uint8_t)red;

            while(q.empty() != true)
            {
                
                auto thisNode = q.front();
                q.pop();
                
                auto parentColor = (uint8_t)color[thisNode];
                auto complement = parentColor == (uint8_t)red ? blue: red;
                auto & component = graph[thisNode];

                for(auto n: component)
                {
                    if(color[n] == 0) { 
                        color[n] = complement;
                        q.push(n);
                        continue; 
                    }
                    if(color[n] == parentColor) {r = false; break;};
                }

            }
        }
        
        return r;
    }
};
__________________________________________________________________________________________________
sample 11116 kb submission
class Solution {
public:
    
    bool isGraphBipartite(vector<vector<int>>& graph, vector<int> & c, int n)
    {
        if(n == c.size()) return false;
        if (graph[n].empty()) return true;

        for (int i = 0; i < graph[n].size(); ++i) {
            int j = graph[n][i];
            if (c[j] == -1) {
                c[j] = !c[n];
                if (isGraphBipartite(graph, c, j) == false)
                    return false;
            }
            else if (c[j] == c[n])
                return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> c;
        int color = -2;
        int n = 0;

        for (int i = 0; i < graph.size(); ++i) {
            if(color == -2 && !graph[i].empty())
            {
                color = -1;
                n = i;
                c.push_back(0);
            }
            else
                c.push_back(color);
        }

        bool r = isGraphBipartite(graph, c, n);
        
        for (int i = 0; i < c.size(); ++i) {
            if(c[i] == -1 && c[i] != -2){
                r &= isGraphBipartite(graph, c, i);
            }
        }
            
        return r;
    }
};

static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
__________________________________________________________________________________________________
