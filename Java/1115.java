__________________________________________________________________________________________________
sample 15 ms submission
import java.util.concurrent.Semaphore;

class FooBar {
    private int n;
    private Semaphore semaFoo;
    private Semaphore semaBar;

    public FooBar(int n) {
        this.n = n;
        this.semaFoo = new Semaphore(1);
        this.semaBar = new Semaphore(0);
    }

    public void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            semaFoo.acquire();
            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            semaBar.release();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            semaBar.acquire();
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            semaFoo.release();
        }
    }
}
__________________________________________________________________________________________________
sample 17 ms submission
import java.util.concurrent.atomic.*;

class FooBar {
    final private int n;
    private AtomicBoolean check = new AtomicBoolean(false);

    public FooBar(int n) {
        this.n = n;
    }

    public synchronized void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            while(check.get()){
                wait();
            }
            if(check.compareAndSet(false,true))
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	printFoo.run();
            if(check.compareAndSet(false,true));
            notify();
        }
    }

    public synchronized void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            while(!check.get()){
                wait();
            }
            if(check.compareAndSet(true,false))
            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();
            notify();
        }
    }
}
__________________________________________________________________________________________________
