__________________________________________________________________________________________________
sample 4 ms submission
import java.util.concurrent.Semaphore;
class ZeroEvenOdd {
    private int n;
    
    public Semaphore sem0 = new Semaphore(1);
    public Semaphore sem1 = new Semaphore(0);
    public Semaphore sem2 = new Semaphore(0);
    
    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i=0 ; i<n; i++) {
             sem0.acquire();
             printNumber.accept(0);

            if (i % 2 == 0){
                sem1.release();
            } else {
                sem2.release();
            }
        }
        
         
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i=2 ; i<=n; i=i+2) {
            sem2.acquire();
            printNumber.accept(i);
            sem0.release();
           
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i=1 ; i<=n; i=i+2) {
             sem1.acquire();
             printNumber.accept(i);
             sem0.release(); 
        }
    }
}
__________________________________________________________________________________________________
8ms
import java.util.concurrent.locks.*;
class ZeroEvenOdd {
    private int n;
    private volatile boolean e = false;
    private volatile boolean o = false;
    private ReentrantLock lock = new ReentrantLock();
    private Condition zeroCondition = lock.newCondition();
    private Condition evenCondition = lock.newCondition();
    private Condition oddCondition = lock.newCondition();


    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            lock.lock();
            try {
                if (i != 1) {
                    zeroCondition.await();
                }
                printNumber.accept(0);
                if (isOdd(i)) {
                    o = true;
                    oddCondition.signal();
                } else {
                    e = true;
                    evenCondition.signal();
                }
            } finally {
                lock.unlock();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i += 2) {
            lock.lock();
            try {
                while (!e) {
                    evenCondition.await();
                }
                e = false;
                printNumber.accept(i);
                zeroCondition.signal();
            } finally {
                lock.unlock();
            }
        }

    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i += 2) {
            lock.lock();
            try {
                while (!o) {
                    oddCondition.await();
                }
                o = false;
                printNumber.accept(i);
                zeroCondition.signal();
            } finally {
                lock.unlock();
            }
        }
    }

    private static boolean isOdd(final int number) {
        return (number & 1) == 1;
    }
}
__________________________________________________________________________________________________
