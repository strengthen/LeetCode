__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
      std::sort( deck.begin(), deck.end() );
      std::deque<int> dq;
      for( int i = 0; i < deck.size(); ++i ) dq.push_front( i );
      vector<int> res( deck.size() );
      int count = 0;
      while( !dq.empty() )
      {
        res[dq.back()] = deck[count++]; dq.pop_back();
        dq.push_front( dq.back() );
        dq.pop_back();
      }
      return res;
    }
};

static int x = []() {
	// toggle off cout & cin, instead, use printf & scanf
	std::ios::sync_with_stdio(false);
	// untie cin & cout
	cin.tie(NULL);
	return 0;
}();
__________________________________________________________________________________________________
sample 8980 kb submission
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        std::sort(deck.begin(), deck.end());
        vector<int> ans(deck.size(), -1);
        int i = 0, j = 0;
        bool hide = false;
        while(j<deck.size()){
            if(ans[i]==-1){
                if(hide){
                    hide = false;
                }
                else{
                    hide = true;
                    ans[i] = deck[j++];
                }
            }
            i++;
            if(i >=ans.size())
                i = 0;
        }
        return ans;
    }
};
__________________________________________________________________________________________________
