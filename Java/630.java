__________________________________________________________________________________________________
sample 33 ms submission
class Solution {
    public int scheduleCourse(int[][] courses) {
        int n = courses.length;
        long[] deadlineDuration = new long[n];
        n = 0;
        for (int[] course : courses) {
            deadlineDuration[n++] = course[0] | (long)course[1] << 32;
        }
        Arrays.sort(deadlineDuration);
        int curLastDay = 0;
        Queue<Integer> duration = new PriorityQueue<>();
        int curLen, curDeadline;

        for (long course : deadlineDuration) {
            curLen = (int)course;
            curDeadline = (int)(course >> 32);
            curLastDay += curLen;
            duration.offer(-curLen);
            if (curDeadline < curLastDay) {
                curLastDay += duration.poll();
            }
        }

        return duration.size();
    }
}
__________________________________________________________________________________________________
sample 45244 kb submission
class Solution {
    public int scheduleCourse(int[][] courses) {
         Arrays.sort(courses, (a, b) -> a[1] - b[1]);
         PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a); // max heap
         int time = 0;
         for(int[] course : courses){
             int duration = course[0];
             int deadline = course[1];
             if(time + duration <= deadline){
                 pq.offer(duration);
                 time += duration;
             }else if(!pq.isEmpty() && pq.peek() > duration){
                 time -= pq.poll();
                 time += duration;
                 pq.offer(duration);
             }
         }
         return pq.size();
    }
}
__________________________________________________________________________________________________
