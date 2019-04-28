__________________________________________________________________________________________________
typedef pair<int, int> pint;
typedef vector<pint> vpint;

class pcomp {
    public:
    
    bool operator()(const pint& p1, const pint&p2){
        return p1.first<p2.first;
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // positions aren't sorted!
        vpint plist;
        for(int pos=0; pos<position.size(); pos++){
            plist.push_back(pint(position.at(pos), speed.at(pos)));
        }
        sort(plist.begin(), plist.end(), pcomp());
        int tot_fleets = 0;
        double next_fleet_arrival = -1.0, curr_arrival_time=-1.0;
        for(int pos=plist.size()-1; pos>=0; pos--){
            curr_arrival_time = (target-plist.at(pos).first)*1.0/plist.at(pos).second;
            if(curr_arrival_time>next_fleet_arrival){
                tot_fleets++;
                next_fleet_arrival = curr_arrival_time;
            }
        }
        return tot_fleets;
    }
};

static int optimize = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
__________________________________________________________________________________________________
sample 10732 kb submission
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size()<=1) return position.size();
        vector<int> ind(position.size());
        int i = 0;
        iota(ind.begin(),ind.end(),i++);
        sort(ind.begin(),ind.end(),[&](int a,int b){return position[a]>position[b];});
        int last = 0;
        int fleets = 1;
        double tar = target;
        for(int i = 0; i<ind.size(); i++)
        {
            if( (tar - position[ind[last]])*speed[ind[i]]<(tar - position[ind[i]])*speed[ind[last]])
            {
                fleets++; last = i;
            }
        }
        return fleets;
    }
};
__________________________________________________________________________________________________
