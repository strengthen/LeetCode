__________________________________________________________________________________________________
sample 48 ms submission
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
      std::ios_base::sync_with_stdio(false);
      cin.tie(0);
      cout.tie(0);
      std::vector<int> bx(initialBoxes.begin(), initialBoxes.end());
      bool changed = false;
      int result = 0;  
      do {
        changed = false;  
        std::vector<int> bm;  
        for(int b : bx) {
          if( status[b] == 1) {
            status[b] = 2;
            result += candies[b];
            for(int k : keys[b]) {
              if( status[k] == 0 )  
                status[k] = 1;  
            }
            bm.insert(bm.end(), containedBoxes[b].cbegin(), containedBoxes[b].cend());
            changed = true;  
          } else if( status[b] == 0 )
            bm.push_back(b);  
        }
        std::sort(bm.begin(), bm.end());
        bm.erase(std::unique(bm.begin(), bm.end()), bm.end());  
        std::swap(bm, bx);  
      } while(changed);
      return result;  
    }
};
__________________________________________________________________________________________________
sample 60 ms submission
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        std::ios_base::sync_with_stdio(false);
        int size = status.size();
        vector<bool> foundBox(size, false);
        vector<bool> foundKey(size, false);
        queue<int> store;
        for (int i=0; i<initialBoxes.size(); ++i){
            store.push(initialBoxes[i]);
            foundBox[initialBoxes[i]] = true;
        }
        while (!store.empty()){
            int temp = store.front();
            store.pop();
            for(int i=0; i<keys[temp].size(); ++i){
                foundKey[keys[temp][i]] = true;
            }
            for(int i=0; i<containedBoxes[temp].size(); ++i){
                foundBox[containedBoxes[temp][i]] = true;
                store.push(containedBoxes[temp][i]);
            }
        }
        int ret = 0;
        for (int i=0; i<size; ++i){
            if (!foundBox[i]) continue;
            if (status[i] == 1 || foundKey[i] == true) ret+=candies[i];
        }
        return ret;
    }
};
__________________________________________________________________________________________________
