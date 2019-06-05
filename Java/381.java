__________________________________________________________________________________________________
sample 52 ms submission
class RandomizedCollection {
    private Map<Integer, List<Integer>> valueIndexMap;
    private int[] set;
    private int size = 0;

    /** Initialize your data structure here. */
    public RandomizedCollection() {
        valueIndexMap = new HashMap<>();
        set = new int[2];
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    public boolean insert(int val) {
        boolean isExist = valueIndexMap.containsKey(val);
        if (size == set.length) {
            resize(2 * set.length);
        }
        valueIndexMap.putIfAbsent(val, new ArrayList<>());
        valueIndexMap.get(val).add(size);
        set[size] = val;
        size++;
        return !isExist;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    public boolean remove(int val) {
        boolean isExist = valueIndexMap.containsKey(val);
        if (isExist) {
            int last = size - 1;
            int lastValue = set[last];
            List<Integer> list = valueIndexMap.get(val);
            int targetIndex = list.remove(list.size() - 1);
            if (list.size() == 0) {
                valueIndexMap.remove(val);
            }
            
            if (targetIndex != last) {
                List<Integer> lastList = valueIndexMap.get(lastValue);
                lastList.remove(lastList.size() - 1);
                lastList.add(0, targetIndex);
                set[targetIndex] = lastValue;
            } 
            set[last] = 0;
            size--;
            if (size > 0 && size == set.length/4) {
                resize(set.length/2);
            }
        }
        return isExist;
    }
    
    /** Get a random element from the collection. */
    public int getRandom() {
        Random rand = new Random();
        int n = rand.nextInt(size);
        return set[n];
    }
    
    private void resize(int capacity) {
        set = java.util.Arrays.copyOf(set, capacity);
    }
}
__________________________________________________________________________________________________
sample 40968 kb submission
class RandomizedCollection {

    Random rand;
    List<Integer> list;
    Map<Integer, Set<Integer>> map;
    public RandomizedCollection() {
        rand = new Random();
        list = new ArrayList();
        map = new HashMap();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    public boolean insert(int val) {
        boolean notContains = true;
        if(map.containsKey(val)) {
            map.get(val).add(list.size());
            list.add(val);
            notContains = !notContains;
        }else {
            
            map.computeIfAbsent(val, k->new LinkedHashSet());
            map.get(val).add(list.size());
            list.add(val);
        }
        return notContains;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    public boolean remove(int val) {
        if(!map.containsKey(val)) {
           return false; 
        }else {
        Set<Integer> indexes = map.get(val);
        int index = indexes.iterator().next();
        indexes.remove(index);
        if(indexes.size() == 0) {
            map.remove(val);
        }
            if(index!=list.size()-1){ 
            int lastVal = list.get(list.size()-1);
            Set<Integer> lastValIndexes = map.get(lastVal);
            list.set(index, lastVal);
            lastValIndexes.remove(list.size()-1);
            lastValIndexes.add(index);
                
            }
        }
        list.remove(list.size()-1);
        return true;
    }
    
    /** Get a random element from the collection. */
    public int getRandom() {
        return list.get(rand.nextInt(list.size()));
    }
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
__________________________________________________________________________________________________
