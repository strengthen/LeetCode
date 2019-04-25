__________________________________________________________________________________________________
sample 28 ms submission
class Solution {
public:
    int getId(string &word,int *ids){
        int k=0;
        for(auto c:word)
            if((k&ids[c-'a'])==0)
                k |= ids[c-'a'];
        return k;
    }
    int maxProduct(vector<string>& words) {
        std::ios::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
        int ids[26];
        for(int i=0;i<26;i++){
            ids[i]=1<<i;
        }
        int n = words.size();
        vector<int> id(n,0);
        for(int i=0;i<n;i++){
            id[i]=getId(words[i],ids);
        }
        int res = 0;
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                if((id[i]&id[j])==0){
                    int l=words[i].length()*words[j].length();
                    if(l>res)
                        res = l;
                }
        return res;
    }
};
__________________________________________________________________________________________________
sample 13656 kb submission
class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.empty()) {
            return 0;
        }
        vector<int> mask(words.size(), 0);
        for (int i = 0; i < words.size(); ++i) {
            for (auto c : words[i]) {
                mask[i] = mask[i] | (1 << static_cast<int>(c - 'a'));
            }
        }
        int max_product = 0;
        for (int i = words.size() - 1; i >= 0; --i) {
            for (int j = i - 1; j >= 0; --j) {
                if (!(mask[i] & mask[j])) {
                    max_product = max(max_product, static_cast<int>(words[i].size()) * static_cast<int>(words[j].size()));
                }
            }
        }
        return max_product;
    }
};
__________________________________________________________________________________________________
