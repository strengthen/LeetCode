__________________________________________________________________________________________________
class DinnerPlates {
    int capacity;
    List<Stack<Integer>> stacks;
    TreeSet<Integer> pushable;
    TreeSet<Integer> popable;
    
    
    public DinnerPlates(int cap) {
        capacity = cap;
        stacks = new ArrayList<>();
        pushable = new TreeSet<>();
        popable = new TreeSet<>();
    }
    
    public void push(int val) {
        if (pushable.isEmpty()) {
            pushable.add(stacks.size());
            stacks.add(new Stack<>());
        }
        int index = pushable.first();
        Stack<Integer> stack = stacks.get(index);
        stack.push(val);
        popable.add(index);
        if (stack.size() == capacity) {
            pushable.remove(index);
        }
    }
    
    public int pop() {
        if (popable.size() == 0) {
            return -1;
        }
        int index = popable.last();
        return popAtStack(index);
    }
    
    public int popAtStack(int index) {
        if (!popable.contains(index)) {
            return -1;
        }
        Stack<Integer> stack = stacks.get(index);
        int res = stack.pop();
        pushable.add(index);
        if (stack.size() == 0) {
            popable.remove(index);
        }
        return res;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
