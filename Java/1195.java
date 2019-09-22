__________________________________________________________________________________________________
sample 4 ms submission
class FizzBuzz {
    private int n;
    private Semaphore s0; // control the number as the main control logic.
    private Semaphore s3; // control the fizz 
    private Semaphore s5;  // control the buzz
    private Semaphore s15;  // control the fizzBuzz
    public FizzBuzz(int n) {
        this.n = n;
        s0 = new Semaphore(1);
        s3 = new Semaphore(0);
        s5 = new Semaphore(0);
        s15 = new Semaphore(0);
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        int i = 3; 
        while(i <= n) {
            s3.acquire();
            printFizz.run();
            s0.release();
            i+= 3; 
            if( i% 5 == 0) 
                i+=3;
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
          int i = 5; 
        while(i <= n) {
            s5.acquire();
            printBuzz.run();
            s0.release();
            i+= 5; 
            if( i% 3 == 0) 
                i += 5;
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
         int i = 15; 
        while(i <= n) {
            s15.acquire();
            printFizzBuzz.run();
            s0.release();
            i+= 15; 
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        int i = 1;
        while(i <= n) {
            s0.acquire();
            if( i % 5 == 0 && i % 3 == 0) {
                s15.release();
            } else if(i % 5 ==0 ) {
                s5.release();
            } else if( i %3 == 0) {
                s3.release();
            } else {
                printNumber.accept(i);               
                s0.release();
            }
            i++;
        }
    }
}
__________________________________________________________________________________________________
class FizzBuzz {
    
    private int n;
    private int currentNumber = 1;
    
    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public synchronized void fizz(Runnable printFizz) throws InterruptedException {
        while (currentNumber <= n) {
            if (currentNumber % 3 != 0 || currentNumber % 5 == 0) {
                wait();
                continue;
            }
            printFizz.run();
            currentNumber += 1;
            notifyAll();
        }
    }

    // printBuzz.run() outputs "buzz".
    public synchronized void buzz(Runnable printBuzz) throws InterruptedException {
        while (currentNumber <= n) {
            if (currentNumber % 5 != 0 || currentNumber % 3 == 0) {
                wait();
                continue;
            }
            printBuzz.run();
            currentNumber += 1;
            notifyAll();
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public synchronized void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        while (currentNumber <= n) {
            if (currentNumber % 15 != 0) {
                wait();
                continue;
            }
            printFizzBuzz.run();
            currentNumber += 1;
            notifyAll();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public synchronized void number(IntConsumer printNumber) throws InterruptedException {
        while (currentNumber <= n) {
            if (currentNumber % 3 == 0 || currentNumber % 5 == 0) {
                wait();
                continue;
            }
            printNumber.accept(currentNumber);
            currentNumber += 1;
            notifyAll();
        }
    }
}
__________________________________________________________________________________________________
