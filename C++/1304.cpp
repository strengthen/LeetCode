__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    vector<int> sumZero(int n) {

        vector<int> res;
        if(n % 2) res.push_back(0), n --;
        while(n) res.push_back(n), res.push_back(-n), n -= 2;
        return res;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<int> sumZero(int n) {
            vector<int> arr;
            if(n%2!=0) arr.push_back(0);
            for(int i=1;i<=n/2;i++){
                arr.push_back(-i);
                arr.push_back(i);
            }
            return arr;
    }
};
__________________________________________________________________________________________________
