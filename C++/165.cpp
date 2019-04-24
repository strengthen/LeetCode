__________________________________________________________________________________________________
4ms
class Solution {
public:
    int compareVersion(string version1, string version2) {
        while(version1.size()>0 || version2.size()>0){
            int v1 = 0,v2 = 0;
            if(version1.find(".")!=version1.npos){
                v1 = atoi(version1.substr(0,version1.find(".")).c_str());
                version1 = version1.substr(version1.find(".")+1);
            }
            else{
                v1 = atoi(version1.c_str());
                version1 = "";
            }
            if(version2.find(".")!=version2.npos){
                v2 = atoi(version2.substr(0,version2.find(".")).c_str());
                version2 = version2.substr(version2.find(".")+1);
            }
            else{
                v2 = atoi(version2.c_str());
                version2 = "";
            }
            if(v1 > v2) return 1;
            else if(v1 < v2) return -1;
        }
        return 0;
    }
};
__________________________________________________________________________________________________
8100 kb
class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int n1(version1.size()), n2(version2.size());
        
        int i(0), j(0);
        
        while (i < n1 || j < n2) {
            int v1(0), v2(0);
            while (i < n1 && version1[i] != '.') v1 = v1*10 + version1[i++]-'0';
            while (j < n2 && version2[j] != '.') v2 = v2*10 + version2[j++]-'0';
            
            if (v1 < v2) return -1;
            if (v1 > v2) return 1;
            ++i; ++j;
        }
        
        return 0;
    }
};
__________________________________________________________________________________________________
