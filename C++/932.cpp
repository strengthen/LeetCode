__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res{1};
        while(res.size() < N)
        {
            vector<int> temp;
            for(int i = 0; i < res.size(); ++i)
                if(res[i] * 2 - 1 <= N)
                    temp.push_back(res[i] * 2 - 1);
            for(int i = 0; i < res.size(); ++i)
                if(res[i] * 2 <= N)
                    temp.push_back(res[i] * 2);
            res = temp;
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 9036 kb submission
class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res{1};
        while (res.size() < N) {
            vector<int> temp;
            for (int i = 0; i < res.size(); i++) {
                if (res[i] * 2 - 1 <= N)
                    temp.push_back(res[i] * 2 - 1);
            }
            for (int i = 0; i < res.size(); i++) {
                if (res[i] * 2 <= N)
                    temp.push_back(res[i] * 2);
            }
            swap(temp, res);
        }
        return res;
    }
};
__________________________________________________________________________________________________
