__________________________________________________________________________________________________
sample 96 ms submission
struct Rectangle {
    int x;
    int y;
    int w;
    Rectangle(int _x = 0, int _y = 0, int _w = 1) : x(_x), y(_y), w(_w) {}
};

class Solution {
private:
    map<int, Rectangle> rects;
    int point_cnt;
public:
    Solution(vector<vector<int>> rects) {
        point_cnt = 0;
        for (int i = 0; i < rects.size(); i++)
        {
            const auto &rect = rects[i];
            this->rects[point_cnt] = Rectangle(rect[0], rect[1], rect[3] - rect[1] + 1);
            point_cnt += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
        }
    }
    
    vector<int> pick() {
        int r = rand() % point_cnt;
        auto it = rects.upper_bound(r);
        --it;
        
        const Rectangle &rect = it->second;
        
        /*cout << point_cnt << " " << r << endl;
        cout << it->first << " " << r << " " << rect.x << " " << rect.y << " " << rect.w << endl;*/
        r -= it->first;
        vector<int> res = {rect.x + r / rect.w, rect.y + r % rect.w};
        
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */
__________________________________________________________________________________________________
sample 26876 kb submission
class Solution {
public:
    vector<vector<int>> rect;
    vector<int> r_area;
    int total_area;
    Solution(vector<vector<int>> rects) {
        rect = rects;
        int total = 0;
        for (int i = 0; i < rects.size(); i++) {
            total += (rects[i][2] - rects[i][0]+1)*(rects[i][3] - rects[i][1]+1);
            r_area.push_back(total);
        }
        total_area = total;
    }
    
    vector<int> pick() {
        int random_area = rand()%total_area+1;
        int low = 0, high = r_area.size() -1;
        while(low < high) {
            int mid = (low + high)/2;
            if(r_area[mid] >= random_area)
                high = mid;
            else
                low = mid + 1;
        }
        
        int dis_x = rand()%(rect[low][2] - rect[low][0]+1);
        int dis_y = rand()%(rect[low][3] - rect[low][1]+1);
        return {rect[low][0] + dis_x, rect[low][1] + dis_y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */
__________________________________________________________________________________________________
