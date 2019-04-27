__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string toLowerCase(string str) {
        for (char &c : str) {
            if (c >= 'A' && c <= 'Z') c += 32;
        }
        return str;
    }
};
__________________________________________________________________________________________________
sample 7996 kb submission
class Solution {
public:
    string toLowerCase(string str) 
    {
        int d = 'a' - 'A';
        for(int i=0;i<str.size();i++)
        {
            if(str[i]>='A' && str[i]<='Z')
            {
                str[i] += d;
            }
        }
        
        return str;
    }
};
__________________________________________________________________________________________________
