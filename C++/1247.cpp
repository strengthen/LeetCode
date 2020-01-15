__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int result=0;
        int xyCount=0, yxCount=0;
        if (s1.length() != s2.length()) return -1;
        for (int i=0; i<s1.length(); i++) {
            /*
                xxyyxyxyxx
                xyyxyxxxyx
                xy: 3, yx:3
                2 xy/yxs can be solved using 1 step
                1 xy+yx can be solved using 2 steps
                => xy/2 + yx/2 + xy%2*2
            */
            if (s1[i] == 'x' && s2[i] == 'y') xyCount += 1;
            if (s1[i] == 'y' && s2[i] == 'x') yxCount += 1;
        }
        if ((xyCount+yxCount)%2) return -1;
        
        int xySets = xyCount/2 + yxCount/2;
        int xyCrossSets = (xyCount%2)*2;
        return xySets + xyCrossSets;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int left=0,right=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                if(s1[i]=='x')
                    left++;
                else
                    right++;
            }
        }
        if((left+right)%2!=0)
            return -1;
        else{
            return (left)/2+right/2+((left)%2+right%2);
        }
    }
};
__________________________________________________________________________________________________
