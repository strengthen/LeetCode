__________________________________________________________________________________________________
sample 0 ms submission
#include<cmath>
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int ll = 0, hl = 0;
        ll = log10(low);
        hl = log10(high) > 8 ? 8 : log10(high);
        vector<int> base = {1,11,111,1111,11111,111111,1111111,11111111,111111111};
        vector<int> first = {1,12,123,1234,12345,123456,1234567,12345678,123456789};
        
        vector<int> res;
        for(int i = ll;i <= hl;i ++){
            int b = first[i];
            res.push_back(b);
            cout<<b<<endl;
            while(b % 10 < 9){
                b += base[i];
                res.push_back(b);
                cout<<b<<endl;
            }
        }
        
        int i=0,j=0;
        for(i = 0;i < res.size();i ++){
            if(res[i] >= low)
                break;
        }
        for(j = res.size();j --;j >= 0){
            if(res[j] <= high)
                break;
        }
        vector<int> r;
        for(int k = i;k <= j;k ++){
            r.push_back(res[k]);
        }
        return r;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<int> sequentialDigits(int l, int h) {
        queue<int> q;
        for(int i = 1; i <= 9; i++) {
            q.push(i);
        }
        vector<int> ret;
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            if(f <= h && f >= l) {
                ret.push_back(f);
            }
            if(f > h)
                break;
            int num = f % 10;
            if(num < 9) {
                q.push(f * 10 + (num + 1));
            }
        }
        return ret;
    }
};
__________________________________________________________________________________________________
