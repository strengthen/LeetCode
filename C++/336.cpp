__________________________________________________________________________________________________
sample 120 ms submission
static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class TrieNode
{
public:
    int num;
    vector<TrieNode*> next; 
    TrieNode(): num(-1), next(26, NULL){}
    
};


class Solution 
{
private:
    TrieNode* buildTrie(vector<string>& words)
    {
        TrieNode* root=new TrieNode();
        
        for(int i=0; i<words.size(); ++i)
        {
            string tmp=words[i];
            reverse(tmp.begin(), tmp.end());
            TrieNode* curr=root;
            for(int j=0; j<tmp.size(); ++j)
            {
                if(!curr->next[tmp[j]-'a'])
                    curr->next[tmp[j]-'a']=new TrieNode();
                
                curr=curr->next[tmp[j]-'a'];   
            }
            curr->num=i;

        }
        
        return root;
        
        
    }
    
    inline bool isPP(string& a, string& b)
    {
        string c=a+b;
        int head=0;
        int tail=c.size()-1;
        while(head<tail)
        {
            if(c[head]!=c[tail])
                return false;
            head++;
            tail--;
        }
        return true;
    }
    inline bool isPP(string c)
    {
        int head=0;
        int tail=c.size()-1;
        while(head<tail)
        {
            if(c[head]!=c[tail])
                return false;
            head++;
            tail--;
        }
        return true;
    }
    
    void backtracking(TrieNode* root, vector<string>& words, int start, int index, vector<vector<int>>& result)
    {
        if(root->num >= 0 && index!=root->num)//we find it in TrieNode
        {
            if(isPP(words[index], words[root->num]))
            {
                vector<int> tmp={index, root->num};
                 result.emplace_back(tmp);
            }
               
            
        }
            
       
        for(int i=0; i<26; ++i)
        {
            if(start<words[index].size() && root->next[i] && i==int(words[index][start]-'a'))    
                backtracking(root->next[i], words, start+1, index, result);
            if(start==words[index].size() && root->next[i])
                backtracking(root->next[i], words, start, index, result);
            
        }
              
    }    
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) //more concise
    {
        vector<vector<int>> result;
        int wsize=words.size();
        if(wsize<2)
            return result;
        
        unordered_map<string, int>dict;
        for(int i=0; i<wsize; ++i)
            dict[words[i]]=i;
        
        
        for(int i=0; i<wsize; ++i)
        {
            
            for(int j=0; j<words[i].size(); ++j)
            {
                if(is_palindrome(words[i], j, words[i].size()-1))
                {
                    string prefix=words[i].substr(0,j);//does not include the whole s, but include ""
                    reverse(prefix.begin(), prefix.end());
                    if(dict.find(prefix)!=dict.end() && dict[prefix]!=i)
                        result.push_back({i, dict[prefix]});
                }
            }
            
            for(int j=0; j<=words[i].size(); ++j)
            {
                if(is_palindrome(words[i], 0, j-1))
                {
                    string prefix=words[i].substr(j);//include the whole s and should also include ""
                    //when j=words.size(), substr=""
                    reverse(prefix.begin(), prefix.end());
                    if(dict.find(prefix)!=dict.end() && dict[prefix]!=i)
                        result.push_back({dict[prefix], i});
                }
            }
            
        }
        
        return result;
        
    }
    
    bool is_palindrome(string& s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
        
    }
};
__________________________________________________________________________________________________
sample 31020 kb submission
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    typedef unordered_map<string,int> mapt;
    // index:  0 1 2 3 4
    //         a b c d e
    // index2: 01234567
    // p[i] = length of palindrome at index2 i
    vector<int> p;

    inline char mapStr(const string &s, int index){
        return index % 2 ? 0 : s[index/2];
    }
    // find the matching word that can form a complete palindrome
    void find(const mapt&m, vector<vector<int>>&ans, int index, int palinLen,const string &s,const string &sr, bool rev){
        string prefix = rev ? s.substr(palinLen): sr.substr(0, sr.size()-palinLen);
        mapt::const_iterator it =  m.find(prefix);

        if (it != m.end() && index != it->second){
            if (rev){
                ans.push_back({index, it->second});
            }
            else {
                ans.push_back({it->second, index });
            }
        }
    }
    void check(const mapt&m, vector<vector<int>>&ans, int index,const string &s, const string &sr, bool rev ){
        if (s.size()==0)
            return;
        int palinLenHalf = 0;

        const int maxIndex2 = s.size()*2-2;
        p.clear();
        p.reserve(maxIndex2+1);
        // manacher's algo
        for (int i=0,j=0;i<= maxIndex2;){
            // expand palindrome
            while (i-1-palinLenHalf >= 0 &&
                i+1+palinLenHalf <= maxIndex2 &&
                mapStr(s, i-1-palinLenHalf) == mapStr(s,i+1+palinLenHalf)){
                palinLenHalf++;
            }
            p[i]=1+palinLenHalf*2;
            const int ir = min(maxIndex2, i+palinLenHalf);
            palinLenHalf=0;
            for ( j=i+1; j <= ir; j++){
                const int jp = i-(j-i);
                const int jpl = p[jp];
                if (jpl/2 + j >= ir){
                    palinLenHalf = ir-j;
                    break;
                }
                p[j] = jpl;
            }
            i=j;
        }

        // find prefix that is a palindrome
        for (int i=0;i <=maxIndex2;i++){
            if (i-p[i]/2 == 0){
                const int palinLen = (p[i]+1)/2;
                // find the missing word needed
                find(m,ans,index, palinLen,s, sr, rev);
            }
        }
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        mapt m;
        m.reserve(words.size());
        int i=0;
        vector<vector<int>> ans;
        for (const string & s : words){
            m [s] = i++;
        }
        i=0;
        for (const string & s : words){
            string sr(s);
            reverse(sr.begin(),sr.end());
            // find prefixes that are palindrome
            check(m,ans,i,s,sr,false);
            // find suffixes that are palindrome
            check(m,ans,i,sr,s,true);
            // account for the zero-length prefix palindrome
            find(m,ans,i, 0, s,sr, false);
            i++;
        }
        return ans;
    }
};
__________________________________________________________________________________________________
