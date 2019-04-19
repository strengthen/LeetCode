__________________________________________________________________________________________________
8ms
static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        while(left < right){
            int h = min(height[left], height[right]);
            res = max(res, h * (right - left));
            // while(height[left] <= h && left < right)
                // left++;
            // while(height[right] <= h && left < right)
                // right--;
            height[left] < height[right] ? left++ : right--;
        }
        return res;
    }
};
__________________________________________________________________________________________________
20ms
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        while(left < right){
            int h = min(height[left], height[right]);
            res = max(res, h * (right - left));
            // while(height[left] <= h && left < right)
            //     left++;
            // while(height[right] <= h && left < right)
            //     right--;
            height[left] < height[right] ? left++ : right--;
        }
        return res;
    }
};
__________________________________________________________________________________________________
9644 kb
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int m=0;
        int i=0,j=height.size()-1;
        while(i<j)
        {
            m = max(m,min(height[i],height[j])*(j-i));
            height[i]<height[j]?i++:j--;
        }
        return m;
    }
};
__________________________________________________________________________________________________
9688 kb
static int pre = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	int maxArea(vector<int>& height) {
		auto area = 0;
		auto front = 0;
		auto end = static_cast<int>(height.size() - 1);
		while (front < end) {
			auto length = end - front;
			auto heightA = height[front];
			auto heightB = height[end];
			auto minHeight = 0;
			if (heightA > heightB) {
				minHeight = heightB;
				end--;
			}
			else {
				minHeight = heightA;
				front++;
			}
			auto tempArea = minHeight * length;
			if (tempArea > area)
				area = tempArea;
		}
		return area;
	}
};
__________________________________________________________________________________________________
9764 kb
static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = height.size();
        int res = 0;
        for(int i = 0; i<l; i++){
            for(int j = i+1; j<l; j++){
                res = max(res, min(height[i],height[j])*(j-i));
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
