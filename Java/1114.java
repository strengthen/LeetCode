__________________________________________________________________________________________________
sample 7 ms submission
import java.util.concurrent.Semaphore;

class Foo {
    Semaphore second = new Semaphore(0);
    Semaphore third = new Semaphore(0);

    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        second.release();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        
        // printSecond.run() outputs "second". Do not change or remove this line.
        second.acquire();
        printSecond.run();
        third.release();
    }

    public void third(Runnable printThird) throws InterruptedException {
        
        // printThird.run() outputs "third". Do not change or remove this line.
        third.acquire();
        printThird.run();
    }
}
__________________________________________________________________________________________________
sample 9 ms submission
import java.util.concurrent.atomic.AtomicInteger;


class Foo {

    AtomicInteger ai = new AtomicInteger(1);
    
    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        while(ai.get() != 1);
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        ai.set(2);
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while(ai.get() != 2);
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        ai.set(3);
    }

    public void third(Runnable printThird) throws InterruptedException {
        while(ai.get() != 3);
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
        ai.set(1);
    }
}
__________________________________________________________________________________________________
