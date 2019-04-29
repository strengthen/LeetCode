__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> temp;
        int j = 0;
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        for(int i = 0; i < pushed.size() ; ++i)
        {
            temp.push(pushed[i]);
            while(!temp.empty()  and temp.top() == popped[j])
            {
                temp.pop();
                ++j;
            }
        }
        return temp.empty() ;
        
    }
};
__________________________________________________________________________________________________
sample 9044 kb submission
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
public:
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {
        int pu = 0;
        int po = 0;
        std::stack<int> s;
        while (true) {
            if (!s.empty() && po < popped.size() && s.top() == popped[po]) {
                s.pop();
                ++po;
            } else if (pu < pushed.size()) {
                s.push(pushed[pu++]);
            } else if (po == popped.size()) {
                return true;
            } else {
                return false;
            }
        }
    }
};
__________________________________________________________________________________________________
