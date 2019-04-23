__________________________________________________________________________________________________
8ms
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int largestRectangleArea(vector<int>& v) 
    {
        int n=v.size();
        vector<int> nsr(n),nsl(n);
        stack<int> c1,c2;
        for(int i=0;i<n;i++)
        {
            while(!c1.empty()&&v[c1.top()]>v[i])
            {
                c1.pop();
                
            }
            nsl[i]=c1.empty()?-1:c1.top();
            c1.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!c2.empty()&&v[c2.top()]>=v[i])
            {
                c2.pop();
                
            }
            nsr[i]=c2.empty()?n:c2.top();
            c2.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int h=v[i];
            int w=nsr[i]-nsl[i]-1;
            ans=max(ans,h*w);
        }
        return ans;
        
    }
};
__________________________________________________________________________________________________
9576 kb
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (i+1 < heights.size() && heights[i] <= heights[i+1]) {
                continue;
            }
            
            int minH = heights[i];
            for (int j = i; j>=0; j--) {
                minH = min(minH, heights[j]);
                int area = minH * (i - j +1);
                res = max(res, area);
            }
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
