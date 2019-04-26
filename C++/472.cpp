__________________________________________________________________________________________________
sample 152 ms submission
int trie[50000][26];
bool terminal[50000];
class Solution {
public:
	int node;
	
	void add(string s){
		int tam = s.size();
		int p = 0;    
		for(int i=0;i<tam;i++){
			if(trie[p][s[i]-'a'] != 0){
				p = trie[p][s[i]-'a'];
			}else{
				p = trie[p][s[i]-'a'] = node++;
			}
		}
		
		terminal[p]= true;
	}
	
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		node = 1;
		vector<string> ans;
		memset(trie,0,sizeof(trie));
		memset(terminal,false,sizeof(terminal));
		
		for(int i=0;i<words.size();i++)
			add(words[i]);
		
		for(auto w : words){
			int n = w.size();
			if(n == 0) continue;
			bool dp[n+1];
			memset(dp,false,sizeof(dp));
			dp[0] = true;
			
			for(int i=0; i<n; i++){
				if(dp[i] == false) continue;
				int index = 0;
				
				for(int j=i;j<n;j++){
					index = trie[index][w[j]-'a'];
					if(index == 0)break;
					if(i==0 && j==n-1)continue;
					if(terminal[index])
						dp[j+1]=true;
				}
				
				if(dp[n]){
					ans.push_back(w);
					break;
				}
			}    
		}
		
		return ans;
	}
};
__________________________________________________________________________________________________
sample 40344 kb submission
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_set<string> dict(words.begin(), words.end());
        for (string word : words) {
            if (word.empty()) continue;
            if (helper(word, dict, 0, 0)) {
                res.push_back(word);
            }
        }
        return res;
    }
    bool helper(string& word, unordered_set<string>& dict, int pos, int cnt) {
        if (pos == word.size() && cnt >= 2) return true;
        for (int i = 1; i <= (int)word.size() - pos; ++i) {
            string t = word.substr(pos, i);
            if (dict.count(t) && helper(word, dict, pos + i, cnt + 1)) {
                return true;
            }
        }
        return false;
    }
};
__________________________________________________________________________________________________
