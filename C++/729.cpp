__________________________________________________________________________________________________
sample 80 ms submission
int FASTIO = [](){ios::sync_with_stdio(0); cin.tie(0); return 0;}();

class MyCalendar {
	map<int, int> calender;
public:
	MyCalendar() {
		
	}

	bool book(int start, int end) {

		map<int, int>::iterator id = calender.upper_bound(start);
		
		if (calender.size() == 0)
		{
			calender.insert(std::make_pair(start, end));
			return true;
		}
		
		
		if (id != calender.end() && end > id->first)
			return false;

		if (id != calender.begin())
		{
			id--;
			int prevStart = id->first;
			int prevEnd = id->second;

			if (start >= prevStart && start < prevEnd)
				return false;			
		}

		calender.insert(std::make_pair(start, end));
		return true;
	}
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
__________________________________________________________________________________________________
sample 35044 kb submission
class MyCalendar {
private:
    vector<pair<int, int>> list;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bool flag = true;
        for (int i = 0; i < list.size(); i++) {
            if (start >= list[i].first && start < list[i].second)
                flag = false;
            else if (end <= list[i].second && end > list[i].first)
                flag = false;
            else if (start < list[i].first && end > list[i].second)
                flag = false;
            if (!flag)
                return false;
        }
        list.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
__________________________________________________________________________________________________
