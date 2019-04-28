__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> s(banned.begin(), banned.end());
        unordered_map<string, int> counts;
        int n = paragraph.size();
        int pre = 0, c = 0;
        string ret, cur;        
        for(int i=0; i<=n; ++i){
            if(i < n && isalpha(paragraph[i])) cur.push_back(tolower(paragraph[i]));
            else{
                if(cur.size() > 0){
                    if(s.find(cur) == s.end()){
                        ++counts[cur];
                        if(counts[cur] > c){
                            c = counts[cur];
                            ret = cur;
                        }
                    }
                    cur.clear();
                }
            }
        }
        return ret;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    void trim(string& str) {
        for(int i = 0; i < str.size(); ++i) {
            if (!isalpha(str[i])) str[i] = ' ';
            else str[i] = tolower(str[i]);
        }
    }
    void split(string& str, vector<string>& words) {
        int wordStart = 0;
        int wordSize = 0;
        for(int i = 0 ; i <= str.size(); ++i) {
            if (i != str.size() && str[i] != ' ') {
                wordSize++;
            } else {
                if (wordSize != 0) words.push_back(str.substr(wordStart,wordSize));
                wordStart = i + 1;
                wordSize = 0;
            }
        }
        
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> wordCount;
        unordered_set<string> bannedSet(banned.begin(),banned.end());
        
        trim(paragraph);
        //istringstream ss{paragraph};
        //vector<string> words{istream_iterator<string>{ss},
        //                    istream_iterator<string>{}};
        vector<string> words;
        split(paragraph,words);
        
        string mostFrequentWord = "";
        int maxCount = 0;
        for(auto word : words) {
            if (bannedSet.find(word) == bannedSet.end()) {
                wordCount[word]++;
                if (wordCount[word] > maxCount) {
                    maxCount = wordCount[word];
                    mostFrequentWord = word;
                }
            }
        }
        return mostFrequentWord;
    }
};
__________________________________________________________________________________________________
sample 8948 kb submission
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int n = paragraph.length();
        if(n == 0) return "";
        
        unordered_map<string, int> cnt;
        string res;
        int max_cnt = 0, i = 0, j = 0;
        while(i < n && j < n){
            j = i;
            while(j < n && isalpha(paragraph[j])) j++;
            string word = paragraph.substr(i, j - i);
            transform(word.begin(), word.end(), word.begin(), ::tolower);

            if(find(banned.begin(), banned.end(), word) == banned.end()){
                cnt[word]++;
                if(cnt[word] > max_cnt){
                    max_cnt = cnt[word];
                    res = word;
                }
            }
            i = j;
            while(i < n && !isalpha(paragraph[i])) i++;
        }
        return res;
    }
};