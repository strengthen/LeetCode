__________________________________________________________________________________________________
class Solution {
    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
    for(int i = 0; i < group.length; i++)
        if(group[i] == -1)
            group[i] = m++; // assign none-group elements a group

    int[] inG = new int[m]; // indegree of groups
    int[] inI = new int[n]; // indegree of items
    ArrayList<Integer>[] graphI = new ArrayList[n]; // graph of groups: before group -> after groups
    ArrayList<Integer>[] graphG = new ArrayList[m]; // graph of items: before item -> after items
    ArrayList<Integer>[] g2i = new ArrayList[m]; // group index -> item indexes
    for(int i = 0; i < m; i++) g2i[i] = new ArrayList<>();
    for(int i = 0; i < n; i++) graphI[i] = new ArrayList<>();
    for(int i = 0; i < m; i++) graphG[i] = new ArrayList<>();

    for(int i = 0; i < group.length; i++) g2i[group[i]].add(i);
    for(int i = 0; i < beforeItems.size(); i++) {
        List<Integer> l = beforeItems.get(i);
        for(int b : l) {
            if(group[i] != group[b]) { // order between differnt groups
                graphG[group[b]].add(group[i]);
                inG[group[i]]++;
            } else { // order between items within a group
                inI[i]++;
                graphI[b].add(i);
            }
        }
    }
    // Level1: the code below is a topological sort on the groups
    PriorityQueue<Integer> q = new PriorityQueue<>();
    for(int i = 0; i < m; i++) {
        if(inG[i] == 0) q.offer(i);
    }
    ArrayList<ArrayList<Integer>> orderG = new ArrayList<>();
    while(!q.isEmpty()) {
        int b = q.poll(); // current group with indgree equals 0


        // Level 2: the code below is a topological sort on items within a group
        ArrayList<Integer> temp = new ArrayList<>();
        PriorityQueue<Integer> iq = new PriorityQueue<>();
        for(int i : g2i[b]) {
            if(inI[i] == 0) iq.offer(i);
        }
        while(!iq.isEmpty()) {
            int ib = iq.poll();
            temp.add(ib);
            for(int ia : graphI[ib]) {
                inI[ia]--;
                if(inI[ia] == 0) {
                    iq.offer(ia);
                }
            }
        }
        if(temp.size() != g2i[b].size()) return new int[]{}; // invalid result
        orderG.add(temp); // add the sorted group items into result
        // END inner sort


        for(int after : graphG[b]) { // add new groups with indgree equals 0 into the queue
            inG[after]--;
            if(inG[after] == 0) {
                q.offer(after);
            }
        }
    }
    if(orderG.size() != m) return new int[] {};
    // END outer sort

    int[] result = new int[n];
    int cnt = 0;
    for(ArrayList<Integer> l : orderG) {
        for(int i : l) result[cnt++] = i;
    }
    return result;
}
}
__________________________________________________________________________________________________
class Solution {
    
    
    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
        int[] res = new int[n];
        int index=0;
        Map<Integer, Set<Integer>> groupItems = new HashMap();
        for(int i=0; i<m;i++) groupItems.put(i, new HashSet<Integer>());
        for(int i=0; i<n; i++) {
            if(group[i]>-1) {
                groupItems.get(group[i]).add(i);
            }
        }
        int[] groupInterCount= new int[m];
        // int[] groupInnerCount= new int[m];
        
        int[] itemInCount = new int[n];
        Queue<Integer> freeGroup = new LinkedList();
        Queue<Integer> freeItem = new LinkedList();
        List<List<Integer>> afterItem = new ArrayList();
        for(int i=0;i<n;i++) afterItem.add(new ArrayList<Integer>());
        
        for(int i=0; i<n; i++){
            List<Integer> list = beforeItems.get(i);
            for(int j: list) {
                itemInCount[i]++;
                 List<Integer> l = afterItem.get(j);
                    l.add(i);
                if(group[i]!=group[j]&&group[i]!=-1) {
                    groupInterCount[group[i]]++;
                    
                   
                }
            }
        }
        
        for(int i=0; i<n; i++) if(group[i]==-1&&itemInCount[i]==0) freeItem.offer(i);
        for(int i=0; i<m;i++) if(groupInterCount[i]==0) freeGroup.offer(i);
        
        while(freeItem.size()>0||freeGroup.size()>0){
            while(freeItem.size()>0) {
                int item = freeItem.poll();
                List<Integer> after = afterItem.get(item);
                res[index++]=item;
                for(int i: after) {
                    itemInCount[i]--;
                    if(group[i]==-1) {
                        if(itemInCount[i]==0) {
                            freeItem.offer(i);
                        }
                    } else {
                        if(--groupInterCount[group[i]]==0) freeGroup.offer(group[i]);
                    }
                }
            }
            while(freeGroup.size()>0) {
                int g=freeGroup.poll();
                Set<Integer> items=groupItems.get(g);
				Queue<Integer> free = new LinkedList();
				for(int i: items) if(itemInCount[i]==0) free.offer(i);
				int size=items.size();
				while(!free.isEmpty()) {
					size--;
					int item=free.poll();
					List<Integer> after = afterItem.get(item);
					res[index++]=item;
            
					for(int i: after) {
						itemInCount[i]--;
						if(group[i]==-1) {
							if(itemInCount[i]==0) {
								freeItem.offer(i);
							}
						} else if(group[i]==group[item]) {
                        if(itemInCount[i]==0) free.offer(i);
                    } 
					else {
                        if(--groupInterCount[group[i]]==0) freeGroup.offer(group[i]);
                    }
            }
        }
            if(size>0) return new int[0];
            }
        }
        
        return index==n?res:new int[0];
    }
    
}
__________________________________________________________________________________________________
