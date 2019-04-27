__________________________________________________________________________________________________
class StringIterator {
public:
    StringIterator(string compressedString) {
        s = compressedString;
        n = s.size();
        i = 0;
        cnt = 0;
        c = ' ';
    }
    
    char next() {
        if (hasNext()) {
            --cnt;
            return c;
        }
        return ' ';
    }
    
    bool hasNext() {
        if (cnt > 0) return true;
        if (i >= n) return false;
        c = s[i++];
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            cnt = cnt * 10 + s[i++] - '0';
        }
        return true;
    }

private:
    string s;
    int n, i, cnt;
    char c;
};
__________________________________________________________________________________________________
class StringIterator {
public:
    StringIterator(string compressedString) {
        is = istringstream(compressedString);
        cnt = 0;
        c = ' ';
    }
    
    char next() {
        if (hasNext()) {
            --cnt;
            return c;
        }
        return ' ';
    }
    
    bool hasNext() {
        if (cnt == 0) {
            is >> c >> cnt;
        }
        return cnt > 0;
    }

private:
    istringstream is;
    int cnt;
    char c;
};
__________________________________________________________________________________________________
class StringIterator {
public:
    StringIterator(string compressedString) {
        istringstream is(compressedString);
        int cnt = 0;
        char c = ' ';
        while (is >> c >> cnt) {
            q.push({c, cnt});
        }
    }
    
    char next() {
        if (hasNext()) {
            auto &t = q.front();
            if (--t.second == 0) q.pop();
            return t.first;
        }
        return ' ';
    }
    
    bool hasNext() {
        return !q.empty();
    }

private:
    queue<pair<char, int>> q;
};