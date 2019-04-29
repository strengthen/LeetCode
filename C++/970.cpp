__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> res;
        unordered_set<int> s;
        int tx=1, ty=1, ts ;
        vector<int> xs, ys;
        while(1){
            xs.push_back(tx);
            tx*=x;
            if(tx >= bound || tx==xs.back()) break;
        }
        while(1){
            ys.push_back(ty);
            ty*=y;
            if(ty >= bound || ty == ys.back()) break;
        }
        for(int i=0; i < xs.size(); i++ ){
            for(int j=0; j<ys.size(); j++){
                ts = xs[i]+ys[j];
                if(ts > bound) break;
                s.insert(ts);
            }
        }
        copy(begin(s), end(s), back_inserter(res));
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        for (int i = 1; i <= bound; i *= x) {
            for (int j = 1; i + j <= bound; j *= y) {
                s.insert(i + j);
                if (y == 1) break;
            }
            if (x == 1) break;

        }
        return vector<int>(s.begin(), s.end());
    }
};
__________________________________________________________________________________________________
