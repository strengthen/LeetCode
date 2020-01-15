__________________________________________________________________________________________________
sample 8 ms submission
static const auto io_sync_off = []()
{
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	std::cin.tie(nullptr);
	return nullptr;
}();
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        if(start >= n) return false;
        
        queue<int> q;
        q.push(start);
        vector<int> visited(n,0);
        visited[start] = 1;
        while(!q.empty()){
            int s = q.front();
            if(arr[s] == 0) return true;
            q.pop();
            int low  = s - abs(arr[s]);
            int high = s + abs(arr[s]);
            if(low >= 0 && !visited[low]){
                visited[low] = 1;
                q.push(low);
            }
             if(high < n && !visited[high]){
                visited[high] = 1;
                q.push(high);
            }
        }
        return false;
    }
};
__________________________________________________________________________________________________
sample 12 ms submission
const auto fastIO = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
private:
    unordered_map<int, int> visited;
public:
    bool canReach(vector<int>& arr, int start) {
        if (start>=0 && start<arr.size() && visited.count(start)==0) {
            visited[start]++;
            return arr[start]==0 || canReach(arr, start+arr[start]) || canReach(arr, start-arr[start]);
        }
        
        return false;
    }
};
__________________________________________________________________________________________________
