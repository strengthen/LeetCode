__________________________________________________________________________________________________
sample 8 ms submission
class ZeroEvenOdd {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    int curr;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->curr = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++){
            std::unique_lock<std::mutex> lk(mtx);
            cv.wait(lk, [this]() {
                return curr == 0;
            });
            printNumber(0);
            curr = i %2 == 0 ? 1 : 2;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i++ ) {
            if (i %2 == 0) {
                std::unique_lock<std::mutex> lk(mtx);
                cv.wait(lk, [this]() {
                    return this->curr == 2;
                });
                printNumber(i);
                curr = 0;
                cv.notify_all();
            }
        }
    }

    void odd(function<void(int)> printNumber) {
         for (int i = 1; i <= n; i++ ) {
            if (i %2 == 1) {
                std::unique_lock<std::mutex>lk(mtx);
                cv.wait(lk, [this]() {
                    return this->curr == 1;
                });
                printNumber(i);
                curr = 0;
                cv.notify_all();
            }
        }
    }
};
__________________________________________________________________________________________________
sample 16 ms submission
class ZeroEvenOdd {
private:
    int n;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        zero_out = false;
        num = 1;
        done = false;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(true)
        {

            unique_lock<mutex> ul(mx);
            cond.wait(ul, [&](){return done || !zero_out;});
            if(num>n)
            {
                done = true;
                cond.notify_all();
                return;
            }
            printNumber(0);
            zero_out = true;    
            cond.notify_all();

        }

    }

    void even(function<void(int)> printNumber) {
        while(true)
        {
            unique_lock<mutex> ul(mx);
            cond.wait(ul, [&](){return done || zero_out&&(num%2==0);});
            if(num>n)
            {
                done = true;
                cond.notify_all();
                return;
            }
            printNumber(num);
            ++num;
            zero_out = false;   
                    cond.notify_all();

        }


    }

    void odd(function<void(int)> printNumber) {
        while(true)
        {

            unique_lock<mutex> ul(mx);
            cond.wait(ul, [&](){return done||zero_out&&(num%2==1);});
            
            if(num>n)
            {
                done = true;
                cond.notify_all();
                return;
            }
            printNumber(num);
            ++num;
            zero_out = false; 
            cond.notify_all();
        }

    }
private:
    int num;
    mutex mx;
    bool zero_out;
    bool done;
    condition_variable cond;
};
__________________________________________________________________________________________________
