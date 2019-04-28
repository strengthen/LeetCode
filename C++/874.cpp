__________________________________________________________________________________________________
sample 64 ms submission

static auto x = [](){std::ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr;}();

class Solution{
private:
	struct pairHash{
		size_t operator()(const pair<int,int>& val) const{
			return val.first^val.second;
		}
	};

public:
	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles){
		unordered_set<pair<int,int>,pairHash> otable;
		
		for(int i=0;i<obstacles.size();i++)
			otable.emplace(pair<int,int> (obstacles[i][0],obstacles[i][1]));
		
		int step[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
		
		int x=0,y=0,dir=0,ans=0;
		
		for(int i=0;i<commands.size();i++){
			if(commands[i]==-1)
                dir=(dir+3)%4;
			else if(commands[i]==-2) 
                dir=(dir+1)%4;
			else
            {
				while(commands[i]-- >0 && !otable.count(pair<int,int> (x+step[dir][0],y+step[dir][1]))){
					x+=step[dir][0];
					y+=step[dir][1];
				};
            }
			ans=max(ans,x*x+y*y);
		}
		
		return ans;
	}
};
__________________________________________________________________________________________________
sample 20544 kb submission
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int flag = 0;
        int x = 0, y = 0;
        int max = 0;
        for(int i = 0; i != commands.size(); ++i)
        {
          if(flag == 0)
          {
            if(commands[i] == -1)
            {
              flag = 1;
              continue;
            }
            else if(commands[i] == -2)
            {
              flag = 2;
              continue;
            }
            else
            {
              for(int j = 0; j != commands[i]; ++j)
              {
                y++;
                int obs = 0;
                for(int k = 0; k != obstacles.size(); ++k)
                {
                  if(x == obstacles[k][0] && y == obstacles[k][1])
                  {
                    y--;
                    obs = 1;
                    break;
                  }
                }
                if(obs == 1)
                  break;
              }
            }          
          }
          else if(flag == 1)
          {
            if(commands[i] == -1)
            {
              flag = 3;
              continue;
            }
            else if(commands[i] == -2)
            {
              flag = 0;
              continue;
            }
            else
            {
              for(int j = 0; j != commands[i]; ++j)
              {
                x++;
                int obs = 0;
                for(int k = 0; k != obstacles.size(); ++k)
                {
                  if(x == obstacles[k][0] && y == obstacles[k][1])
                  {
                    x--;
                    obs = 1;
                    break;
                  }
                }
                if(obs == 1)
                  break;
              }
            }
          }
          else if(flag == 2)
          {
            if(commands[i] == -1)
            {
              flag = 0;
              continue;
            }
            else if(commands[i] == -2)
            {
              flag = 3;
              continue;
            }
            else
            {
              for(int j = 0; j != commands[i]; ++j)
              {
                x--;
                int obs = 0;
                for(int k = 0; k != obstacles.size(); ++k)
                {
                  if(x == obstacles[k][0] && y == obstacles[k][1])
                  {
                    x++;
                    obs = 1;
                    break;
                  }
                }
                if(obs == 1)
                  break;
              }           
            }
          }
          else if(flag == 3)
          {
            if(commands[i] == -1)
            {
              flag = 2;
              continue;
            }
            else if(commands[i] == -2)
            {
              flag = 1;
              continue;
            }
            else
            {
              for(int j = 0; j != commands[i]; ++j)
              {
                y--;
                int obs = 0;
                for(int k = 0; k != obstacles.size(); ++k)
                {
                  if(x == obstacles[k][0] && y == obstacles[k][1])
                  {
                    y++;
                    obs = 1;
                    break;
                  }
                }
                if(obs == 1)
                  break;
              }
            }
          }
          int tmp = x*x + y*y;
          if(tmp > max)
            max = tmp;  
        }
        return max;
    }
};
__________________________________________________________________________________________________
