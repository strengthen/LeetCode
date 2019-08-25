__________________________________________________________________________________________________
sample 264 ms submission
class DinnerPlates {
    set<int> free_stacks;
    vector<stack<int>> stacks;
    int capacity;
public:
    DinnerPlates(int capacity) {
        stacks.reserve(10000);
        this->capacity = capacity;
    }
    
    void push(int val) {
        if (free_stacks.size()==0) {
            stacks.emplace_back();
            stacks.back().push(val);
            if (stacks.back().size()<capacity) {
                free_stacks.insert((int)stacks.size()-1);
            }
        } else {
            int first_free = *free_stacks.begin();
            auto&s = stacks.at(first_free);
            s.push(val);
            if (s.size()==capacity) {
                free_stacks.erase(free_stacks.begin());
            }
        }
    }
    
    int pop() {
        return popAtStack((int)stacks.size()-1);
    }
    
    int popAtStack(int index) {
        if (index<0 || index>=stacks.size()) return -1;
        auto&s = stacks.at(index);
        if (s.size()==0) return -1;
        int r = s.top();
        s.pop();
        if (s.size()==capacity-1) {
            free_stacks.insert(index);
        }
        if (s.size()==0) {
            if (index==stacks.size()-1) {
                stacks.pop_back();
                free_stacks.erase(index);
            }
        }
        return r;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
__________________________________________________________________________________________________
sample 272 ms submission
class DinnerPlates {
public:
    // need to know the left not full stacks
    // need to know the right not empty stacks
    vector<vector<int>> nums;
    set<int> lefts;
    set<int> rights;
    int size;
    
    DinnerPlates(int capacity) {
        size = capacity;
    }
    
    void push(int val) {
        if (lefts.empty()) {
            vector<int> temp;
            nums.push_back(temp);
            lefts.insert(nums.size() - 1);
        }
        int idx = *lefts.begin();
        nums[idx].push_back(val);
        if (nums[idx].size() == size) lefts.erase(lefts.begin());
        rights.insert(idx);
    }
    
    int pop() {
        if (rights.empty()) return -1;
        int idx = *rights.rbegin();
        int num = *nums[idx].rbegin();
        nums[idx].pop_back();
        if (nums[idx].empty()) rights.erase(idx);
        lefts.insert(idx);
        return num;
    }
    
    int popAtStack(int index) {
        if (index < 0 || index >= nums.size() || nums[index].empty()) return -1;
        int num = *nums[index].rbegin();
        nums[index].pop_back();
        if (nums[index].empty()) rights.erase(index);
        lefts.insert(index);
        return num;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
__________________________________________________________________________________________________
