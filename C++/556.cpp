__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int nextGreaterElement(int n) {
        
        string temp = std::to_string(n);
        int i = temp.size()-1;
        while(i > 0 && temp[i] <= temp[i-1])
        {
            i--;
        }
        
        if(i == 0)
        {
            return -1;
        }
        
        int j = i-1;
        i = temp.size()-1;
        while(temp[j] >= temp[i])
        {
            i--;
        }
        
        std::swap(temp[j], temp[i]);
        std::sort(temp.begin()+j+1, temp.end());
        long res = std::stol(temp);
        return res > INT_MAX ? -1 : res;
    }
};
__________________________________________________________________________________________________
sample 8256 kb submission
class Solution {
public:
    int nextGreaterElement(int n) {
        int num = n;
        string s = "";
        while(n) {
            s += (char)(n%10) + '0';
            n = n/10;
        }
        
        reverse(s.begin(), s.end());
        int i;
        for(i = s.size() - 2; i >= 0; i--) {
            if(s[i] - '0' < s[i+1] - '0') {
                break;
            }
        }
        //cout << s << "  " << i << endl; 
        if(i < 0) {
            return -1;
        }
        int swapVal = (int)(s[i] - '0');
        int nextG = INT_MAX;
        int sIndex = i;
        for(int j = i+1; j < s.size(); j++) {
            int tt = (int)(s[j] - '0');
            if(tt > swapVal && tt <= nextG) {
                nextG = tt;
                sIndex = j;
            }
        }
        //cout << sIndex << "  " << nextG << endl;
        swap(s[i], s[sIndex]);
        reverse(s.begin() + i + 1, s.end());
        //cout << s << endl;
        long long int res = 0;
        for(int j = 0; j < s.size(); j++) {
            res = res*10 + (int)(s[j] - '0');
        }
        if(res > INT_MAX) return -1;
        return res;
    }
};
__________________________________________________________________________________________________
