__________________________________________________________________________________________________
sample 248 ms submission
auto __ =[]() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}
();

class StockSpanner {
    struct Node {
        Node(int num = 0, int val = 0) {
            this->num = num;
            this->val = val;
        }
        int num;
        int val;
    };
    stack<Node> sta;
public:
    StockSpanner() {

    }
    int next(int price) {
        int ans = 1;
        while(!sta.empty() && sta.top().val <= price) {
            ans += sta.top().num;
            sta.pop();
        }
        sta.push(Node(ans, price));
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
__________________________________________________________________________________________________
sample 71960 kb submission
class StockSpanner {
    stack<pair<int, int>> hist;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int cnt = 1;
        while (!hist.empty() && hist.top().first <= price)
        {
            cnt += hist.top().second;
            hist.pop();
        }
        hist.push({price, cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
__________________________________________________________________________________________________
