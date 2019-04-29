__________________________________________________________________________________________________
sample 4 ms submission
typedef long long int64;
const int INF = 0x3f3f3f3f;
template <class T> inline int len (const T &a) { return a.size (); }
int key[256];

bool cmp(const string &e1, const string &e2) {
    int N = len (e1), M = len (e2);
    for (int i = 0; i < min(N, M); i++)
        if (key[e1[i] - 'a'] != key[e2[i] - 'a'])
            return key[e1[i] - 'a'] < key[e2[i] - 'a'];
    return N < M;
}

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < len (order); i++) key[order[i] - 'a'] = i + 1;
        for (int i = 1; i < words.size(); i++) 
            if (!cmp(words[i - 1], words[i])) return false;
        return true;
        /*
        
        vector<string> copy = words;
        sort(words.begin(), words.end(), cmp);
        for (string c: words) cout << c << " ";
        return copy == words;
        */
    }
};

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
__________________________________________________________________________________________________
sample 8988 kb submission
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

/* 
//Solution 1   // 12 ms

unordered_map<char,int> m;
class Solution {
public:    
    class Compare{
        public:
        bool operator() (string a , string b){
            for(int i = 0 ; i < a.length() && i < b.length() ; ++i)
                if(m[a[i]] != m[b[i]]) return m[a[i]] > m[b[i]];
            return a.length() > b.length();
        }
    };
    
    bool isAlienSorted(vector<string>& words, string order) {
        m.clear();
        int n = order.size();
        for(int i = 0 ; i < n ; ++i) m[order[i]] = i;
        priority_queue<string, vector<string>, Compare> pq;
        for(string word : words) pq.push(word);
        for(string word : words){
            if(pq.top() != word) return false;
            pq.pop();            
        }
        return true;
    }
};

*/


/*
//Solution 2   // 8 ms
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        int n = words.size();
        if (!n) return true;

        for (int i = 0 ; i < n-1; ++i){
            int k;
            string first = words[i];
            string second = words[i+1];
            bool found = false;
            
            for (k = 0; k < first.length() && k < second.length(); ++k){
                if (first[k] != second[k]){
                    found = true;
                    int index1 = order.find_first_of(first[k]);
                    int index2 = order.find_first_of(second[k]);
                    if (index1 > index2) return false;
                    break;
                }
            }
            if (!found)
                if (k == second.length() && k != first.length()) return false;
        }
        return true;
    }
};

*/


// Solution 3   // 8 ms
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        int n = words.size();
        if (!n) return true;
        
        int m[256] = {-1};
        int l = order.size();
        for(int i = 0 ; i < l ; ++i) m[order[i]] = i;

        for(int i = 0 ; i < n-1 ; ++i){
            string f = words[i];
            string s = words[i+1];
            int n1 = f.length();
            int n2 = s.length();
            bool isSame = true;
            
            for(int j = 0 ; j < n1 && j < n2 ; ++j)
                if(f[j] != s[j]){ isSame = false; if(m[f[i]] < m[s[i]]) break; if(m[f[j]] > m[s[j]]) return false; }  
            if(isSame && n1 > n2) return false;
        }
        
        return 1;
    }
};
__________________________________________________________________________________________________
