__________________________________________________________________________________________________
class Excel {
public:
    Excel(int H, char W) {
        m.clear();
        mat.resize(H, vector<int>(W - 'A', 0));
    }
    
    void set(int r, char c, int v) {
        if (m.count({r, c})) m.erase({r, c});
        mat[r - 1][c - 'A'] = v;
    }
    
    int get(int r, char c) {
        if (m.count({r, c})) return sum(r, c, m[{r, c}]);
        return mat[r - 1][c - 'A'];
    }
    
    int sum(int r, char c, vector<string> strs) {
        int res = 0;
        for (string str : strs) {
            auto found = str.find_last_of(":");
            if (found == string::npos) {
                char y = str[0];
                int x = stoi(str.substr(1));
                res += get(x, y);
            } else {
                int x1 = stoi(str.substr(1, (int)found - 1)), y1 = str[0] - 'A';
                int x2 = stoi(str.substr(found + 2)), y2 = str[found + 1] - 'A';
                for (int i = x1; i <= x2; ++i) {
                    for (int j = y1; j <= y2; ++j) {
                        res += get(i, j + 'A');
                    }
                }
            }
        }
        m[{r, c}] = strs;
        return res;
    }

private:
    vector<vector<int>> mat;
    map<pair<int, char>, vector<string>> m;
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
