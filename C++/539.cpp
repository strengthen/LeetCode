__________________________________________________________________________________________________
sample 12 ms submission
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        std::vector<short> help(timePoints.size());
        int index = 0;
        for(auto &str:timePoints){
            int hour = (str[0]-'0')*10 + (str[1]-'0');
            int minute = (str[3]-'0')*10 + (str[4]-'0');
            help[index] = hour*60 + minute;
            index++;
        }
        
        std::sort(help.begin(),help.end());
        
        int diff = 60*24;
        int len = help.size();
        for(int i=0;i<len-1;i++){
            if(diff>help[i+1]-help[i]) diff = help[i+1]-help[i];
        }
        
        if(diff>(60*24+help[0]-help[len-1])) diff = 60*24+help[0]-help[len-1];
        return diff;
    }
};
__________________________________________________________________________________________________
sample 12152 kb submission
class Solution {
private:
    int minutes(string s)
    {
        int a,b;
        a=s[4]+10*s[3];
        b=s[1]+10*s[0];
        return (b*60)+a;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int n=timePoints.size();
        int mind=INT_MAX;
        int a,b;
        for(int i=0;i<n;i++)
        {
           a=minutes(timePoints[i]);
           b=minutes(timePoints[(i+n-1)%n]);
            a=a-b;
            if(a<0)a+=1440;
            if(a<mind)mind=a;
        }
        return mind;
    }
};
__________________________________________________________________________________________________
