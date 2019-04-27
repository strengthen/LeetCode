__________________________________________________________________________________________________
sample 40 ms submission
class KthLargest final {
    int m;
    const int k;
    priority_queue<int, vector<int>, greater<>> q;

public:
    KthLargest(const int k, vector<int>& nums) noexcept : m(INT_MIN), k(k) {
        if (k == 1) {
            if (!nums.empty()) m = *max_element(nums.cbegin(), nums.cend());
            return;
        }

        if (nums.size() > k) {
            nth_element(nums.begin(), nums.begin() + (k - 1), nums.end(), greater<>());
            nums.resize(k);
        }
        q = {nums.cbegin(), nums.cend()};
    }

    int add(const int val) noexcept {
        if (val <= m) return m;
        if (k == 1) return m = val;
        q.push(val);
        if (q.size() > k) q.pop();
        return m = q.top();
    }
};

static const auto speedup = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
__________________________________________________________________________________________________
sample 19232 kb submission
class KthLargest {
public:
    KthLargest(int k, vector<int> nums):v{nums.begin(), nums.begin()+ std::min(k, (int)nums.size())}, k(k) {
        
        std::make_heap(v.begin(), v.end(), f);
        
        for(auto i = k ; i < nums.size() ; i++){
            
            if(v.front() < nums[i]){
                
                std::pop_heap(v.begin(), v.end(), f);
                v.pop_back();
                
                v.push_back(nums[i]);
                std::push_heap(v.begin(), v.end(), f);
            }
        }
    }
    
    int add(int val) {
        
        if(v.size() < k){
            
            v.push_back(val);
            std::push_heap(v.begin(), v.end(), f);
        }else{
            
            if(v.front() < val){
                
                std::pop_heap(v.begin(), v.end(), f);
                v.pop_back();
                
                v.push_back(val);
                std::push_heap(v.begin(), v.end(), f);
            }
        }
        
        return v.front();
    }
    
private:
    vector<int> v;
    const int k;
    const std::function<bool(int, int)> f = [](int a, int b){ return a > b ;}; // min heap
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
__________________________________________________________________________________________________
