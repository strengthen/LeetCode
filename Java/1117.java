__________________________________________________________________________________________________
sample 3 ms submission
import java.util.concurrent.locks.*; 
import java.util.concurrent.*;

public class H2O {
    private int wH, wO;
    private Lock lock;
    private Condition waitingH, waitingO, barrier;
    private int aH, aO;

    public H2O() {
        wH = 0;
        wO = 0;
        aH = 0;
        aO = 0;
        lock = new ReentrantLock();
        waitingH = lock.newCondition();
        waitingO = lock.newCondition();
        barrier = lock.newCondition();
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        lock.lock();
        try {
          wH++;
          // while not allowed to leave
          while (aH == 0) {
            if (wH >= 2 && wO >= 1) {
              if (aO > 0) {
                  barrier.await();
              }
              wH-=2; aH+=2;
              wO-=1; aO+=1;
              waitingH.signal();
              waitingO.signal();
            } else {
              waitingH.await();
              barrier.signal();
            }
          }
          aH--;
        } finally {
            releaseHydrogen.run();
            lock.unlock();
        }
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        lock.lock();
        try {
          wO++;

          while (aO == 0) {
            if (wH >= 2 && wO >= 1) {
              if (aH > 0) {
                  barrier.await();
              }
              wH-=2; aH+=2;
              wO-=1; aO+=1;
              waitingH.signal();
              waitingH.signal();
            } else {
              waitingO.await();
              barrier.signal();
            }
          }
          aO--;
        } finally {
            releaseOxygen.run();
            lock.unlock();
        }

    }
}
__________________________________________________________________________________________________
sample 13 ms submission
import java.util.concurrent.Semaphore;
class H2O {
    
    Semaphore h, o;
    volatile boolean flag = false;
    public H2O() {
        h = new Semaphore(2, true);
        o = new Semaphore(0, true);
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		h.acquire();
        releaseHydrogen.run();
        o.release();
        
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        o.acquire(2);
		releaseOxygen.run();
        h.release(2);
    }
}
__________________________________________________________________________________________________
