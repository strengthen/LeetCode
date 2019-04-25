__________________________________________________________________________________________________
sample 76 ms submission
auto gucciGang = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution {
private:
	struct hash_pair {
		size_t operator() (const pair<int, int> &p) const {
			return p.first + p.second * 31;
		}
	};
public:
	bool isRectangleCover(vector<vector<int>>& rectangles) {
		int area = 0;
		int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN;
		unordered_set<pair<int, int>, hash_pair> hash;
		for (auto &v : rectangles) {
			area += (v[2] - v[0]) * (v[3] - v[1]);
			min_x = min(min_x, v[0]); min_y = min(min_y, v[1]);
			max_x = max(max_x, v[2]); max_y = max(max_y, v[3]);
			if (hash.find({ v[0], v[1] }) != hash.end()) { hash.erase({ v[0], v[1] }); }
			else { hash.insert({ v[0], v[1] }); }
			if (hash.find({ v[0], v[3] }) != hash.end()) { hash.erase({ v[0], v[3] }); }
			else { hash.insert({ v[0], v[3] }); }
			if (hash.find({ v[2], v[1] }) != hash.end()) { hash.erase({ v[2], v[1] }); }
			else { hash.insert({ v[2], v[1] }); }
			if (hash.find({ v[2], v[3] }) != hash.end()) { hash.erase({ v[2], v[3] }); }
			else { hash.insert({ v[2], v[3] }); }
		}
		if (hash.find({ min_x, min_y }) == hash.end() || hash.find({ min_x, max_y }) == hash.end() ||
			hash.find({ max_x, min_y }) == hash.end() || hash.find({ max_x, max_y }) == hash.end() ||
			hash.size() > 4) {
			return false;
		}
		return area == (max_x - min_x) * (max_y - min_y);
	}
};
__________________________________________________________________________________________________
sample 18732 kb submission
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int left=INT_MAX,right=INT_MIN,top=INT_MIN,bottom=INT_MAX,area=0;
        for(int i=0;i<rectangles.size();++i)
        {
            for(int j=i+1;j<rectangles.size();++j)
            {
                if(isOverlap(rectangles[i],rectangles[j]))
                {
                    return false;
                }
            }
            
            left=min(left,rectangles[i][0]);
            right=max(right,rectangles[i][2]);
            top=max(top,rectangles[i][3]);
            bottom=min(bottom,rectangles[i][1]);
            
            area+=(rectangles[i][2]-rectangles[i][0])*(rectangles[i][3]-rectangles[i][1]);
        }
        return area==(right-left)*(top-bottom);
    }
    
    bool isOverlap(vector<int>& rec1,vector<int>& rec2)
    {
        return !(rec1[0]>=rec2[2]||rec1[1]>=rec2[3]||rec1[2]<=rec2[0]||rec1[3]<=rec2[1]);
    } 
};
__________________________________________________________________________________________________
