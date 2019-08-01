__________________________________________________________________________________________________
sample 4 ms submission
// HashMap 解法很巧妙
// 逻辑分析是关键：culminated sum Method
// Code II is 100%
class Solution {
    /*
    // Code I
    public int leastBricks(List<List<Integer>> wall) {
        if(wall.size() == 0) return 0;
        int count = 0;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(List<Integer> list : wall)
        {
            int length = 0;
            for(int i = 0; i < list.size() - 1; i++)
            {
                length = length + list.get(i);
                map.put(length, map.getOrDefault(length, 0) + 1);
                count = Math.max(count, map.get(length));
            }
        }
        
        return wall.size() - count;
    }
    */
    // Code II
    public int leastBricks(List<List<Integer>> wall) {
    int[] a = new int[65536];
        for(List<Integer> b: wall)
        {
            int sum = 0;
            for(int i = 0;i < b.size() - 1;i++)
            {
                sum += b.get(i);
                a[sum]++;
            }
        }
        int max = 0;
        for(int j = 0;j < a.length;j++)
            if(max < a[j])
                max = a[j];
        return wall.size()-max;
    }
}
__________________________________________________________________________________________________
sample 46772 kb submission
class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        PriorityQueue<List<Integer>> pq = new PriorityQueue<>((l1, l2) -> Integer.compare(l1.get(0), l2.get(0)));
        for (List<Integer> in : wall) {
            for (int i=1; i<in.size(); i++) {
                in.set(i, in.get(i) + in.get(i-1));
            }
            pq.offer(in);
        }
        
        int last = -1;
        int runlen = 0;
        int maxlen = 0;
        System.out.println(pq);
        while (!pq.isEmpty()) {
            List<Integer> list = pq.poll();
            int cur = list.remove(0);
            if (cur == last) {
                runlen++;
            } else {
                maxlen = Math.max(runlen, maxlen);
                runlen = 1;
                last = cur;
            }
            if (!list.isEmpty()) {
                pq.offer(list);
            }
        }
        return wall.size() - maxlen;
    }
}
__________________________________________________________________________________________________
