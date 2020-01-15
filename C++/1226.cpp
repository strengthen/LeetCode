__________________________________________________________________________________________________
sample 64 ms submission
class DiningPhilosophers {
    int n;
    vector<std::mutex> fork_locks; 
public:
    DiningPhilosophers() {
        n = 5;
        fork_locks = vector<std::mutex>(n);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		int left_id = philosopher % n;
        int right_id = (philosopher+1) % n;

        if (philosopher % n == 1) {
            fork_locks[right_id].lock();
            fork_locks[left_id].lock();
            pickRightFork();
            pickLeftFork();
            eat();
            putLeftFork();
            putRightFork();
            fork_locks[left_id].unlock();
            fork_locks[right_id].unlock();
        } else {
            fork_locks[left_id].lock();
            fork_locks[right_id].lock();
            pickRightFork();
            pickLeftFork();
            eat();
            putLeftFork();
            putRightFork();
            fork_locks[right_id].unlock();
            fork_locks[left_id].unlock();
        }
    }
};

class DiningPhilosophers2 {
    mutex *ms;
    
public:
    DiningPhilosophers2() {
        ms = new mutex[5];
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		int first_lock = -1, second_lock = -1;
        if (philosopher == 4) {
            first_lock = 4;
            second_lock = 0;
        }
        else if (philosopher % 2 == 0) {
            first_lock = philosopher;
            second_lock = philosopher+1;
        } else {
            first_lock = philosopher+1;
            second_lock = philosopher;
        }
        
        //cout << first_lock << " " << second_lock << endl;
        
      //  scoped_lock lock(ms[first_lock], ms[second_lock]);
        ms[first_lock].lock();
        ms[second_lock].lock();
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        
        ms[second_lock].unlock();
        ms[first_lock].unlock();
    }
};
__________________________________________________________________________________________________
sample 68 ms submission
class DiningPhilosophers {
public:
    DiningPhilosophers() {
    }
    ~DiningPhilosophers() = delete;

    
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        if (philosopher == 0) {
            this->do_after_other(N - 1, pickRightFork, putRightFork, 0, pickLeftFork, putLeftFork, eat);
        } else {
            this->do_after_other(philosopher, pickLeftFork, putLeftFork, philosopher - 1, pickRightFork, putRightFork, eat);
        }
    }
    
private:
    static constexpr int N = 5;
    array<mutex, N> forks;
    
    void do_after_other(
        int idx1, function<void()> prepare1, function<void()> cleanup1,
        int idx2, function<void()> prepare2, function<void()> cleanup2,
        function<void()> action) {
        
        lock_guard<mutex> lk_1(this->forks[idx1]);
        lock_guard<mutex> lk_2(this->forks[idx2]);
        prepare1();
        prepare2();
        action();
        cleanup1();
        cleanup2();
    }           
};
__________________________________________________________________________________________________
