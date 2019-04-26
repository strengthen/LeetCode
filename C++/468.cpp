__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string validIPAddress(string IP) {
        int n = IP.length();
        char sep = '0';
        for(char c : IP){
            if(c == '.'){
                sep = '.';
                break;
            }
            if(c == ':'){
                sep = ':';
                break;
            }
        }
        if(sep == '0') return "Neither";
        if(sep == '.'){
            int j = 0;
            for(int i = 0; i < 4; ++i){
                int start = j;
                while(j < n && IP[j] != sep){
                    if(!isdigit(IP[j]))
                        return "Neither";
                    ++j;
                }
                if(start == j || j - start > 3 || stoi(IP.substr(start, j - start)) > 255 || j != start + 1 && IP[start] == '0') 
                    return "Neither";
                ++j;
            }
            if(j == n + 1)
                return "IPv4";
        }
        else {
            int j = 0;
            for(int i = 0; i < 8; ++i){
                int start = j;
                while(j < n && IP[j] != sep){
                    if(!isdigit(IP[j]) && (IP[j] < 'a' || IP[j] > 'f') && (IP[j] < 'A' || IP[j] > 'F'))
                        return "Neither";
                    ++j;
                }
                if(start == j || j - start > 4) 
                    return "Neither";
                ++j;
            }
            if(j == n + 1)
                return "IPv6";
        }
        return "Neither";
    }
};
__________________________________________________________________________________________________
sample 8752 kb submission
class Solution {
public:
    string validIPAddress(string IP) {
        size_t N = IP.length();
        int kind = 0;
        char sep;
        size_t segLen;
        size_t segEndPos = string::npos;
        int lp = min(5, (int) N);
        for (int i = 0; i < lp; i++) {
            sep = IP.at(i);
            if (sep == '.' || sep == ':') {
                segEndPos = i;
                break;
            }
        }
        if (segEndPos == string::npos) return "Neither";
        if (sep == '.') {
            kind = 1;
            segLen = 3;
        } else if (sep == ':') {
            kind = 2;
            segLen = 4;
        }
        //cout << "Kind: " << kind << endl;
        size_t segStartPos = 0, length = 0, segCount = 0;
        for (int i = 0; i < N; i++) {
            if (kind == 1 && segCount >= 4) return "Neither";
            if (kind == 2 && segCount >= 8) return "Neither";
            char c = IP.at(i);
            if (c != sep)
            {
                if (kind == 1 && !(c >= '0' && c <= '9'))
                    return "Neither";
                if (kind == 2 && !((c >= '0' && c <= '9') 
                    || (c >= 'a' && c <= 'f') 
                    || (c >= 'A' && c <= 'F')))
                    return "Neither";
                length++;
            }
            
            if (length < 1 || length > segLen) return "Neither";
            
            if (c == sep || i == N - 1) {
                if (c == sep && i == N-1) return "Neither";
                if (kind == 1)
                {
                    if (length > 1 && IP.at(segStartPos) == '0') return "Neither";
                    auto str = IP.substr(segStartPos, length);
                    int num = stoi(str);
                    if (num > 255) return "Neither";
                }
                segCount++;
                length = 0;
                segStartPos = i + 1;
                continue;
            }
        }
        if (kind == 1 && segCount == 4) return  "IPv4";
        if (kind == 2 && segCount == 8) return "IPv6";
        return "Neither";
    }
};
__________________________________________________________________________________________________
