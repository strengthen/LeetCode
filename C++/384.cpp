__________________________________________________________________________________________________
sample 188 ms submission
static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
private:
    vector<int> ori,suf;   
    vector<int> Fisher_Yates_Shuffle(void)
    {
        vector<int> ans;
        
        //srand((unsigned) time(nullptr));
        while(!suf.empty())
        {
            int i = rand() % suf.size();
            ans.push_back(suf[i]);
            suf.erase(suf.begin() + i);
        }
        suf = ans;
        
        return ans;
    }
    vector<int>  Knuth_Durstenfeld_Shuffle(void)
    {
        for(int i = suf.size() - 1;i >= 0;--i)
        {
            swap(suf[rand() % (i + 1)],suf[i]);
        }
        return suf;
    }
    vector<int>  Inside_Out_Shuffle(void)
    {
        vector<int> ans(suf);
        
        for(int i = 0;i < suf.size();++i)
        {
            int k = rand() % (i + 1);
            ans[i] = ans[k];
            ans[k] = suf[i];
        }
        suf = ans;
        
        return ans; 
    }
public:
    Solution(vector<int>& nums) :ori(nums),suf(nums) {
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ori;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        //return  Fisher_Yates_Shuffle();
        //return Knuth_Durstenfeld_Shuffle();
          return Inside_Out_Shuffle();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
__________________________________________________________________________________________________
sample 29956 kb submission
class Solution {
public:
    vector<int> orignal;
    Solution(vector<int> nums) {
        orignal = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return orignal;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result = orignal;
        for (int i = 0; i < result.size()*2; i++) {
            int first = rand()%result.size();
            int second = rand()%result.size();
            int t = result[first];
            result[first] = result[second];
            result[second] = t;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
__________________________________________________________________________________________________
