__________________________________________________________________________________________________
sample 24 ms submission
static auto _=[]() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class ExamRoom {
    vector<tuple<int, int, int>> h; //[<radius, -left, right>]
    int N;
    void dump() {
        printf("[");
        for (const auto &a : h)
            printf("<%d, %d, %d>, ", get<0>(a), -get<1>(a), get<2>(a));
        printf("]\n");
    }
    bool bigger(int i, int j) {
        return get<0>(h[i]) > get<0>(h[j]) || get<0>(h[i]) == get<0>(h[j]) && get<1>(h[i]) > get<1>(h[j]);
    }
    
    void go_up(int i, bool keep = false) {
        if (i >= h.size()) return;
        while (i > 0 && (keep || bigger(i, (i-1)/2))) {
            if (bigger(i, (i-1)/2)) swap(h[(i-1)/2], h[i]);
            i = (i-1)/2;
        }
    }
    void go_down(int i) {
        if (i < 0) return;
        while (i < h.size() && (i+1)*2-1 < h.size()) {
            int j = (i+1)*2 >= h.size() || bigger((i+1)*2-1, (i+1)*2) ? (i+1)*2 - 1 : (i+1)*2;
            if (bigger(i, j)) break;
            swap(h[i], h[j]);
            i = j;
        }
    }
    
    void update(int i, int j) {
        int mn = min(i, j), mx = max(i, j);
        go_down(mx);
        go_down(mn);
        go_up(mn);
        go_up(mx, true);
    }
public:
    ExamRoom(int N) {
        this->N = N;
        h.emplace_back(N, 1, -1);
    }
    
    int seat() {
        auto tp = h.front();
        auto left = -get<1>(tp), right = get<2>(tp);
        int m;
        if (left == -1) {
            m = 0;
        } else if (right == -1) {
            m = N-1;
        } else {
            m = (left + right) / 2;
        }
        
        get<0>(h.front()) = left == -1 ? m : (m - left) / 2;
        get<2>(h.front()) = m;
        go_down(0);
        
        // <(right - m)/2 , -m, right>
        int r = right == -1 ? N-1 - m : (right - m) / 2;
        h.emplace_back(r, -m, right);
        go_up(h.size() - 1);
        
        return m;
    }
    
    void leave(int p) {
        int l = -1, r = -1;
        for (int i = 0; i < h.size(); ++i) {
            if (get<2>(h[i]) == p) l = i;
            if (-get<1>(h[i]) == p) r = i;
        }
        
        get<2>(h[l]) = get<2>(h[r]);
        if (p == 0) get<0>(h[l]) = get<2>(h[l]);
        else if (p == N-1) get<0>(h[l]) = N-1+get<1>(h[l]);
        else get<0>(h[l]) = (get<2>(h[l]) + get<1>(h[l])) / 2;
        
        swap(h[r], h[h.size() - 1]);
        h.pop_back();
        
        update(l, r);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
__________________________________________________________________________________________________
sample 14020 kb submission
class ExamRoom {
public:
    int N;
    vector<int> L;
    ExamRoom(int n) {
        N = n;
    }

    int seat() {
        if (L.size() == 0) {
            L.push_back(0);
            return 0;
        }
        int d = max(L[0], N - 1 - L[L.size() - 1]);
        for (int i = 0; i < L.size() - 1; ++i) d = max(d, (L[i + 1] - L[i]) / 2);
        if (L[0] == d) {
            L.insert(L.begin(), 0);
            return 0;
        }
        for (int i = 0; i < L.size() - 1; ++i)
            if ((L[i + 1] - L[i]) / 2 == d) {
                L.insert(L.begin() + i + 1, (L[i + 1] + L[i]) / 2);
                return L[i + 1];
            }
        L.push_back(N - 1);
        return N - 1;
    }

    void leave(int p) {
        for (int i = 0; i < L.size(); ++i) if (L[i] == p) L.erase(L.begin() + i);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
__________________________________________________________________________________________________
