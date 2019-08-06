__________________________________________________________________________________________________
sample 28 ms submission
class H2O {
public:
    H2O() {
        m_a = 0;
        m_b = 0;
        m_sum = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        std::unique_lock<std::mutex> lock(m_mutex);
        m_cond.wait(lock, [this]{return m_a < 2;});
        releaseHydrogen();
        m_a++;
        m_sum++;
        if (m_sum == 3)
        {
            m_sum = 0;
            m_a = 0;
            m_b = 0;
            m_cond.notify_all();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        std::unique_lock<std::mutex> lock(m_mutex);
        m_cond.wait(lock, [this]{return m_b < 1;});
        releaseOxygen();
        m_b++;
        m_sum++;
        if (m_sum == 3)
        {
            m_sum = 0;
            m_a = 0;
            m_b = 0;
            m_cond.notify_all();
        }
    }
    
private:
    int m_a, m_b;
    int m_sum;
    std::mutex m_mutex;
    std::condition_variable m_cond;
};

__________________________________________________________________________________________________
sample 40 ms submission
class H2O {
    
    struct Semaphore {
        void lock() {
            unique_lock<mutex> l(m_);
            cv_.wait(l, [this]{return count_ > 0;});
            count_--;
        }
        void unlock() {
            unique_lock<mutex> l(m_);
            count_++;
            cv_.notify_all();
        }
        Semaphore(int count) : count_(count) {}
    private:
        int count_;
        mutex m_;
        condition_variable cv_;
    };
    
    Semaphore h_,o_;
    
    condition_variable cv_;
    mutex m_;
    int totalCount_ = 0;
    
    void barrier() {
        unique_lock<mutex> l(m_);
        totalCount_++;
        if (totalCount_ == 3) {
            totalCount_ = 0;
            cv_.notify_all();
        } else {
            cv_.wait(l);
        }
    }
public:
    H2O(): h_(2), o_(1) {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<Semaphore> l(h_);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        barrier();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<Semaphore> l(o_);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        barrier();
    }
};
__________________________________________________________________________________________________
sample 44 ms submission
class H2O {
    
    int h = 0;
    int o = 0;
    std::mutex m;
    std::condition_variable cv;
    
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {

        std::unique_lock<std::mutex> l(m);
        cv.wait(l, [this]{ return h < (o*2); });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++h;
        l.unlock();
        cv.notify_one();
    }
    
    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> l(m);
        cv.wait(l, [this]{ return h >= o * 2; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        ++o;
        l.unlock();
        cv.notify_one();
    }
};