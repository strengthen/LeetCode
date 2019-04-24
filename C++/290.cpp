__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> m;
        set<string> st;
        char buf[str.length() + 1];
        sprintf(buf, "%s", str.c_str());
        char* token;
        token = strtok(buf, " ");
        vector<string> v;
        while (token != NULL)
        {
            v.emplace_back(token);
            token = strtok(NULL, " ");
        }
        
        if (pattern.length() != v.size())
            return false;
        int i = 0;
        for (auto x : pattern)
        {            
            auto itr =  m.find(x);
            if (itr == m.end())
            {
                auto itr_1 = st.find(v[i]);
                if (itr_1 != st.end())
                    return false;
                else
                    st.insert(v[i]);
                m.insert(pair<char, string>(x, v[i]));
            }
            else
            {
                if (v[i].compare(itr->second))
                    return false;
            }
            i++;
        }        
        return true;        
    }
};
__________________________________________________________________________________________________
sample 8276 kb submission
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int n = pattern.length();
        string s[26];
        unordered_map < string, char > m;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j >= str.length()) return false;
            char c = pattern[i];
            string tmp = "";
            while (j < str.length() && str[j] != ' ') {
                tmp += str[j++];
            }
            while (j < str.length() && str[j] == ' ') {
                j++;
            }
            if (s[c - 'a'].empty()) s[c - 'a'] = tmp;
            if (s[c - 'a'] != tmp) return false;
            if (m.find(tmp) == m.end()) m[tmp] = c;
            if (m[tmp] != c) return false;
        }
        while (j < str.length() && str[j] == ' ') {
            j++;
        }
        if (j < str.length()) return false;
        return true;
    }
};
__________________________________________________________________________________________________
