__________________________________________________________________________________________________
16ms
class Solution {
public:
    
    
    class Counter {
        struct TargetVsCurrent {
            TargetVsCurrent() : target(0), current(0) { }
            long target;
            long current;
        };
        
        using counts = std::unordered_map<string_view, TargetVsCurrent>;
        
    public:
        Counter(const vector<string>& words) {
            for (const auto &w : words) {
                byWords[w].target++;
            }
            reset();
        }
        
        void reset() {
            for (auto &c : byWords) {
                c.second.current = 0;
            }
            other.current = 0;
            diff = byWords.size();
        }
        
        size_t addWord(string_view word) {
            return modifyCounter(word, +1);
        }
        
        size_t removeWord(string_view word) {
            return modifyCounter(word, -1);
        }
        
    private:
        size_t modifyCounter(string_view word, int delta) {
            if (!delta) {
                return diff;
            }
            auto& counter = getCounter(word);
            if (counter.current == counter.target) {
                ++diff;
            }
            counter.current += delta;
            if (counter.current == counter.target) {
                --diff;
            }
            //if (diff < 0) {
            //    throw "invalid diff: " + diff;
            //}
            return diff;
        }
        
        TargetVsCurrent& getCounter(string_view word) {
            auto it = byWords.find(word);
            if (it != byWords.end()) {
                return it->second;
            }
            return other;
        }    
        
    private:
        counts byWords;
        TargetVsCurrent other;
        long diff;
    };
    
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) {
            return {};
        }
        Counter counter(words);
        size_t step = words[0].size();
        vector<int> result;
        for (int shift = 0; shift < step; ++shift) {
            auto tmp = doScan(s, shift, step, counter, words.size());
            result.insert(result.end(), tmp.begin(), tmp.end());
        }
        return result;
    }
    
    vector<int> doScan(string_view s, size_t shift, size_t step, Counter& counter, size_t total) {
        vector<int> result;
        size_t window = 0;
        counter.reset();
        for (size_t first = shift, last = shift; last + step - 1 < s.size(); last += step) {
            if (last - first == total * step) {
                string_view prev = s.substr(first, step);
                counter.removeWord(prev);
                first += step;
            }
            string_view cur = s.substr(last, step);
            if (counter.addWord(cur) == 0) {
                result.push_back(first);
            }
        }
        return result;
    }
};
__________________________________________________________________________________________________
20ms
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> map;
        vector<int> res;
        int i, wSize = words.size();
        if(!wSize) return res;
        int wL=words[0].size(), start, cur, sL=s.size(), wCnt;
        if(!wL) return res;
        if(sL<wL*wSize) return res;
        
        //build the map
        for(i=0; i<wSize; ++i)
            map[words[i]]++;
            
        for(i=0; i<wL; ++i)
        {
            start = cur = i; 
            wCnt = wSize; 
            while(start<=sL-wL*wSize)
            {
                if(map.count(s.substr(cur,wL))==0){
                        for(wCnt = wSize; start!=cur; start+=wL) ++map[s.substr(start,wL)];
                        start +=wL; 
                }
                else if(map[s.substr(cur,wL)]==0){
                    for(;s.substr(cur,wL)!=s.substr(start,wL); start+=wL)
                    {
                        ++map[s.substr(start,wL)];
                        ++wCnt;
                    }
                    start += wL;
                }
                else{
                    --map[s.substr(cur,wL)]; 
                    if(--wCnt == 0) { 
                        res.push_back(start); 
                        ++map[s.substr(start,wL)]; 
                        start +=wL;
                        ++wCnt;
                    }
                }
                cur+=wL; 
            }
            for(;start<cur;start+=wL)  ++map[s.substr(start,wL)];
        }
        return res;
    }
};
__________________________________________________________________________________________________
24ms
class Solution {

    vector<bool> used;
    int min;
    int max;

    int strstr(string& s, int i, string& word) {
        int wordLen = word.length();
        for (; i <= s.length() - wordLen; i += wordLen) {
            if (used[i]) {
                continue;
            }

            auto k = 0;
            for (auto j = i; k < wordLen; ++j, ++k) {
                if (s[j] != word[k]) {
                    break;
                }
            }
            if (k == word.length()) {
                used[i] = true;
                return i;
            }
        }
        return -1;
    }

    int findAllSubstrings(string& s, int i, vector<string>& words) {
        resetUsed();

        int totalLen = words[0].length() * words.size();

        for (int j = 0; j < words.size(); ++j) {
            auto f = strstr(s, i, words[j]);
            if (f < 0) {
                return -1;
            }
            if (f < min) {
                min = f;
            }
            if (f > max) {
                max = f;
            }
        }

        return min;
    }

    bool isValidPos(int f, int totalLen, int wordLen) {
        return (max - min) == (totalLen - wordLen);
    }

    void resetUsed() {
        vector<bool> tmp(used.size());
        used.swap(tmp);
        min = INT_MAX;
        max = INT_MIN;
    }

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> find;

        int len = words.size();
        if (len == 0) {
            return find;
        }

        int wordLen = words[0].length();
        if (wordLen == 0) {
            return find;
        }

        int totalLen = len * wordLen;

        if (s.length() < totalLen) {
            return find;
        }

        used.resize(s.length());

        for (auto i = 0; i < wordLen; ++i) {
            auto f = findAllSubstrings(s, i, words);
            while (f >= 0) {
                if (isValidPos(f, totalLen, wordLen)) {
                    find.push_back(f);
                }
                f = findAllSubstrings(s, f + wordLen, words);
            }
        }

        return find;
    }
};
__________________________________________________________________________________________________
11596 kb
static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
vector<int> findSubstring(string s, vector<string>& words)
{
    vector<int> ans;
    if (words.empty())
    {
        return ans;
    }
    int len = words[0].size();
    unordered_map<string, int> word;
    for (int i = 0; i < words.size(); i++)
    {
        word[words[i]]++;
    }
    vector<int> index;
    index.resize(s.size(), -1);
    vector<int> table;
    table.resize(word.size());
    int temp = 0;
    for (auto iter : word)
    {
        //cout<<iter.first<<endl;
        table[temp] = iter.second;
        int i = -1;
        while ((i = s.find(iter.first, i + 1)) != string::npos)
        {
            index[i] = temp;
        }
        temp++;
    }
    for (int i = 0; i < len; i++)
    {
        int left = i, right = left;
        int count = 0;
        vector<int> cnt;
        cnt.resize(word.size());
        while (right < s.size())
        {
            if (index[right] == -1)
            {
                count = 0;
                cnt.clear();
                cnt.resize(word.size());
                right += len;
                left = right;
                continue;
            }
            cnt[index[right]]++;
            if (cnt[index[right]] <= table[index[right]])
            {
                count++;
            }
            else while (cnt[index[right]] > table[index[right]])
            {
                cnt[index[left]]--;
                if (cnt[index[left]] < table[index[left]])
                {
                    count--;
                }
                left += len;
            }
            if (count == words.size())
            {
                count--;
                cnt[index[left]]--;
                ans.push_back(left);
                left += len;
            }
            right += len;
        }
    }
    return ans;
}
};
__________________________________________________________________________________________________
11932 kb
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.length() == 0 || words.size() == 0) return vector<int>();
        
        int numWords = words.size();
        int wordLength = words[0].length();
        
        int* matchingIdx = new int [s.length()];
        for (int i = 0; i < s.length(); i++)
            matchingIdx[i] = -1;
        
        int* duplicate = new int[numWords];
        memset(duplicate, 0, sizeof(int) * numWords);
        
        for (size_t k = 0; k < words.size(); k++) {
            size_t pos = 0;
            while (pos < s.length()) {
                pos = s.find(words[k], pos);
                if (pos == string::npos) break;
                
                if (matchingIdx[pos] != -1) {
                    duplicate[matchingIdx[pos]]++;
                    break;
                }
                    
                matchingIdx[pos] = k;
                pos++;
            }
        }
        
        vector<int> ret;
        int* matchingVector = new int[numWords];
        
        for (int i = 0; i <= ((int)s.length()) - numWords * wordLength; i++) {
            int matchingCount = 0;
            memset(matchingVector, 0, sizeof(int) * numWords);
            int pos = i;
            while (matchingCount < numWords) {
                if (matchingIdx[pos] < 0) break;
                if (matchingVector[matchingIdx[pos]] > duplicate[matchingIdx[pos]]) break;
                
                matchingVector[matchingIdx[pos]]++;
                matchingCount++;
                pos += wordLength;
            }
            
            if (matchingCount == numWords)
                ret.push_back(i);
        }
        
        delete[] matchingVector;
        delete[] duplicate;
        delete[] matchingIdx;
        return ret;
    }
};
__________________________________________________________________________________________________
