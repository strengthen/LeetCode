__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> toVisit;
        unordered_set<string> dict(bank.begin(), bank.end());
        int dist = 0;
        
        if(!dict.count(end)) return -1;
        
        toVisit.push(start);
        dict.insert(start); dict.insert(end);
        while(!toVisit.empty()) {
            int n = toVisit.size();
            for(int i=0; i<n; i++) {
                string str = toVisit.front();
                toVisit.pop();
                if(str==end) return dist;
                addWord(str, dict, toVisit);
            }
            dist++;
        }
        return -1;
    }
void addWord(string word, unordered_set<string>& dict, queue<string>& toVisit) {
        dict.erase(word);
        for(int i=0; i<word.size(); i++) 
        {
            char tmp = word[i];
            for(char c:string("ACGT")) 
            {
                word[i] = c;
                if(dict.count(word)) 
                {
                    toVisit.push(word);
                    dict.erase(word);
                }
            }
            word[i] = tmp;
        }
    }
};
__________________________________________________________________________________________________
sample 8400 kb submission
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> hash;
        for (auto &str : bank){
            hash.insert(str);
        }
        list<string> todo;
        todo.push_back(start);
        int count = 1;
        int step = 0;
        int process_count = 0;
        while (todo.size() > 0){
            string top = todo.front();
            todo.pop_front();
            if (top == end){
                return step;
            }
            
            for (int i = 0; i < bank.size() - process_count;){
                if (true == isOneStep(top, bank[i])){
                    todo.push_back(bank[i]);
                    ++process_count;
                    swap(bank[i], bank[bank.size() - process_count]);
                    
                }
                else{
                    ++i;
                }
            }
            
            if (0 == --count){
                count = todo.size();
                ++step;
            }
        }
        return -1;
    }
private:
    bool isOneStep(string &src, string &dst){
        int diff = 0;
        for (int i = 0; i < src.length(); ++i){
            if (src[i] != dst[i]){
                ++diff;
            }
        }
        return 1 == diff;
    }    
};
__________________________________________________________________________________________________
