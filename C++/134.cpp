__________________________________________________________________________________________________
4ms
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int minc = 0;
        int inx = -1;
        for(int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];
            if(total < minc){
                minc = total;
                inx = i;
            }
        }
        if(total < 0) return -1;
        else return (inx+1)%gas.size();
    }
};

static int x = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
__________________________________________________________________________________________________
 8792 kb
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int st = 0;
        int cur = st;
        int tank = 0;
        int len = gas.size();
        while(true){
            tank = tank+gas[cur]-cost[cur];
            cur = (cur+1)%len;
            if(tank >= 0){  //解的唯一性
                if(cur == st) return st;
            }else{
                if(cur <= st) return -1;
                else{
                    st = cur;
                    tank = 0;
                }
            }
        }
    }
};
__________________________________________________________________________________________________
