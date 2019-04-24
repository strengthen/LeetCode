__________________________________________________________________________________________________
sample 120 ms submission
static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class MedianFinder {
public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int Num) {
    if (LowerHalf.empty()) {
      LowerHalf.push(Num);
      return;
    }
    
    if (Num <= LowerHalf.top())
      LowerHalf.push(Num);
    else
      UpperHalf.push(Num);
    
    if (LowerHalf.size() > UpperHalf.size() + 1) {
      UpperHalf.push(LowerHalf.top());
      LowerHalf.pop();
    } else if (UpperHalf.size() > LowerHalf.size() + 1) {
      LowerHalf.push(UpperHalf.top());
      UpperHalf.pop();
    }
  }

  double findMedian() {
    const auto Size = LowerHalf.size() + UpperHalf.size();
    //assert(Size > 0 && "no number");
    
    if (Size % 2 != 0) {
      return LowerHalf.size() > UpperHalf.size() ? 
        LowerHalf.top() : UpperHalf.top();
    } else
      return (LowerHalf.top() + UpperHalf.top()) / 2.0;
  }

private:
  std::priority_queue<int> LowerHalf;
  std::priority_queue<int, std::vector<int>, std::greater<int>> UpperHalf;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
__________________________________________________________________________________________________
sample 42244 kb submission
class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> data;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int start = 0;
        int end = data.size() - 1;
        if(data.empty())
        {
            data.push_back(num);
            return;
        }
        while(start + 1 < end) {
            int mid = (start + end) >> 1;
            if(data[mid] <= num)
                start = mid;
            else
                end = mid - 1;
        }
        int pos;
        if(end >=0 && data[end] <= num)
            pos = end;
        else if(start >=0 && data[start] <= num)
            pos = start;
        else
            pos = start - 1;
        data.insert(data.begin() + pos + 1, num);
        return;
    }
    
    double findMedian() {
        if(data.size() % 2 == 0)
        {
            return ((double)(data[data.size()/2]) + (double)(data[data.size()/2-1])) / 2.0;  
        }
        else
        {
            cout<<data.size()<<endl;
           return data[data.size()/2]; 
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
__________________________________________________________________________________________________
