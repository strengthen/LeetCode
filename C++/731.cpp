__________________________________________________________________________________________________
sample 92 ms submission
class MyCalendarTwo {
public:
    bool book(int start, int end) {
        for (auto i : overlap) {
            if (start < i.second && i.first < end) return false;
        }        
        for (auto i : schedule) {
            if (start < i.second && i.first < end) {
                overlap.push_back({max(i.first,start),min(i.second,end)});
            }
        }        
        schedule.push_back({start,end});
        return true;
    }
    
    vector<pair<int,int>> schedule, overlap;
};

static auto x = [] {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
__________________________________________________________________________________________________
sample 31876 kb submission
class MyCalendarTwo {
private:
    vector<int> starts;
    vector<int> ends;
public:
    int find_insert_pos(vector<int>&list,int v){
        //cout<<"find------"<<endl;
        //list is sorted.
        if(list.size()<1) return 0;
        if(v<=list[0]) return 0;
        if(v>=list[list.size()-1]) return list.size();
        
        int s = 0;
        int e = list.size()-1;
        while(s<e-1){
            //list[e]>v
            //list[s]<v
            int m = (s+e)/2;
            if(list[m]==v) return m;
            if(list[m]>v) e = m;
            else s = m;
        }
        //cout<<"value: "<<v<<" ;index: "<<e<<endl;
        return e;
    }
    
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        if(starts.size()<1){
            starts.push_back(start);
            ends.push_back(end);
            return true;
        }
        int s_insert = find_insert_pos(starts,start);
        int e_insert = find_insert_pos(ends,end);
        starts.insert(starts.begin()+s_insert,start);
        ends.insert(ends.begin()+e_insert,end);
        
        int s=1;
        int overlap = 1;
        int e = 0;
        /*
        cout<<"starts------"<<endl;
        for(auto st:starts){
            cout<<st<<" ,";
        }
        cout<<endl;
        cout<<"ends--------"<<endl;
        for(auto ed:ends){
            cout<<ed<<" ,";
        }
        cout<<endl;
        
        */
        while(s<starts.size()){
            if(starts[s]<ends[e]){
                overlap++;
                s++;
            }else{
                overlap--;
                e++;
            }
            if(overlap==3){
                starts.erase(starts.begin()+s_insert);
                ends.erase(ends.begin()+e_insert);
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
__________________________________________________________________________________________________
