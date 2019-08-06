__________________________________________________________________________________________________
sample 72 ms submission
class FooBar {
private:
    int n;
    atomic_bool state;
public:
    FooBar(int n) {
        this->n = n;
        state = false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            while( state )
                this_thread::yield();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            state = !state;
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            while( !state )
                this_thread::yield();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            state = !state;
        }
    }
};
__________________________________________________________________________________________________
sample 88 ms submission
class FooBar {
private:
    int n;
    atomic<bool> goFoo, goBar;
public:
    FooBar(int n) {
        this->n = n;
        goFoo = true;
        goBar = false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            while (!goFoo) {
                this_thread::yield();
            }
                       
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            
            goFoo = false;
            goBar = true;
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            while (!goBar){
                this_thread::yield();
            }
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            
            goBar = false;
            goFoo = true;
        }
    }
};
__________________________________________________________________________________________________
