__________________________________________________________________________________________________
sample 24 ms submission
class FizzBuzz {
private:
    int                 n;
    mutex               mtx;
    condition_variable  cv;
    int                 item = 1;
    
public:
    
    FizzBuzz(int n) {
        this->n = n;
    }
    
    /*
     * While item has not reached n, we wait until a condition is met. If the condition
     * is met, we execute a function and wake all the others waiting for a condition to 
     * be met.
     */
    #define CONSUMER(cond, fn) while (item <= n) {                          \
                                    unique_lock<mutex> lck(mtx);            \
                                    if (!(cond)) {                          \
                                        cv.wait(lck);                       \
                                        continue;                           \
                                    }                                       \
                                    fn; item++; cv.notify_all();            \
                                }   
    
    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) { 
        CONSUMER(!(item % 3) && (item % 5), printFizz()); 
    }
    
    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        CONSUMER((item % 3) && !(item % 5), printBuzz())
    }
    
    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        CONSUMER(!(item % 3) && !(item % 5), printFizzBuzz())
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        CONSUMER((item % 3) && (item % 5), printNumber(item));
    }
};
__________________________________________________________________________________________________
sample 32 ms submission
class FizzBuzz {
private:
    int n;
    
    int num;
    
public:
    FizzBuzz(int n) {
        this->n = n;
        
        num = 1;
    }

    //maybe for each function, have a while loop until it reaches n
    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
                        //check to see if number is factor of 3
            //if so, yield thread
        while(num<=n){
            
            if(num%3 != 0 || num%15==0){
                std::this_thread::yield();
                continue;
            }
            
            printFizz();
            num++;
        }
       
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
                    //check to see if number is factor of 5,
            //if so, yield thread
        while(num<=n){
            
            if(num%5!=0 || num%15==0 ){
                std::this_thread::yield();
                continue;
            }
            
            printBuzz();
            num++;
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
                //check to see if number is factor of 3, 5,
            //if so, yield thread
        
        while(num<=n){
            
            if(num%3 != 0 || num%5!=0){
                std::this_thread::yield();
                continue;
            }
            
            printFizzBuzz();
            num++;
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        
        //check to see if number is factor of 3, 5,
            //if so, yield thread
        while(num<=n){
            
            if(num%3 == 0 || num%5==0){
                
                std::this_thread::yield();
                continue;
            }
            
            printNumber(num);
            num++;
        }
    }
};
__________________________________________________________________________________________________
