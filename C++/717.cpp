__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i=0;
if(bits.size()==1&&bits[0]==0) return true;
while(i<bits.size())
{if(bits[i]==0)
++i;
else i+=2;
if(i==bits.size()-1) return true;
}
return false;
    }
};
__________________________________________________________________________________________________
sample 8944 kb submission
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size() == 1 || bits[bits.size()-2] == 0){
        return true;
    }
    for(int i = 0; i != bits.size();){
        if(bits[i] == 1){
            i += 2;
        }else{
            i++;
        }
        if(i == bits.size()-1){
            return true;
        }
    }
    return false;
    }
};
__________________________________________________________________________________________________
