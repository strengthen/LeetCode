__________________________________________________________________________________________________
sample 8 ms submission
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        deque<int> q;
        q.push_back(asteroids[0]);
        
        int n = asteroids.size();
            
        for (int i = 1; i < n;)
        {
            if (!q.empty() && q.back() > 0 && asteroids[i] < 0)
            {
                if (std::abs(q.back()) < std::abs(asteroids[i]))
                {
                    q.pop_back();
                    continue;
                }

                if (std::abs(q.back()) == std::abs(asteroids[i]))
                    q.pop_back();
            }
            else
                q.push_back(asteroids[i]);
 
            ++i;
        }
        
        vector<int> v;
        
        while (!q.empty())
        {
            v.push_back(q.front());
            q.pop_front();
        }
        
        return v;
    }
};
__________________________________________________________________________________________________
sample 10904 kb submission
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        
        for(int i : asteroids){
            while(!res.empty() && res.back() > 0 && res.back() < -i){
                res.pop_back();
            }
            
            if(res.empty() || res.back() < 0 || i > 0){
                res.push_back(i);
            }else if(res.back() == -i){
                res.pop_back();
            }
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
