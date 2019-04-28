__________________________________________________________________________________________________
sample 8 ms submission
static const auto ___ = [](){
    std::cout.sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int m=-1,c=0;
        for(auto i:seats) if(i==1){m=(m==-1?2*c:max(c,m));c=0;} else c++;
        return (2*c>=m&&seats[seats.size()-1]==0)?c:(m+1)/2;
    }
};
__________________________________________________________________________________________________
sample 10076 kb submission
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int distance=1,maxsize=1;
        for(int i=0;i<seats.size();i++){
            if(seats[i]==0){
                distance++;
            }
            if(seats[i]==1){
                
               maxsize=max(distance/2,maxsize);
                distance=1;
            } 
            
        }
         maxsize=max(distance-1,maxsize);
        distance=1;
         for(int i=0;i<seats.size(),seats[0]==0;i++){
            if(seats[i]==0){
                distance++;
            }
            if(seats[i]==1){
                
               maxsize=max(distance-1,maxsize);
                distance=1;
                break;
            } 
        }
        return maxsize;
    }
};
__________________________________________________________________________________________________
