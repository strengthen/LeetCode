__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int len = preorder.size();
        if(len == 0)
            return true;
        int n = 0;
        for(int i = len-1; i >= 0; i--){
            if(preorder[i] == ',')
                continue;
            else if(preorder[i] == '#')
                n++;
            else{
                if(n >= 2){
                    n--;
                    while(i >= 0 && preorder[i] != ',')
                        i--;
                }
                else
                    return false;
            }
        }
        if(n == 1)
            return true;
        else
            return false;
    }
};
__________________________________________________________________________________________________
sample 8508 kb submission
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.size() == 0)
            return false;
        
        int spaces = 1;
        
        for(int i = 0; i < preorder.size(); ++i) {
            spaces--;

            if(spaces < 0)
                return false;
            
            if(preorder[i] != '#')
                spaces += 2;
            
            while(i < preorder.size() && preorder[i] != ',')
                i++;
        }
        
        if(spaces == 0)
            return true;
        
        return false;
    }
};
__________________________________________________________________________________________________
