__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean isPossible(int[] nums) {
        int pre = Integer.MIN_VALUE, p1 = 0, p2 = 0, p3 = 0;
        int cur = 0, cnt = 0, c1 = 0, c2 = 0, c3 = 0;

        for (int i = 0; i < nums.length; pre = cur, p1 = c1, p2 = c2, p3 = c3) {
            for (cur = nums[i], cnt = 0; i < nums.length && cur == nums[i]; cnt++, i++);

            if (cur != pre + 1) {
                if (p1 != 0 || p2 != 0) return false;
                c1 = cnt; c2 = 0; c3 = 0;

            } else {
                if (cnt < p1 + p2) return false;
                c1 = Math.max(0, cnt - (p1 + p2 + p3));
                c2 = p1;
                c3 = p2 + Math.min(p3, cnt - (p1 + p2));
            }
        }

        return (p1 == 0 && p2 == 0);
    }
}
__________________________________________________________________________________________________
sample 37692 kb submission
class Solution {
    public boolean isPossible(int[] nums) {
        PriorityQueue<interval> queue = new PriorityQueue<>((a, b) -> (a.end == b.end ? a.len - b.len : a.end - b.end));
        for (int num : nums) {
            while (!queue.isEmpty() && queue.peek().end + 1 < num) {
                if (queue.poll().len < 3) return false;
            }
            if (queue.isEmpty() || queue.peek().end == num) queue.offer(new interval(num, num));
            else { //num == end + 1
                queue.add(new interval(queue.poll().start, num));
            }
        }
        while (!queue.isEmpty()) {
            if (queue.poll().len < 3) return false;
        }
        return true;
    }
    
    class interval {
        int start, end, len;
        public interval(int start, int end) {
            this.start = start;
            this.end = end;
            this.len = end - start + 1;
        }
    }
}
__________________________________________________________________________________________________
