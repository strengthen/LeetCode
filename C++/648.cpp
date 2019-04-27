__________________________________________________________________________________________________
sample 36 ms submission
int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class TrieNode {
public:
	TrieNode *children[27] = { nullptr };
};

class Solution {
public:
	string replaceWords(vector<string> &dict, string sentence) {
		TrieNode *root = new TrieNode, *node = root;
		for (const string &prefix : dict) {
			for (char l : prefix) {
				if (node->children[l - 'a'] == nullptr)
					node->children[l - 'a'] = new TrieNode;
				node = node->children[l - 'a'];
			}
			node->children[26] = root;
			node = root;
		}
		string output;
		string::const_iterator b = sentence.cbegin(), e = b;
		while (e != sentence.cend()) {
			if (*e == ' ')
				b = ++e;
			bool flag = false;
			while (e != sentence.cend() && *e != ' ') {
				if (node->children[26]) {
					flag = true;
					break;
				} else if (node->children[*e - 'a'] == nullptr)
					break;
				node = node->children[*e++ - 'a'];
			}
			if (flag) {
				output += string(b, e);
				e = find(e, sentence.cend(), ' ');
			} else {
				e = find(e, sentence.cend(), ' ');
				output += string(b, e);
			}
			node = root;
			output += ' ';
		}
		return string(output.cbegin(), output.cend() - 1);
	}
};
__________________________________________________________________________________________________
sample 19704 kb submission
class Solution {
    
public:
    string replaceWords(vector<string>& dict, string sentence) {
        constexpr long q = 2147483647;
        constexpr long p = 29;
        std::unordered_set<long> m;
        
        for (string& str : dict) {
            long h = 0;
            
            for (auto ch : str)
                h = (h * p + (ch - 'a' + 1)) % q;
            
            m.insert(h);
        }
        
        string res = "";
        const auto ed = std::end(sentence);
        auto res_st = std::back_inserter(res);
        
        for (auto st = std::begin(sentence); st != ed; ) {
            const char ch = *st;
            
            if (ch == ' ')
                *res_st++ = *st++;
            else {
                long h = ch - 'a' + 1;
                auto it = ++st;
                
                for (; it != ed && *it != ' '; it++) {
                    
                    if (m.count(h)) {
                        break;
                    }
                    
                    h = (h * p + ((*it) - 'a' + 1)) % q;
                }
                
                res_st = std::copy(std::prev(st), it, res_st);
                
                for (st = it; st != ed && *st != ' '; st++);
            }
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
