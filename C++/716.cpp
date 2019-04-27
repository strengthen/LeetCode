__________________________________________________________________________________________________
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {}
    
    void push(int x) {
        if (s2.empty() || s2.top() <= x) s2.push(x);
        s1.push(x);
    }
    
    int pop() {
        if (!s2.empty() && s2.top() == s1.top()) s2.pop();
        int t = s1.top(); s1.pop();
        return t;
    }
    
    int top() {
        return s1.top();
    }
    
    int peekMax() {
        return s2.top();
    }
    
    int popMax() {
        int mx = s2.top();
        stack<int> t;
        while (s1.top() != s2.top()) {
            t.push(s1.top()); s1.pop();
        }
        s1.pop(); s2.pop();
        while (!t.empty()) {
            push(t.top()); t.pop();
        }
        return mx;
    }

private:
    stack<int> s1, s2;
};
__________________________________________________________________________________________________
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {}
    
    void push(int x) {
        v.insert(v.begin(), x);
        m[x].push_back(v.begin());
    }
    
    int pop() {
        int x = *v.begin();
        m[x].pop_back();
        if (m[x].empty()) m.erase(x);
        v.erase(v.begin());
        return x;
    }
    
    int top() {
        return *v.begin();
    }
    
    int peekMax() {
        return m.rbegin()->first;
    }
    
    int popMax() {
        int x = m.rbegin()->first;
        auto it = m[x].back();
        m[x].pop_back();
        if (m[x].empty()) m.erase(x);
        v.erase(it);
        return x;
    }

private:
    list<int> v;
    map<int, vector<list<int>::iterator>> m;
};
__________________________________________________________________________________________________
