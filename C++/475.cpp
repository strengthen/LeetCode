__________________________________________________________________________________________________
sample 36 ms submission
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        int length = heaters.size();
        sort(heaters.begin(), heaters.end());
        int max = 0;
        for (int& h : houses) {
            // cout << "h: " << h << endl;
            auto hb = upper_bound(heaters.begin(), heaters.end(), h);
            int n = distance(heaters.begin(), hb);
            int diff = 0;
            if (n == length) diff = (h - heaters[length-1]);
            else if (n == 0) diff = (heaters[0] - h);
            else diff = (min(heaters[n] - h, h - heaters[n-1]));
            if (diff > max) max = diff;
            
        }
        return max;
    }
};

auto ___ = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
__________________________________________________________________________________________________
sample 11012 kb submission
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int result=0;
        for(const auto &h:houses){
            int distance=binary_helper(h,heaters);
            cout<<distance<<endl;
            result=max(result,distance);
        }
        return result;
    }
    
    //在heaters中寻找元素，使得最接近h。
    int binary_helper(int h,vector<int>& heaters){
        long long l=-1,r=heaters.size();
        int right=INT_MAX,left=INT_MAX; //时刻记录
        int dis=INT_MAX;
        while(l+1!=r){
            long long mid=l+(r-l)/2;
            int heater=heaters[mid];
            if(heater==h) return 0;
            else if(heater<h){
                l=mid;
                right=h-heater;
                dis=min(dis,h-heater);
            }
            else{
                r=mid;
                dis=min(dis,heater-h);
                left=heater-h;
            }
        }
        return dis;
        return min(left,right);
        
    }
};
__________________________________________________________________________________________________
