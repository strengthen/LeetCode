__________________________________________________________________________________________________
Runtime: 86 ms
Memory Usage: 89.7 MB
class SnapshotArray {

    private List<Map<Integer, Integer>> shot;
    private Map<Integer, Integer> diff;
    
    public SnapshotArray(int length) {
        shot  = new ArrayList<>(length);
        diff  = new HashMap<>(length);
    }
    
    public void set(int index, int val) {
        diff.put(index, val);
    }
    
    public int snap() {
        shot.add(diff);
        diff = new HashMap<>();
        return shot.size() - 1;
    }
    
    public int get(int index, int snap_id) {
        for (int i = snap_id; i >= 0; --i)
             if (shot.get(i).containsKey(index))   
                 return shot.get(i).get(index); 
        return 0;
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray obj = new SnapshotArray(length);
 * obj.set(index,val);
 * int param_2 = obj.snap();
 * int param_3 = obj.get(index,snap_id);
 */
__________________________________________________________________________________________________

__________________________________________________________________________________________________
