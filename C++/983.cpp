__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> values(366, 0);
        int pos = 0;
        for (int i = 1; i <= 365 && pos < days.size(); i++) {
            if (i == days[pos]) {
                int value = values[i - 1] + costs[0];
                if (i - 7 <= 0) {
                    value = min(value, costs[1]);
                }
                if (i - 7 > 0) {
                    value = min(value, values[i - 7] + costs[1]);
                }
                if (i - 30 <= 0) {
                    value = min(value, costs[2]);
                }
                if (i - 30 > 0) {
                    value = min(value, values[i - 30] + costs[2]);
                }
                values[i] = value;
                pos++;
            } else {
                values[i] = values[i - 1];
            }
        }
        return values[days[days.size() - 1]];
    }
};
__________________________________________________________________________________________________
sample 8876 kb submission
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> mincost(days.size(),INT_MAX);
        mincost[days.size()-1] = costs[0];
        for(int i=days.size()-2; i>=0;i--){
            int current = days[i];
            //cout<<"daysi"<<days[i]<<endl;
            int curr_7 = current + 7;
            int curr_30 = current + 30;
            int cost = mincost[i];
            int j = i+1;
            while(j < days.size() && days[j] < (current+7))
                j++;
            if(j < days.size())
                cost = min(cost, costs[1] + mincost[j]);
            else
                cost = min(cost, costs[1]);
            while(j < days.size() && days[j] < (current+30))
                j++;
            if(j < days.size())
                cost = min(cost, costs[2] + mincost[j]);
            else
                cost = min(cost, costs[2]);
            mincost[i] = min(cost, mincost[i+1]+costs[0]);
            //cout<<i<< "mincost "<<mincost[i]<<endl;
        }
        return mincost[0];
    }
};
__________________________________________________________________________________________________
