__________________________________________________________________________________________________
sample 40 ms submission
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(W==1) return true;
        if(hand.size()%W) return false;
        
        vector<int> cs(W,0);
        
        for(auto &&i:hand) {
            cs[i%W]++;
        }
        
        int M=hand.size()/W;
        for(auto &&i:cs) {
            if(i!=M) return false;
        }
        return true;
    }
};
__________________________________________________________________________________________________
sample 10408 kb submission
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        std::sort(hand.begin(), hand.end());
        
        while(hand.size() !=0)
        {
            int prev=-1;
            for(int i=0; i<W; i++)
            {
                if(i==0)
                {
                    prev = hand.back();
                    hand.pop_back();
                    continue;
                }
                
                auto it = std::find(hand.begin(), hand.end(), prev-1);
                if(it == hand.end())
                {
                    return false;
                }
                else
                {
                    hand.erase(it);
                    prev = prev-1;
                }
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________
