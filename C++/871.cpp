__________________________________________________________________________________________________
sample 20 ms submission
static int x = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

class Solution {
  public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        //ans表示最后结果，即最小加油次数
        //pos表示当前卡车位置
        //tank表示油缸中油的数量
        //que优先队列中存放之前能通过的各个加油站的最大加油量Bi
        priority_queue<pair<int,int> > que;
        int ans=0,pos=0,tank=startFuel;
        vector<int> c;
        c.push_back(target);//这里要把终点也算进去
        c.push_back(0);//0代表终点没有油桶
        stations.push_back(c);
        for(int i=0; i<stations.size(); i++) {
            int curDist=stations[i][0]-pos;   //curDist表示到达下一个临时终点(加油站)的距离
            while(curDist>tank) {    //当前油不够到下一个终点
                if(que.empty()) {
                    return -1;
                }
                pair<int,int> temp=que.top();
                que.pop();
                tank+=temp.first;         //不断加油,直到能到达下一个终点
                ans++;
            }
            tank-=curDist;          //跑到下一个终点，消耗 curDist数量的油
            pos=stations[i][0];               //到达下一个加油站，取得该加油站的油，放在优先队列中，以便后面使用
            que.push(make_pair(stations[i][1],i));

        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 13976 kb submission
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
            
        //dp[i] : max distance to go with i stops.
        vector<long> dp(n+1, startFuel);
        
        for(int i = 0; i < n; ++i){
            // for j stops, start from high to low to avoid reusing station i
            for(int j = i+1; j >=1; --j){
                if(dp[j-1] >= stations[i][0]){
                    dp[j] = max(dp[j], dp[j-1] + stations[i][1]);
                }
            }
        }
        
        for(int i = 0; i < n+1; i ++){
            if(dp[i] >= target) return i;
        }
        
        return -1;
        
    }
};
__________________________________________________________________________________________________
