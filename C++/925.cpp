__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        while(i<name.size()){
            if(name[i]==typed[j]){i++;j++;}
            else if (j > 0 && typed[j] == typed[j - 1]) {
              ++j;}
            else
              return false;
        }
        while (j < typed.size() && typed[j] == typed[j - 1]) ++j;
        return  j == typed.size();
    }
};
__________________________________________________________________________________________________
sample 8424 kb submission
static int speedup = [](){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

class Solution {
public:
    
    bool isLongPressedName(string name, string typed) {
        int n1 = name.size();
        int n2 = typed.size();
        
        int i = 0;
        int j = 0;
    
        while(i < n1 && j < n2){
            if(name[i] != typed[j]){
                return false;
            }
            i++;
            j++;
            int c1 = 1;
            int c2 = 1;
            while(i < n1 && (name[i] == name[i-1])){
                i++;
                c1++;
            }
            while(j < n2 && (typed[j] == typed[j-1])){
                j++;
                c2++;
            }
            if(c1 > c2){
                return false;
            }
        }
        if(i != n1 || j != n2){
            return false;
        }
        return true;
    }
};
__________________________________________________________________________________________________
