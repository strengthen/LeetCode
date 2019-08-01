__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int leastInterval(char[] tasks, int n) {
        int max=0,number=0;
        int[] cnt=new int[26];
        for(char c:tasks)
            cnt[c-'A']++;
        for(int i=0;i<26;i++){
            max=Math.max(max,cnt[i]);
        }
        
        for(int i=0;i<26;i++){
            if(cnt[i]==max)
                number++;
        }
        
        return Math.max(tasks.length,(n+1)*(max-1)+number);
    }
}
__________________________________________________________________________________________________
sample 35628 kb submission
class Solution {
    public int leastInterval(char[] tasks, int n) {
        int cycles = 0;
		HashMap<Character, Integer> map = new HashMap<>();
		for(Character task : tasks) {
			if(map.containsKey(task)) {
				int count = map.get(task);
				count++;
				map.put(task, count);
			} else {
				map.put(task, 1);
			}
		}
		PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>((a,b) -> b-a);
		maxHeap.addAll(map.values());
		while(!maxHeap.isEmpty()) {
			List<Integer> temp = new ArrayList<Integer>();
			for(int i = 0; i < n + 1; i++) {
				if(!maxHeap.isEmpty()) {
					int task = maxHeap.poll();
					temp.add(task);
				}
			}
			for(int i : temp) {
				if(--i > 0) {
					//We still have more items to process
					maxHeap.add(i);
				}
			}
			if(maxHeap.isEmpty()) {
				cycles += temp.size();
			} else {
				cycles += n + 1;
			}
		}		
		return cycles;
    }      
}
__________________________________________________________________________________________________
