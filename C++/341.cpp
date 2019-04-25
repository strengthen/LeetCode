__________________________________________________________________________________________________
sample 20 ms submission
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    queue<int> processor;
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        getFlattened(nestedList,processor);
        
    }

    int next() 
    {
        int nextval = processor.front(); processor.pop();
        return nextval;
        
    }

    bool hasNext() 
    {
        return !processor.empty();
        
    }
    
    void getFlattened(vector<NestedInteger>& nestedList, queue<int>& processor)
    {
        int n = nestedList.size();
        for (int i = 0; i < n; i++)
        {
            if (nestedList[i].isInteger()) processor.push(nestedList[i].getInteger());
            else getFlattened(nestedList[i].getList(),processor);
            
                
        }
        
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
__________________________________________________________________________________________________
sample 15784 kb submission
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    using const_iterator = vector<NestedInteger>::const_iterator;
    std::stack<std::pair<const_iterator, const_iterator>> m_active_ranges;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) : m_active_ranges() {
        if(nestedList.cbegin() != nestedList.cend())
            m_active_ranges.emplace(nestedList.cbegin(), nestedList.cend());
    }

    int next() {
        auto& [beg, _] = m_active_ranges.top();
        return beg++->getInteger();
    }

    bool hasNext() {
        while(!m_active_ranges.empty()) {
            auto& [beg, end] = m_active_ranges.top();
            if(beg == end) {
                m_active_ranges.pop();
            } else if(beg->isInteger()) {
                return true;   
            } else {
                const auto nbeg = beg->getList().cbegin();
                const auto nend = beg->getList().cend();
                ++beg;
                if(nbeg != nend)
                    m_active_ranges.emplace(nbeg, nend);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
__________________________________________________________________________________________________
