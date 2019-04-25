__________________________________________________________________________________________________
sample 28 ms submission
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), [] (const pair<int,int>& l, const pair<int,int>& r) {
            if (l.first != r.first) return l.first < r.first;
            return l.second > r.second;
        });
        BIT bit(people.size());
        for (int i = 1; i <= people.size(); ++i) {
            bit.add(i, 1);
        }
        vector<pair<int,int>> ans(people.size());
        for (const auto& p : people) {
            int idx = bit.nth_element(p.second + 1);
            ans[idx] = p;
            bit.add(idx + 1, -1);
        }
        return ans;
    }
    class BIT {
    public:
        BIT(int max): MAX(max) {
            t = vector<int>(MAX + 1);
        }
        void add(int n, int d) {
            while (n <= MAX) {
                t[n] += d;
                n += n & -n;
            }
        }
        int nth_element(int n) {
            int ans = 0, sum = 0;
            for (int i = 10; i >= 0; --i) {
                ans += (1 << i);
                if (ans > MAX or sum + t[ans] >= n) ans -= (1 << i);
                else sum += t[ans];
            }
            return ans;
        }
    private:
        vector<int> t;
        int MAX;
    };
};
__________________________________________________________________________________________________
sample 10096 kb submission
bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.second<b.second;
    return a.first<b.first;
}
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> copy_p = people;
        sort(copy_p.begin(), copy_p.end(), compare);
        int count = 0;
        for(int i = copy_p.size()-1;i>=0;i--){
            int k = i;
            while(k>0 && copy_p[k].first == copy_p[k-1].first){
                count++;
                k--;
            }
            
            int loop_times = copy_p[i].second-count;
            for(int j = 0;j<loop_times;j++){
                pair<int,int> temp = copy_p[i+j];
                copy_p[i+j] = copy_p[i+j+1];
                copy_p[i+j+1] = temp;
            }
            count = 0;
            //cout<<i<<endl;
        }
        return copy_p;
    }
};
__________________________________________________________________________________________________
