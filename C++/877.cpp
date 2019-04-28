__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        
        int dp_a = max(piles[0],piles[piles.size()-1]);
        int dp_l = min(piles[0],piles[piles.size()-1]); 
        int sum_a = dp_a;
        int sum_l = dp_l;
        for(int i = 1; i<piles.size()/2;i++)
        {
            if(i%2 == 1) // it's alex's turn
            {
                dp_a = max(piles[i],piles[piles.size()-1-i]);
                sum_a += dp_a;
            }
            else
            {
                dp_l = min(piles[i],piles[piles.size()-1-i]);
                sum_l += dp_l;
            }
        }
        if(sum_a > sum_l)
            return true;
        else
            return false;
    }
};
__________________________________________________________________________________________________
sample 8456 kb submission
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true ;
    }
};
__________________________________________________________________________________________________