__________________________________________________________________________________________________
sample 72 ms submission
static auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class MyCalendarThree {
private:
    map<int, int> count = {{-1,0}};
    int res = 0;
public:
    int book(int s, int e) {
        auto start = count.emplace(s, (--count.lower_bound(s))->second).first;
        auto end = count.emplace(e, (--count.lower_bound(e))->second).first;
        for (auto i = start; i != end; ++i) res = max(res, ++(i->second));
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
__________________________________________________________________________________________________
sample 23304 kb submission
class MyCalendarThree {
public:
    MyCalendarThree() : elementNumber(0) {
    }
    
    int book(int start, int end) {
        startIndices.push_back(start);
        sort(startIndices.begin(), startIndices.end());
        endIndices.push_back(end);
        sort(endIndices.begin(), endIndices.end());
        elementNumber += 2;

        int maxBooking = 0;
        int currentBooking = 0;
        int startPosition = 0;
        int endPosition = 0;   
        for (int i=0; i<elementNumber-1; ++i) {
            if (startPosition == startIndices.size()
                || startIndices[startPosition] >= endIndices[endPosition]) {
                ++endPosition;
                --currentBooking;
            } else {
                ++startPosition;
                ++currentBooking;
                maxBooking = max(maxBooking, currentBooking);                
            }
            
        }  
        return maxBooking;
    }
private:
    vector<int> startIndices;
    vector<int> endIndices;
    int elementNumber;    
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
__________________________________________________________________________________________________
