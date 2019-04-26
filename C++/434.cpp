__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int countSegments(string s) {
        int count=0;
        if(s=="")
            return 0;
        s.push_back(' ');
        for(int i=1;i<s.size();i++)
        {
            if(s.at(i)==' ')
            {
                count++;
                if(s.at(i-1)==' ')
                    count--;
            }
        }
        return count;
    }
};
__________________________________________________________________________________________________
× Close
sample 8328 kb submission
class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        char pre = ' ';
        for (char cur : s) {
            if (pre == ' ' && cur != ' ') count++;
            pre = cur;
        }
        return count;
    }
};
__________________________________________________________________________________________________
