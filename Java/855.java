__________________________________________________________________________________________________
sample 47 ms submission
class ExamRoom {

    int N;
    PriorityQueue<Interval> pq;
    
    public ExamRoom(int N) {
        this.N = N;
        this.pq = new PriorityQueue<>((a, b) -> {
           if (a.length != b.length) {
               return b.length - a.length;
           } 
            return a.start - b.start;
        });
        this.pq.offer(new Interval(0, N - 1, N));
    }
    
    public int seat() {
        
        Interval i = pq.poll();
        int result = 0;
        
        if (i.start == 0) {
            result = 0;
            if (1 <= i.end)
            pq.offer(new Interval(1, i.end, N));
            return result;
        } else if (i.end == N - 1) {
            result = N - 1;
            if (i.start <= N - 2)
            pq.offer(new Interval(i.start, N - 2, N));
            return result;
        }
        result = i.length + i.start;
        if (i.start <= result - 1)
        pq.offer(new Interval(i.start, result - 1, N));
        if (result + 1 <= i.end)
        pq.offer(new Interval(result + 1, i.end, N));
        
        return result;
    }
    
    public void leave(int p) {
        List<Interval> list = new ArrayList<>(pq);
        
        Interval prev = null;
        Interval next = null;
        
        for (Interval i : list) {
            if (i.start - 1 == p) {
                next = i;
            }
            if (i.end + 1 == p) {
                prev = i;
            }
        }
        pq.remove(prev);
        pq.remove(next);
        pq.offer(new Interval(prev == null ? p : prev.start, next == null ? p : next.end, N));
    }
}

public class Interval {
    int start;
    int end;
    
    int length;
    
    public Interval(int start, int end, int N) {
        this.start = start;
        this.end = end;
        
        if (start == 0 || end == N - 1) {
            this.length = end - start;
        } else {
           this.length = (end - start) / 2; 
        }
    }
}
__________________________________________________________________________________________________
sample 34784 kb submission
class ExamRoom {
    
    int N;
    ArrayList<Integer> L = new ArrayList<>();
    public ExamRoom(int n) {
        N = n;
    }

    public int seat() {
        if (L.size() == 0) {
            L.add(0);
            return 0;
        }
        int d = Math.max(L.get(0), N - 1 - L.get(L.size() - 1));
        for (int i = 0; i < L.size() - 1; ++i) d = Math.max(d, (L.get(i + 1) - L.get(i)) / 2);
        if (L.get(0) == d) {
            L.add(0, 0);
            return 0;
        }
        for (int i = 0; i < L.size() - 1; ++i)
            if ((L.get(i + 1) - L.get(i)) / 2 == d) {
                L.add(i + 1, (L.get(i + 1) + L.get(i)) / 2);
                return L.get(i + 1);
            }
        L.add(N - 1);
        return N - 1;
    }

    public void leave(int p) {
        for (int i = 0; i < L.size(); ++i) if (L.get(i) == p) L.remove(i);
    }
}

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
__________________________________________________________________________________________________
