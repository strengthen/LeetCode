__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, special.size()-1, needs);
    }
    int dfs(vector<int> &price, vector<vector<int>> &special, int k, vector<int> &needs){
        if(k<0){
            int pay = 0;
            for(int i=0;i<needs.size();++i)pay+=price[i]*needs[i];
            return pay;
        }
        if(check_offer(special[k], needs)){
            int pay = dfs(price, special, k-1, needs);
            for(int i=0;i<needs.size();++i){
                needs[i] -= special[k][i];
            }
            pay = min(pay, special[k][special[k].size()-1]+dfs(price, special, k, needs));
            for(int i=0;i<needs.size();++i){
                needs[i] += special[k][i];
            }
            return pay;
        }else{
            return dfs(price, special, k-1, needs);
        }
    }
    bool check_offer(vector<int> &offer, vector<int> &need){
        for(int i=0;i<need.size();++i)
            if(offer[i]>need[i])return false;
        return true;
    }
};
__________________________________________________________________________________________________
sample 9312 kb submission
class Solution {
public:
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& need,int cost) {
	int m = price.size(), n = special.size();
	for (int i = 0; i < m; ++i) {
		if (need[i] < 0) return INT_MAX;
	}
	int res = cost;
	for (int i = 0; i < price.size(); ++i)
		res += price[i] * need[i];
	for (int i = 0; i < n; ++i) {
		if (cost + special[i].back() >= res) continue;
		for (int j = 0; j < m; ++j) {
			need[j] -= special[i][j];
		}
		res = min(res, dfs(price, special, need, cost + special[i].back()));
		for (int j = 0; j < m; ++j) {
			need[j] += special[i][j];
		}
	}
	return res;
}

int shoppingOffers(vecto
__________________________________________________________________________________________________
