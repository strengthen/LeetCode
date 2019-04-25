__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    class point {
    public:
        int m_x;
        int m_y;
        point(int x, int y) : m_x(x), m_y(y) {}
        point() {}
    };
    
    class range {
    public:
        int start;
        int end;
        
        range(int s, int e) : start(s), end(s) {}
        range() {}
        void setrange(int s, int e) {start=s; end = e;}
        bool InRange(int value) { return value>=start && value <= end;}
    };
    
    class simpleline {
    public :
        point m_start;
        point m_end;
        bool vertical;
        int vertValue;
        range lineRange;
        bool valid;
        
        simpleline(point start, point end) : m_start(start), m_end(end) {
            if (start.m_x == end.m_x)
            {
                vertical = true;
                vertValue = start.m_x;
                lineRange.setrange(min(start.m_y, end.m_y), max(start.m_y, end.m_y));
            }
            else
            {
                vertical = false;
                vertValue = start.m_y;
                lineRange.setrange(min(start.m_x, end.m_x), max(start.m_x, end.m_x));
            }
            valid = true;
        }
        
        simpleline() {valid = false;}
        
        bool InRange(range s) {
            if (lineRange.InRange(s.start) || lineRange.InRange(s.end) ||
                s.InRange(lineRange.start) || s.InRange(lineRange.end))
                return true;
            else
                return false;
            
        }
        bool intersect(simpleline s) {
            if (vertical == s.vertical)
            {
                if (vertValue != s.vertValue) return false;
                
                return InRange(s.lineRange);
            }
            else
            {
                if (vertical)
                {
                    return lineRange.InRange(s.m_start.m_y) && s.lineRange.InRange(m_start.m_x);
                }
                else
                {
                    return lineRange.InRange(s.m_start.m_x) && s.lineRange.InRange(m_start.m_y);
                }                
            }
        }
    };
    
    vector<pair<int, int>> increment {make_pair(0, 1),
                                      make_pair(-1, 0),
                                      make_pair(0, -1),
                                      make_pair(1, 0)};
    
    int preDirection(int direction) { if(direction == 0) return 3; else return direction-1;}
    
    bool isSelfCrossing(vector<int>& x) {
        vector<simpleline> wall(4);    
        simpleline lastline;
        point lastpoint(0, 0);
        int direction = 0;
        
        for(int i=0; i<x.size();i++)
        {
            point nextpoint(lastpoint.m_x+x[i]*increment[direction].first,
                            lastpoint.m_y+x[i]*increment[direction].second);
            
            simpleline newline(lastpoint, nextpoint);
            
            for (auto& e:wall)
            {
                if (e.valid && e.intersect(newline))
                    return true;
            }
            
            if (lastline.valid)
            {
                wall[preDirection(direction)] = lastline;
            }
            
            lastline = newline;
            lastpoint = nextpoint;
            direction = (direction+1)%4;
        }
        
        return false;
    }
};
__________________________________________________________________________________________________
sample 8200 kb submission
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int n = x.size();
        for(int i=0; i<n; i++){
            if(i>=3 && x[i]>=x[i-2] && x[i-1]<=x[i-3]){return true;}
            if(i>=4 && x[i-1]==x[i-3] && x[i]+x[i-4]>=x[i-2]){return true;}
            if(i>=5 && x[i]+x[i-4]>=x[i-2] && x[i-5]+x[i-1]>=x[i-3] && x[i-2]>=x[i-4] && x[i-1] <= x[i-3]){return true;}
        }
        return false;
    }
};
__________________________________________________________________________________________________
