__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int n = rooms.size();
        boolean[] seen = new boolean[n];
        dfs(0, rooms, seen);
        for(boolean x : seen) {
            if(!x) {
                return false;
            }
        }
        return true;
    }
    
    private void dfs(int cur, List<List<Integer>> rooms, boolean[] seen) {
        seen[cur] = true;
        for(int next : rooms.get(cur)) {
            if(!seen[next]) {
                dfs(next, rooms, seen);
            }
        }
    }
}
__________________________________________________________________________________________________
sample 37104 kb submission
class Solution {
    Queue<Integer> roomToOpenQueue = new ArrayDeque<>();
    HashSet<Integer> visitedRooms = new HashSet<>();

    public boolean canVisitAllRooms(List<List<Integer>> rooms) {


        //pick up keys and add to key map
        List<Integer> keysInRoom = rooms.get(0);
        visitedRooms.add(0);

        roomToOpenQueue.addAll(keysInRoom);

        while (!roomToOpenQueue.isEmpty()) {
            visitRoom(roomToOpenQueue.remove(), rooms);
        }
        return  !(visitedRooms.size() < rooms.size());
     }

     public void visitRoom(Integer roomNumber, List<List<Integer>> rooms) {
        if (!visitedRooms.contains(roomNumber)) {
            System.out.print ("Visiting room " + roomNumber);
            visitedRooms.add(roomNumber);
            List<Integer> keysInRoom = rooms.get(roomNumber);
            
            for (Integer key: keysInRoom) {
                if (!visitedRooms.contains(key)) {
                    roomToOpenQueue.add(key);
                }
            }

        }
         roomToOpenQueue.remove(roomNumber);

     }
}
__________________________________________________________________________________________________
