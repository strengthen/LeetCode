__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        if(rectangles.empty())
            return 0;
        int n = rectangles.size();
        vector<bool> chk(n);
        vector<pair<int, int>> xlist;
        for(int i=0;i<n;i++){
            vector<int> &v = rectangles[i];
            xlist.push_back({v[0], i+1});
            xlist.push_back({v[2], -(i+1)});
        }
        
        sort(xlist.begin(), xlist.end());
        int m = xlist.size();
        long long ans = 0, lastx = xlist[0].first;
        vector<pair<int, int>> range;
        
        for(int i=0;i<m;i++){
            int st = -1;
            long long y = 0;
            
            for(auto p : range){
                st = max(st, p.first);
                y += max(p.second - st, 0);
                st = max(st, p.second);
            }
            
            long long x = xlist[i].first - lastx;
            ans += (x * y) % MOD;
            ans %= MOD;
            
            if(xlist[i].second > 0){
                int j = xlist[i].second - 1;
                range.push_back({rectangles[j][1], rectangles[j][3]});
                sort(range.begin(), range.end());
            }
            else{
                int j = xlist[i].second *(-1) - 1;
                for(int k=0;k<range.size();k++){
                    pair<int, int> &p = range[k];
                    if(p.first == rectangles[j][1] && p.second == rectangles[j][3]){
                        range.erase(range.begin()+k);
                        break;
                    }
                }
            }
            
            lastx = xlist[i].first;
        }
        return (int) ans;
    }
    
    const long long MOD = 1000000000+7;
};
__________________________________________________________________________________________________
sample 9388 kb submission
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        priority_queue<int, vector<int>, std::greater<int>> yaxis;
        priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<pair<int,int>>> xaxis;
        
        for (vector<int> &rectangle:rectangles) {
            yaxis.push(rectangle[1]);
            yaxis.push(rectangle[3]);
        }
        
        long long ans = 0;
        while (!yaxis.empty()) {
            int y0 = yaxis.top();
            yaxis.pop();
            if (yaxis.empty()) {
                break;
            }
            int y1 = yaxis.top();
            for (vector<int> &rectangle:rectangles) {
                if (y0==rectangle[1] && y0!=rectangle[3]) {
                    // 1 is start : 2 is end
                    xaxis.push(make_pair(rectangle[0], 1));
                    xaxis.push(make_pair(rectangle[2], 2));
                    rectangle[1] = y1;
                }
            }
            int start=0, startPoint;
            while (!xaxis.empty()) {
                int point = xaxis.top().first, type = xaxis.top().second;
                xaxis.pop();
                if (type==1) {
                    if (start!=0) {
                        ans += (long long)(y1-y0)*(point-startPoint);
                    }
                    start++;
                }
                else {
                    start--;
                    ans += (long long)(y1-y0)*(point-startPoint);
                }
                startPoint = point;
            }
        }
        ans %= 1000000000+7;
        return (int)ans;
    }
};
__________________________________________________________________________________________________
