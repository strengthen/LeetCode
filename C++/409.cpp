__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        int length = 0;
        
        for (int i = 0; i < s.length(); i++){
            map[s[i]]++; 
        }
        
        for (auto &pair : map){

                if (pair.second % 2 == 0){
                    length += pair.second;
                    pair.second -= pair.second;
                } 
                else {
                    length += (pair.second - 1);
                    pair.second = 1;
                }
        }
        
        for (auto pair2 : map){
            if (pair2.second == 1){
                length++;
                break;
            }
        }
        
        return length;
    }
};
__________________________________________________________________________________________________
sample 9120 kb submission
class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()==0)
        {
            return 0;
        }
        int res=0;
        array<int,52>t_count{0};
        for(auto c:s)
        {
            if(c>='A'&&c<='Z')
            {
                t_count[c-'A'+26]++;
            }
            else
            {
                t_count[c-'a']++;
            }
        }
        bool flag=true;
        for(auto i:t_count)
        {
            if(flag&&i%2)
            {
                res++;
                flag=false;
            }
            int temp=i/2;
            res+=temp*2;
        }
        return max(1,res);
    }
};
__________________________________________________________________________________________________
