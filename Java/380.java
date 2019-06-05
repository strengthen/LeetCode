__________________________________________________________________________________________________
sample 50 ms submission
class RandomizedSet {
    private HashMap<Integer, Integer> map;
    private ArrayList<Integer> list;
    java.util.Random rand = new java.util.Random();
    /** Initialize your data structure here. */
    public RandomizedSet() {
        map = new HashMap<>();
        list = new ArrayList<>();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if(map.containsKey(val)) return false;
        else{
            map.put(val, list.size());
            list.add(val);
        }
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if(!map.containsKey(val)) return false;
        else{
            int index = map.get(val);
            if(index < list.size() - 1){
                int last = list.get(list.size() - 1);
                list.set(index,last);
                map.put(last,index);
            }
            map.remove(val);
            list.remove(list.size() - 1);
        }
        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        return list.get(rand.nextInt(list.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
__________________________________________________________________________________________________
sample 40276 kb submission
class RandomizedSet {
    
    Map<Integer, Integer> map;
    List<Integer> list;

    /** Initialize your data structure here. */
    public RandomizedSet() {
        map = new HashMap<>();
        list = new ArrayList<>();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        boolean isPresent = map.containsKey(val);
        if(!isPresent) {
            list.add(val);
            map.put(val, list.size()-1);
        }
        
        return !isPresent;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        boolean isPresent = map.containsKey(val);
        if(isPresent) {
            int index = map.get(val);
            if(index == list.size()-1) {
                list.remove(index);
            }else {
                // get the value of swapped item so that we can update its index in the map
                // so that later on if this item gets deleted , index will be correct.
                int swapItem = list.get(list.size()-1);
                Collections.swap(list, index, list.size()-1);
                list.remove(list.size()-1);
                map.put(swapItem, index);
            }
            
            map.remove(val);
        }
        
        return isPresent;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
       int max = list.size();
        int min = 0;
        int ind = (int)(Math.random() * (max - min) + min);
        return list.get(ind);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
__________________________________________________________________________________________________
