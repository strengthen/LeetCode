__________________________________________________________________________________________________
12ms
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> single;
        vector<vector<int>> all;
        backtrack(candidates, 0, 0, target, single, all);
        return all;
    }
    
    void backtrack(const vector<int>& candidates, int index, int sum, int target, vector<int> &single, vector<vector<int>> &all) {
        if (sum == target) {
            all.push_back(single);
            return;
        }
        if (sum > target) {
            return;
        }
        for (int i=index; i<candidates.size(); i++) {
            single.push_back(candidates[i]);
            backtrack(candidates, i, sum+candidates[i], target, single, all);
            single.pop_back();
        }
    }
};
__________________________________________________________________________________________________
16ms
class Solution {
public:
    vector<vector<int>> answer;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        
        for(int i=0;i<candidates.size();i++){
                back_track(candidates, target-candidates[i], comb, i);
        }
        return answer;
    }
    
    void back_track(vector<int>& candidates, int target, vector<int>& comb, int index){
        comb.push_back(candidates[index]);
        
        if(target == 0){
            answer.push_back(comb);
        }else if(target > 0){
            for(int i=index;i<candidates.size();i++){
                back_track(candidates, target-candidates[i], comb, i);
            }
        }
        comb.pop_back();
    }
};
__________________________________________________________________________________________________
20ms
class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> currCombination;
        combinationSum(candidates, target, res, currCombination, 0);

        return res;
    }
    
private:
    void combinationSum(const std::vector<int>& candidates, int target, std::vector<std::vector<int>> &res, std::vector<int> currCombination, int begin) {
        if (!target){     // possible solution found!
            res.push_back(currCombination);    // push current solution into stack
            return;
        }
        if (target < 0)     // cannot reach negative number
            return;
        for (int i = begin; i < candidates.size(); i++) {
            int remaining = target-candidates[i];
            if (remaining>=0) {
                currCombination.push_back(candidates[i]); // store potential candidate   
                // CAN CALL SAME index MULTIPLE TIMES
                combinationSum(candidates, target-candidates[i], res, currCombination, i);
                currCombination.pop_back();
            }
        }
        return;
    }
};
__________________________________________________________________________________________________
9472 kb
static int x = [](){ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
    
private:

    void solve(vector<int>& candidates, int target, int idx, vector<int>& current, vector<vector<int>>& results) {
        
        if(target < 0) return;
        
        if(target == 0) {
            results.push_back(current);
            return;
        }
        
        for(int i = idx; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            solve(candidates, target-candidates[i],i,current, results);
            current.pop_back(); // shirnk the vector
        }        
    }    
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> results;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, current, results);
        
        return results;
        
    }
};
__________________________________________________________________________________________________
10040 kb
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        if (candidates.empty() || target <= 0) return results;
        
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        dfs(results, candidates, 0, target, curr);
        return results;
    }
    
private:
    void dfs(vector<vector<int>>& results, vector<int>& candidates, int idx, int target, vector<int>& curr) {
        if (target == 0) {
            results.push_back(curr);
            return;
        }
        if (idx == candidates.size()) return;
        
        for (int i = idx; i < candidates.size(); i++) {
            if (candidates[i] > target) break;
            
            curr.push_back(candidates[i]);
            dfs(results, candidates, i, target-candidates[i], curr);
            curr.pop_back();
        }
    }
};
__________________________________________________________________________________________________