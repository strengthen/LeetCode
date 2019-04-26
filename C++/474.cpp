__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //const unsigned int s = strs.size();
        
        array<tuple<int,int>, 601> res;//amount of 0 and 1 for each string
        size_t ind_ar = 0;
        for (auto it = strs.begin(); it != strs.end(); ++it){
            int z = 0, o = 0;
            //cout << *it << " ";
            for (size_t i = 0; i < it->size(); ++i){
                switch ((*it)[i]){
                    case '1':
                        ++o;
                        break;
                    case '0':
                        ++z;
                        break;
                    default:
                        break;
                }
            }
            //cout << z << " " << o << endl;
            res[ind_ar] = make_tuple(z, o);
            ++ind_ar;
        }
        array<tuple<int,int>,601>::iterator it = &res[strs.size()];
        //common sum increasing
        sort(res.begin(), it,[m, n](tuple<int,int> a, tuple<int,int>b){
            if (get<0>(a) + get<1>(a) == get<0>(b) + get<1>(b)){
                if (m <= n) return get<0>(a) < get<0>(b);
                else return get<1>(a) < get<0>(b);
            }
            else return(get<0>(a) + get<1>(a) < get<0>(b) + get<1>(b));
        });
        // for (auto i = 0; i < strs.size(); ++i){
        //     cout << get<0>(res[i]) << " " << get<1>(res[i]) << endl;
        // }
        int result = 0;
        ind_ar = 0;
        int mc = m, nc = n;
        while ((mc > 0 || nc > 0) && ind_ar < strs.size()){
            if (mc - get<0>(res[ind_ar]) >= 0 && nc - get<1>(res[ind_ar]) >=0){
                mc-=get<0>(res[ind_ar]);
                nc-=get<1>(res[ind_ar]);
                result+=1;
            }
            ind_ar+=1;
        }
        // cout << result <<endl;
        // cout << endl;
        //sum zeroes increasing
        int result1 = 0;
        mc = m; nc = n;
        sort(res.begin(), it,[](tuple<int,int> a, tuple<int,int>b){
            return (get<0>(a) < get<0>(b));
        });
        // for (auto i = 0; i < strs.size(); ++i){
        //     cout << get<0>(res[i]) << " " << get<1>(res[i]) << endl;
        // }
        ind_ar = 0;
        while ((mc > 0 || nc > 0) && ind_ar < strs.size()){
            if (mc - get<0>(res[ind_ar]) >= 0 && nc - get<1>(res[ind_ar]) >=0){
                mc-=get<0>(res[ind_ar]);
                nc-=get<1>(res[ind_ar]);
                result1+=1;
            }
            ind_ar+=1;
        }
        // cout << result1 << endl;
        // cout << endl;
        //sum ones increasing
        int result2 = 0;
        mc = m; nc = n;
        sort(res.begin(), it,[](tuple<int,int> a, tuple<int,int>b){
            return (get<1>(a) < get<1>(b));
        });
        // for (auto i = 0; i < strs.size(); ++i){
        //     cout << get<0>(res[i]) << " " << get<1>(res[i]) << endl;
        // }
        ind_ar = 0;
        while ((mc > 0 || nc > 0) && ind_ar < strs.size()){
            if (mc - get<0>(res[ind_ar]) >= 0 && nc - get<1>(res[ind_ar]) >=0){
                mc-=get<0>(res[ind_ar]);
                nc-=get<1>(res[ind_ar]);
                result2+=1;
            }
            ind_ar+=1;
        }
        // cout << result2 << endl;
        // cout << endl;
        int r = max(result, result1);
        r = max(r, result2);
        return r; 
    }
};
__________________________________________________________________________________________________
sample 9456 kb submission
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if(strs.size() == 0)
            return 0;
        int dp[m+1][n+1];
        for(int i = 0; i < m+1; ++i){
            for(int j = 0; j< n+1; ++j){
                dp[i][j] = 0;
            }
        }
        for(auto word: strs){
            int zeros = 0, ones = 0;
            for(auto c: word){
                if(c == '0')++zeros;
                else
                    ++ones;
            } 
            for(int i = m; i >= zeros; --i){
                for(int j = n; j >= ones; --j){
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
__________________________________________________________________________________________________
