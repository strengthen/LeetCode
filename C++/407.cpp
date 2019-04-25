__________________________________________________________________________________________________
sample 24 ms submission
struct djs_t{
    djs_t* dad;
    int h;
    int area;
    djs_t() = default;
    djs_t* find(){
        return dad==this?this:dad = dad->find();
    }
    djs_t* join(djs_t& rhs){
        if(area<rhs.area){
            return rhs.join(*this);
        }
        h = std::max(h,rhs.h);
        if(area && rhs.area){
            area+= rhs.area;
        }else{
            area = 0;
        }
        rhs.dad = this;
        return this;
    }
};
class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        int n = h.size();
        if(!n)return 0;
        int m = h.front().size();
        if(!m)return 0;
        std::vector<djs_t> ds(n*m);
        for(int i=0;i<n*m;++i){
            ds[i].dad = &(ds[i]);
            ds[i].h = h[i/m][i%m];
            ds[i].area = !(i/m==0 || i/m==n-1 || i%m==0 || i%m==m-1);
        }
        h = std::remove_reference_t<decltype(h)>();
        const array<std::pair<int,int>,4> directions{
            std::pair<int,int>{0,1},
            std::pair<int,int>{1,0},
            std::pair<int,int>{0,-1},
            std::pair<int,int>{-1,0}
        };
        std::vector<int> a(n*m);
        std::iota(a.begin(),a.end(),0);
        std::sort(a.begin(),a.end(),[&ds](int a,int b){
            return ds[a].h<ds[b].h;
        });
        int ans = 0;
        for(auto& e:a){
            auto y = ds[e].find();
            int i = e/m;
            int j = e%m;
            for(auto d:directions){
                int ni = i+d.first;
                int nj = j+d.second;
                if(!(0<=ni && ni<n && 0<=nj && nj<m)){
                    continue;
                }
                auto x = ds[ni*m+nj].find();
                if(x == y || x->h > y->h)continue;
                if(x->h < y->h){
                    ans+= (y->h - x->h)*x->area;
                }
                y = y->join(*x);
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 10184 kb submission
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        int waterMap[m][n];
        int curWater = 0;
        
        for (int i = 1; i < m-1; i++){
            curWater += trap(heightMap[i], waterMap[i]);
        }
        for (int j = 0; j < n; j++){
            waterMap[0][j] = 0;
            waterMap[m - 1][j] = 0;
        }
        int offset_x[4] = {-1, 0, 1, 0};
        int offset_y[4] = {0, -1, 0, 1};
        int spillFlag = 1;

        while (spillFlag){
            spillFlag = 0;
            for (int i = 1; i < m - 1; i++){
                for (int j = 1; j < n - 1; j++){
                    if (waterMap[i][j] != 0){
                        for (int k = 0; k < 4; k++){
                            int neibHeight = heightMap[i + offset_x[k]][j + offset_y[k]] + waterMap[i + offset_x[k]][j + offset_y[k]];
                            int curHeight = heightMap[i][j] + waterMap[i][j];
                            if (neibHeight < curHeight){
                                spillFlag = 1;
                                if (neibHeight < heightMap[i][j]){
                                    curWater -= waterMap[i][j];
                                    waterMap[i][j] = 0;
                                }
                                else{
                                    curWater -= (curHeight - neibHeight);
                                    waterMap[i][j] = neibHeight - heightMap[i][j];
                                }
                            }
                        }
                    }
                }
            }
        }

        return curWater;
    }
    
    int trap(vector<int> &rowHeight, int rowWater[]){
        int left = 0, right = rowHeight.size() -1;
        int leftMax = 0, rightMax = 0;
        int curWater = 0;
        
        while (left <= right){
            if (rowHeight[left] <= rowHeight[right]){
                if (rowHeight[left] > leftMax){
                    leftMax = rowHeight[left];
                    rowWater[left] = 0;
                }
                else{
                    rowWater[left] = leftMax - rowHeight[left];
                    curWater += rowWater[left];
                }
                left++;
            }
            else{
                if (rowHeight[right] > rightMax){
                    rightMax = rowHeight[right];
                    rowWater[right] = 0;
                }
                else{
                    rowWater[right] = rightMax - rowHeight[right];
                    curWater += rowWater[right];
                }
                right--;
            }
        }
        
        return curWater;
    }
};
__________________________________________________________________________________________________
