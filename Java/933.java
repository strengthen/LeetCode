__________________________________________________________________________________________________
sample 57 ms submission
class RecentCounter {

    private static final int MAX_INTERVAL = 3000;
    private static final int MAX_BUFFER_SIZE = MAX_INTERVAL + 2;
    
    private int[] buffer;
    private int bufferStart;
    private int bufferEnd;
    
        
    public RecentCounter() {
        buffer = new int[MAX_BUFFER_SIZE];
        bufferStart = bufferEnd = 0;
    }
    
    public int ping(int t) {
        buffer[bufferEnd++] = t;
        bufferEnd %= (MAX_BUFFER_SIZE);
        
        while (buffer[bufferStart] < t - MAX_INTERVAL) bufferStart = (bufferStart + 1) % MAX_BUFFER_SIZE;
        
        if (bufferEnd > bufferStart) return bufferEnd - bufferStart;
        
        return MAX_BUFFER_SIZE - (bufferStart - bufferEnd);
        
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */
__________________________________________________________________________________________________
sample 61408 kb submission
class RecentCounter {

    private int[] history = new int[10_001];
    private int start = -1;
    private int end = -1;

    public RecentCounter() {

    }

    public int ping(int t) {
        //System.out.println(t);
        if (start == -1) {
            start = 0;
            end = 0;
            history[start] = t;
            return 1;
        }

        end++;
        if (end >= 10_001) {
            end -= 10_001;
        }
        //System.out.println("end " + end);
        history[end] = t;

        while (t - history[start] > 3000) {
            start++;
            if (start >= 10_001) {
                start -= 10_001;
            }
        }

        //System.out.println("start " + start);

        return end - start + 1;
    }
}
__________________________________________________________________________________________________
