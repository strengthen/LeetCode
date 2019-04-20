__________________________________________________________________________________________________
8ms
class Solution {
public:
    int jump(vector<int>& nums) {
        int cur_max_end = 0;
        int next_max_end = 0;
        int length = nums.size();
        if (length < 2) return 0;
        int count = 0;
        for (int i = 0; i < length; ++i) {
            // cout << "cur_max_end: " << cur_max_end << endl;
            // cout << "next_max_end: " << next_max_end << endl;
            if (cur_max_end == 0) {
                cur_max_end = i + nums[i];
                next_max_end = cur_max_end;
                ++count;
                if (next_max_end >= length - 1) return count;
            } else if (i <= cur_max_end) {
                auto tmp = i + nums[i];
                if (tmp > next_max_end) {
                    next_max_end = tmp;
                } else {
                    continue;
                }
            } else {
                ++count;
                cur_max_end = next_max_end;
                next_max_end = max(next_max_end, i + nums[i]);
            }
            if (next_max_end >= length - 1) break;
            
        }
        return count + 1;
    }
};

auto ___ = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
__________________________________________________________________________________________________
12ms
 class Solution {
 public:
	 int jump(vector<int>& nums) {
		 int pos = 0;
		 int jump = 0;
		 int jump_num = 0;
		 while (pos<nums.size()) {
			 int max_j = 0;
			 for (int i = 0; i <= nums[pos]; i++) {
				 if (pos + i == nums.size() - 1) {
					 if (i == 0) {
						 return jump;
					 }
					 return jump + 1;
				 }
				 if (i + nums[pos + i]>=max_j) {
					 max_j = i + nums[pos + i];
					 jump_num = i;
				 }

			 }
			 pos = pos + jump_num;
			 jump++;
		 }
		 return jump;
	 }
 };
__________________________________________________________________________________________________
16ms
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==0||n==1)
            return 0;
        int temp,p=0,step=0,right=0;
        while(p<n)
        {
            step++;
            temp=right;
            for(int i=p;i<=temp;i++)
                right=max(right,i+nums[i]);
            if(right>=n-1)
                return step;
            p++;
        }
        return step;
    }
};
__________________________________________________________________________________________________
9924 kb
static int speedup = [](){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0|| n == 1){
            return 0;
        }
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                nums[i] = 1;
            }
        }
        int jump_count = 1;
        int end = nums[0];
        int t = end;
        if(t >= n-1){
            return jump_count;
        }
        // range initially is 0 to nums[0];
        int k = 1;
        while(k < n){
            jump_count++;
            while(k <= end){
                t = max(t, k + nums[k]);
                if(t >= n-1){
                    return jump_count;
                }
                k++;
            }
            if(k > t){
                return -1;
            }else{
                end = t;
            }
        }
        return -1;
    }
};
__________________________________________________________________________________________________
10228 kb
static int speedup = [](){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1){
            return 0;
        }
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                nums[i] = 1;
            }
        }
        
        vector<int> num_jumps(n,n-1);
        num_jumps[0] = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(j + nums[j] >= i){
                    num_jumps[i] = min(num_jumps[i], num_jumps[j]+1);
                }
            }
        }
        return num_jumps[n-1];
    }
};
__________________________________________________________________________________________________