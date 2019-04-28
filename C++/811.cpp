__________________________________________________________________________________________________
sample 16 ms submission
static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> res;
        
        for (auto& domain : cpdomains) {
            auto end = domain.find(' ');
            int count = std::stoi(domain.substr(0, end));
            //std::cout << count << endl;
            
            auto subdomains = domain.substr(end+1, string::npos);
            auto it = res.find(subdomains);
            if (it != res.end()) {
                it->second += count;
            } else {
                res[subdomains] = count;
            }
            
            //std::cout << subdomains << endl;
            
            end = subdomains.find('.');
            while (end != string::npos) {
                subdomains = subdomains.substr(end+1, string::npos);
                //cout << subdomains << endl;
                it = res.find(subdomains);
                if (it != res.end()) {
                    it->second += count;
                } else {
                    res[subdomains] = count;
                }
                
                end = subdomains.find('.');
            }
            
        }
        
        std::vector<string> result;
        for (auto& dom : res) {
            string count_r = std::to_string(dom.second);
            result.push_back(count_r + " " + dom.first);
        }
        return result;
    }
};
__________________________________________________________________________________________________
sample 13276 kb submission

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> subdomain_counter;
        vector<string> op;
        for(auto &s:cpdomains){
            int count = std::stoi(s);
            for(auto i = 0; i < s.size(); ++i){
                if(s[i] == ' ' || s[i] == '.'){
                    subdomain_counter[s.substr(i + 1)] += count;
                }
            }
        }
        
        for(auto &p:subdomain_counter){
            op.push_back(to_string(p.second) + " "+ p.first);
        }
        
        return op;
    }
};
__________________________________________________________________________________________________
