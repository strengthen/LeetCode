__________________________________________________________________________________________________
28ms
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::ios::sync_with_stdio(0);
        cin.tie(0);
        vector<vector<string>> ans;
        unordered_map<unsigned, int> mp;
        int alpha[26] = {2,3,5,7,11,13,17,19,23,29,31,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103};
        int cur=0;
        for(auto s:strs){
            unsigned key = 1;
            for(char c:s)key *= alpha[c-'a'];
            if(mp.find(key)==mp.end()){
                mp[key]=cur++;
                ans.push_back({s});
            }else{
                ans[mp[key]].push_back(s);
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
32ms
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        string tmp;
        for(auto&str:strs){
            tmp = str;
            sort(tmp.begin(),tmp.end());
            m[tmp].emplace_back(move(str));
        }
        vector<vector<string>> ans;
        for(auto& p:m)ans.emplace_back(move(p.second));
        return ans;
    }
};
static auto _=[](){cin.tie(nullptr);ios::sync_with_stdio(false);return 0;}();
__________________________________________________________________________________________________
36ms
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> my_map;
        string key(26, '0');
        for (int i = 0; i < strs.size(); i++)
        {
            int len = strs[i].size();
            const string& str = strs[i];
            for (int j = 0; j < len; j++)
            {
                key[str[j]-'a'] += 1;
            }
            my_map[key].push_back(str);
            fill(key.begin(), key.end(), '0');
        }
        vector<vector<string>> ret;
        for (auto& pair : my_map)
        {
            ret.emplace_back(move(pair.second));
        }
        return ret;
    }
};
__________________________________________________________________________________________________
16776 kb
class Solution {
public:
    static bool anacomp(string s1, string s2) {
        string ss1 = s1, ss2 = s2;
        sort(ss1.begin(), ss1.end());
        sort(ss2.begin(), ss2.end());
        //cout << ss1 << " " << ss2 << " " << (ss1 < ss2) << endl;
        return (ss1 < ss2);
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ana;
        if (strs.size() == 0) return ana;
        sort(strs.begin(), strs.end(), anacomp); // sort w/o modifying the actual strings
        string s = "";
        for (int i = 0; i < strs.size(); ++i) {
            if (i == 0 || anacomp(s, strs[i])) {
                vector<string> v;
                ana.push_back(v);
            }
            ana[ana.size()-1].push_back(strs[i]);
            s = strs[i];
        }
        return ana;
    }
};
__________________________________________________________________________________________________
16972 kb
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
        // map hash value to indices.
        unordered_map<unsigned, int> wordMap;
        int curr = 0;
        
        vector<vector<string>> anagrams;
        for (auto & word: strs) {
            unsigned encode = 1;
            for (auto & ch : word) {
                encode *= primes[ch - 'a'];
            }
            // std::cout << encode << std::endl;
            // if new encode value
            if (!wordMap.count(encode)) {
                wordMap[encode] = curr++;
                anagrams.push_back({word});
            } else {
                anagrams[wordMap[encode]].push_back(word);
            }
        }
        return anagrams;
    }
private:
    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};
__________________________________________________________________________________________________