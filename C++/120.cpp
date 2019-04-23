__________________________________________________________________________________________________
4ms
static const auto ioSyncOff = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int size=tri.size();
        for(int i=1;i<size;i++){
            for(int j=0;j<tri[i].size();j++){
                tri[i][j]+=getAboveMin(tri[i-1],j);
            }
        }
        return getMin(tri[size-1]);
    }
private:
    int getAboveMin(vector<int>& v,int index){
        if(index==0) return v[0];
        if(index==v.size()) return v[index-1];
        return min(v[index-1],v[index]);
    }
    int getMin(vector<int>& v){
        int min=v[0];
        for(int e:v)
            if(min>e) min=e;
        return min;
    }
};
__________________________________________________________________________________________________
9700 kb
auto gucciGang = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		if (n > 0) {
			int i, j;
			for (i = 0; (vector<vector<int>>::size_type)i + 1 < n; ++i) {
				triangle[i + 1][0] += triangle[i][0];
				for (j = 0; (vector<int>::size_type)j + 1 < triangle[i].size(); ++j) {
					triangle[i + 1][j + 1] += min(triangle[i][j], triangle[i][j + 1]);
				}
				triangle[i + 1][j + 1] += triangle[i][j];
			}
			int total = triangle[i][0];
			for (j = 1; (vector<int>::size_type)j < triangle[i].size(); ++j) {
				total = min(total, triangle[i][j]);
			}
			return total;
		}
		return 0;
	}
};
__________________________________________________________________________________________________
