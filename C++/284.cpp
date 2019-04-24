__________________________________________________________________________________________________
sample 4 ms submission
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

#insert <stack>
using namespace std;

class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
    private:
    
    stack <int> mVals;
    
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(mVals.empty()){
            int val = Iterator::next();
            mVals.push(val); 
            return val;
        } else
            return mVals.top();
        
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if(mVals.empty()){
            return Iterator::next();
        } else {
             int val = mVals.top();
             mVals.pop();
            return val;
        }
	    
	}

	bool hasNext() const {
        return (mVals.empty()) ?
             Iterator::hasNext() :
             true;
	}
};
__________________________________________________________________________________________________
sample 9716 kb submission
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	int current = 0;
    bool hasnext  = true;
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        
        if(Iterator::hasNext()) {
            current = Iterator::next();
            hasnext = true;
        }
        else
            hasnext  = false;
        
    }
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        
       if(!hasnext)
           return -1;
        else
            return current;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
       
        int temp  =  current;
        
        if(Iterator::hasNext())
            current  = Iterator::next();
        else
            hasnext  = false;
        
        return  temp;
        
    }
    
    bool hasNext() const {
        return hasnext;
    }
};
__________________________________________________________________________________________________
