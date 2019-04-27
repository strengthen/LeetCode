__________________________________________________________________________________________________
sample 40 ms submission
int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

struct Pos {
    int idx;
    int qIdx;
    int val;
    
    bool operator<(const Pos& p)const {
        return val > p.val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int upper = INT_MIN;
        int lower = INT_MAX;
        priority_queue<Pos> q;
        const int k = nums.size();
        for (int i = 0;i < k;i++) {
            if (nums[i].size() == 0) {
                return {};
            }
            
            q.push({0, i, nums[i][0]});
            upper = max(upper, nums[i][0]);
            lower = min(lower, nums[i][0]);
        }
        vector<int> ans = {lower, upper};
        
        while (q.size() == k) {
            auto p = q.top();
            q.pop();
            lower = p.val;
            
            if (upper-lower < ans[1]-ans[0]) {
                ans[0] = lower;
                ans[1] = upper;
            }
            
            p.idx++;
            if (p.idx < nums[p.qIdx].size()) {
                p.val = nums[p.qIdx][p.idx];
                q.push(p);
                
                upper = max(upper, p.val);
            }
        }
        
        return ans;
    }
};
__________________________________________________________________________________________________
sample 13156 kb submission
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int minElement;
        int maxElement;
        int diff = INT_MAX;
        int n = nums.size();
        
        vector<int> index(n,0);
        while(true){
            //cout<<"**"<<endl;
            bool conti = true;
            for(int i=0;i<index.size();i++){
                if(index[i]==nums[i].size()){
                    conti = false;
                    break;
                }
            }
            
            if(conti==false)
                break;
            
            int minIndex;
            int curMin, curMax;
            curMin = INT_MAX;
            curMax = INT_MIN;
            
            for(int i=0;i<n;i++){
                if(nums[i][index[i]]<curMin){
                    curMin = nums[i][index[i]];
                    minIndex=i;
                }
                if(nums[i][index[i]]>curMax){
                    curMax = nums[i][index[i]];
                }
            }
            if(diff> (curMax-curMin)){
                diff = (curMax-curMin);
                //cout<<curMin<<" "<<curMax<<" "<<minElement<<" "<<maxElement<<endl;
                minElement = curMin;
                maxElement = curMax;
            }
            //cout<<minIndex<<endl;
            index[minIndex]++;
            
            
        }
        return vector<int>{minElement, maxElement};
    }
};
__________________________________________________________________________________________________
