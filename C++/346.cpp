__________________________________________________________________________________________________
class MovingAverage {
public:
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }
    
    double next(int val) {
        if (q.size() >= size) {
            sum -= q.front(); q.pop();
        }
        q.push(val);
        sum += val;
        return sum / q.size();
    }
    
private:
    queue<int> q;
    int size;
    double sum;
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
