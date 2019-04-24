__________________________________________________________________________________________________
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for (auto a : vec2d) {
            v.insert(v.end(), a.begin(), a.end());
        }    
    }
    int next() {
        return v[i++];
    }
    bool hasNext() {
        return i < v.size();
    }
private:
    vector<int> v;
    int i = 0;
};
__________________________________________________________________________________________________
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        v = vec2d;
        x = y = 0;
    }
    int next() {
        return v[x][y++];
    }
    bool hasNext() {
        while (x < v.size() && y == v[x].size()) {
            ++x; 
            y = 0;
        }
        return x < v.size();
    }    
private:
    vector<vector<int>> v;
    int x, y;
};
__________________________________________________________________________________________________
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        x = vec2d.begin();
        end = vec2d.end();
    }
    int next() {
        return (*x)[y++];
    }
    bool hasNext() {
        while (x != end && y == (*x).size()) {
            ++x; 
            y = 0;
        }
        return x != end;
    }
private:
    vector<vector<int>>::iterator x, end;
    int y = 0;
};