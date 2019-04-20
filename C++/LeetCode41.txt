__________________________________________________________________________________________________
4ms
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int max = 0;
        for (auto &n : nums) {
            if (n > max) max = n;
        }
        if (max == 0) return 1;
        if (max == 1) return max+1;
    
        int i = 1;
        for (; i <= max; i++ ) {
            int j = 0;
            for (; j < nums.size(); j++ ) {
                if (i == nums[j]) break; // found this number
            }
            if ( j == nums.size() ) // not found
                return i; // first missing positive number
        }
        return i; // there are no missing number so next missing no is i 
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0)
            return 1;
        
        for(int i = 0; i < nums.size(); i ++){
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i] != i + 1)
                return i + 1;
        }
        
        return nums.size() + 1;
    }
};
__________________________________________________________________________________________________
8ms
// NOT constant space
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mx = 0;
        unordered_set<int> s;
        for (int num : nums) {
            if (num <= 0) continue;
            s.insert(num);
            mx = max(mx, num);
        }
        for (int i = 1; i <= mx; ++i) {
            if (!s.count(i)) return i;
        }
        return mx + 1;
    }
};
__________________________________________________________________________________________________
8668 kb
static int speedup = [](){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int n = A.size();
        if(n == 0){
            return 1;
        }
        
        int p = 0;
        while(p < n){
            int now = A[p];
            if(now > 0 && now <= n && (now != p+1) && A[now-1] != now){
                A[p] = A[now-1];
                A[now-1] = now;
            }else{
                p++;
            }
        }
        
        p = 0;
        while(p < n && A[p] == p+1){
            p++;
        }
        return p+1;
    }
};
__________________________________________________________________________________________________
9336 kb
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= 0 || nums[i] > nums.size())
                nums[i] = nums.size() + 1;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            
            int index = nums[i];
            if (index < 0) index *= -1;
            index--;
            
            if (index < nums.size()) {
                if (nums[index] > 0)
                    nums[index] = nums[index] * -1;
            }
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >=0 ) {
                return i+1;
            }
        }
        
        return nums.size() + 1;
    }
};
__________________________________________________________________________________________________