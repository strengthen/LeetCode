__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        int twenties = 0;
        for (int& b : bills) {
            if (b == 5) ++fives;
            else if (b == 10) {
                ++tens;
                if (fives == 0) return false;
                --fives;
            } else if (b == 20) {
                ++twenties;
                if (tens != 0) {
                    --tens;
                    if (fives == 0) return false;
                    --fives;
                } else if (fives < 3) return false;
                else fives -= 3;
            }
        }
        return true;
    }
};

auto ___ = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
__________________________________________________________________________________________________
sample 9732 kb submission
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> now(2, 0);
        for (auto i:bills){
            if (i == 5){
                now[0]++;
            }else if (i == 10){
                if (now[0] == 0){
                    return false;
                }
                now[1]++;
                now[0]--;
            }else if (i == 20){
                if(now[1] == 0){
                    if (now[0] < 3){
                        return false;
                    }
                    now[0] -= 3;
                }else{
                    if (now[0] == 0){
                        return false;
                    }
                    now[1]--;
                    now[0]--;
                }
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________
