__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        for (int i = 1; i <= 10; ++i) {
            for (int j = 1; j <= 10; ++j) {
                vector<int> result;
                if (canSplit(S, i, j, result)) {
                    return result;
                }
            }
        }
        return {};
    }
private:
    bool myStoi(const string& s, int& num) {
        if (s.empty() ||
            s[0] == '0' && s.size() > 1 ||
            s.size() > 10 ||
            s.size() == 10 && s > to_string(std::numeric_limits<int>::max())
        ) {
            return false;
        }
        num = stoi(s);
        return true;
    }
    bool canSplit(const string& s, int i, int j, vector<int>& result) {
        int num1 = 0;
        int num2 = 0;
        if (!(i + j <= s.size() &&
             myStoi(s.substr(0, i), num1) &&
             myStoi(s.substr(i, j), num2))
        ) {
            return false;
        }
        result.push_back(num1);
        result.push_back(num2);
        while (true) {
            int64_t num_i64 = static_cast<int64_t>(num1) + static_cast<int64_t>(num2);
            if (num_i64 > 2147483647) {
                return false;
            }
            string s_expected = to_string(num_i64);
            i += j;
            j = s_expected.size();
            if (!(i + j <= s.size() && s_expected == s.substr(i, j))) {
                return false;
            }
            num1 = num2;
            num2 = num_i64;  // no overflow, has checked at line 34.
            result.push_back(num2);
            if (i + j == s.size()) {
                return true;
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________
sample 8824 kb submission
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int>nums;
        backtrack(S, 0, nums);
        return nums;
    }
    
    bool backtrack(const string& S, int start, vector<int>&nums){
        if(start == S.size() && nums.size() >=3){
            return true;
        }
        
        for(int i = 1;i < 11 && start + i <= S.size(); i++) {
            if(S[start] == '0' && i > 1) {
                return false;
            }
            
            long num = stol(S.substr(start, i));
            
            if(num > INT_MAX) {
                return false;
            }
            
            if(nums.size() < 2 || (long)nums[nums.size()-1] + (long)nums[nums.size()-2] == num) {
                nums.push_back((int)num);
                if(backtrack(S, start + i, nums)) return true;
                nums.pop_back();
            }
        }
        return false;
    }
};
__________________________________________________________________________________________________
