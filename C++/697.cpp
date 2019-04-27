__________________________________________________________________________________________________
sample 20 ms submission
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        std::unordered_map<int,std::tuple<int,int,int>>count;
        for(int i=0;i<nums.size();i++){
            auto it = count.find(nums[i]);
            if(it==count.end()){
                count[nums[i]] = std::make_tuple(1,i,i+1);
            }else{
                std::get<0>(it->second)++;
                std::get<2>(it->second) = i+1;
            }
        }
        
        int res = nums.size();
        int degree = 0;
        for(auto it=count.begin();it!=count.end();++it){            
            if(std::get<0>(it->second)>degree){
                degree = std::get<0>(it->second);
                res = std::get<2>(it->second)-std::get<1>(it->second);
            }else if(std::get<0>(it->second)==degree && res>(std::get<2>(it->second)-std::get<1>(it->second))){ 
                res = std::get<2>(it->second)-std::get<1>(it->second);
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 12216 kb submission
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int num_count[50010] = { 0 };
        int num_low[50010] = {0};
        int max_count = 1, n = nums.size(), result = 50000;
        for(int i = 0; i < n; i++){
            num_count[nums[i]] += 1;
            if(num_count[nums[i]] == 1)
                num_low[nums[i]] = i;
            if(max_count < num_count[nums[i]]){
                max_count = num_count[nums[i]];
                result = i - num_low[nums[i]] + 1;
            }
            if(max_count == num_count[nums[i]]){
                if(i - num_low[nums[i]] + 1 < result)
                    result = i - num_low[nums[i]] + 1;
            }                
        }
        return result;
    }
};
__________________________________________________________________________________________________
