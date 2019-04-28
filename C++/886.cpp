__________________________________________________________________________________________________
sample 140 ms submission
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> graph;
    vector<int> colors; // white -1 red 0 blue 1 black 2
    
    bool dfsPaintColor(int i, int color)
    {
        if(colors[i] < 0)
        {
            colors[i] = color;
            for(int node : graph[i])
            {
                if(!dfsPaintColor(node, (color + 1) % 2))
                    return false;
            }
            colors[i] = 2;
        }
        else if(!(colors[i] >> 1))
        {
            return color == colors[i];
        }
        return true;
    }

	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        graph.resize(N + 1);
        colors.resize(N + 1, -1);
        
        for(const auto& pair : dislikes)
        {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
        
        for(int i = 1; i < N; ++i)
        {
            if(!dfsPaintColor(i, 0))
                return false;
        }
        return true;
	}
};
__________________________________________________________________________________________________
sample 47800 kb submission
class Solution {
    unordered_map<int, char> s;
    bool first{true};
    int count =0;
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        
        vector<vector<int>> again;
        for(const auto& item: dislikes){
            if(s.count(item[0]) == 0){
                
                if(s.count(item[1]) == 0){
                    if(first){
                        s[item[0]] = 'a';
                        s[item[1]] = 'b';
                        first=false;
                    }
                    else
                        again.push_back(item);
                }
                else {
                     if(s[item[1]] == 'b')
                         s[item[0]] = 'a';
                    else
                        s[item[0]] = 'b';
                    
                }
            
            }
            else{
                if(s[item[0]] == 'a'){
                    if(s.count(item[1]) == 0)
                        s[item[1]] = 'b';
                    else if(s[item[1]] != 'b')
                        return false;
                    
                }else if(s[item[0]] == 'b'){
                    if(s.count(item[1]) == 0)
                        s[item[1]] = 'a';
                    else if(s[item[1]] != 'a')
                        return false;
                }
                
            }
        }
        
        if(again.empty())
          return true;
        
        count++;
        if(count ==2)
        first =true;
        return possibleBipartition(N, again);
    }
};
__________________________________________________________________________________________________
