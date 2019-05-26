__________________________________________________________________________________________________
class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {

       HashMap<Integer,Integer> count = new HashMap<>();
       for (int c : barcodes) {
           if(!count.containsKey(c)) {
               count.put(c,0);
           }
           count.put(c,count.get(c)+1);
       }

       PriorityQueue<Map.Entry<Integer,Integer>> priorityQueue = new PriorityQueue<>(
               (a,b) -> !Objects.equals(a.getValue(), b.getValue()) ? b.getValue() - a.getValue() : a.getKey() - b.getKey());

       priorityQueue.addAll(count.entrySet());

       int[] result = new int[barcodes.length];

       Queue<Map.Entry<Integer,Integer>> queue = new LinkedList<>();

       int i=0;
       while (!priorityQueue.isEmpty()) {

           Map.Entry<Integer, Integer> entry = priorityQueue.poll();
           entry.setValue(entry.getValue() - 1);
           queue.offer(entry);
           result[i]=entry.getKey();
           i++;

           if(queue.size()<2) {
               continue;
           }

           Map.Entry<Integer, Integer> front = queue.poll();

           if(front!=null && front.getValue()>0) {
               priorityQueue.offer(front);
           }

       }

       return result;
   }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
