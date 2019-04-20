__________________________________________________________________________________________________
4ms
class Solution 
{
public:
    int trap(vector<int>& A) 
    {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int i = 0, j = A.size() - 1, res = 0, leftMax = 0, rightMax = 0;
        while(i <= j)
        {
            if(A[i] <= A[j])
            {
                if(A[i] >= leftMax)
                    leftMax = A[i];
                else
                    res += leftMax - A[i];
                i++;
            }
            else
            {
                if(A[j] >= rightMax)
                    rightMax = A[j];
                else
                    res += rightMax - A[j];
                j--;
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, level = 0, water = 0;
        while (l < r) {
            int lower = height[height[l] < height[r] ? l++ : r--];
            level = max(level, lower);
            water += level - lower;
        }
    return water;
}
};
__________________________________________________________________________________________________
16ms
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, n = height.size();
        vector<vector<int>> range (2, vector<int> (n, 0));
        int left_mx = 0, right_mx = 0;
        for(int i = 0; i < n; i++){  // 记录某处左右侧的最大值
            int j = n - i - 1;
            range[0][i] = left_mx;
            range[1][j] = right_mx;
            left_mx = max(left_mx, height[i]);
            right_mx = max(right_mx, height[j]);            
        }
        for(int i = 0; i < n; i++){
            int cur = min(range[0][i], range[1][i]);
            res += cur > height[i] ? (cur - height[i]) : 0;
        }
        return res;
    }
};
__________________________________________________________________________________________________
9008 kb
class Solution {
public:
    int trap(vector<int>& height) {
        int count0 = 0;
        
        int pos = 0;
        {
            int count1 = 0;
            int limit = 0;

            for (int i = 0; i < height.size(); ++i) {
                if (limit <= height[i]) {
                    limit = height[i];
                    count0 += count1;
                    count1 = 0;
                    pos = i;
                    continue;
                }
                count1 += limit - height[i];
            }
        }
        
        int max = height.size() - pos;
        {
            int count1 = 0;
            int limit = 0;

            for (auto it = height.rbegin(); it != height.rend(); ++it) {
                if (!max--)
                    break;
                if (limit <= *it) {
                    limit = *it;
                    count0 += count1;
                    count1 = 0;
                    continue;
                }
                count1 += limit - *it;
            }
        }
        
        return count0;
    }
};

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
9060 kb
class Solution {
public:
    int trap(vector<int>& height) {
        static int x = [](){
            std::ios::sync_with_stdio(false);
            cin.tie(NULL);
            return 0;
        }();
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                left_max = max(left_max, height[left]);
                ans += (left_max - height[left]);
                left++;
            } else {
                right_max = max(right_max, height[right]);
                ans += (right_max - height[right]);
                right--;
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________