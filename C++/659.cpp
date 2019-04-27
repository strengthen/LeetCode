__________________________________________________________________________________________________
sample 28 ms submission
auto fast_io = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        deque<int> start;
        int idx = 0, idx2 = 0, prev = 0, curr = nums[0];
        while (idx < nums.size()) {
            while (idx2+1 < nums.size() && nums[idx2+1] == curr) ++idx2;
            int cnt = idx2-idx+1;
            if (cnt > prev) {
                for (int i = prev; i < cnt; ++i) {
                    start.emplace_back(curr);
                    // cout<<"start: "<<curr<<endl;
                }
            } else if (cnt < prev) {
                for (int i = cnt; i < prev; ++i) {
                    int temp = start.front();
                    start.pop_front();
                    // cout<<"end: "<<curr<<endl;
                    if (curr-temp < 3) return false;
                }
            }
            prev = cnt;
            idx = idx2+1;
            ++curr;            
        }
        for (int i = 0; i < prev; ++i) {
            int temp = start.front();
            start.pop_front();
            // cout<<"end: "<<curr<<endl;
            if (curr-temp < 3) return false;
        }
        return true;
    }
};
__________________________________________________________________________________________________
sample 15548 kb submission
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if(nums.size()==0) return true;
        int count =0;
        int num = INT_MIN;
		vector<int> cnt;
        for(int i=0;i<=nums.size();i++){
            if(count==0){
				cnt.push_back(0);
                count=1;
                num=nums[i];
            }
            else if(i==nums.size()||nums[i]!=num){   
				cnt.push_back(count);
				if(i==nums.size()||nums[i]-num>1){
					cnt.push_back(0);
				}
                if(i==nums.size())
                    break;
                count=1;
                num=nums[i];               
            }  
            else{                
                count++;
            }
        }
		queue<int> s;
		for(int i=1;i<cnt.size();i++){
			if(cnt[i]>cnt[i-1]){
				int h = cnt[i]-cnt[i-1];
				for(int m=0;m<h;m++){
					s.push(i);
				}
			}
			else if(cnt[i]<cnt[i-1]){
				int h = cnt[i-1]-cnt[i];
				for(int m=0;m<h;m++){
					int startIndex = s.front();
					s.pop();
					if(i-startIndex<=2)return false;
				}
			}
		}
		
        return true;
    }
};
__________________________________________________________________________________________________
