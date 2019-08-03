__________________________________________________________________________________________________
sample 75 ms submission
class FreqStack {
        private Map<Integer, Integer> map;
        private List<LinkedList<Integer>> list;
        private int index;
        private int counter;
        public FreqStack() {
            this.map = new HashMap<>();
            this.list = new ArrayList<>();
            this.counter = 0;
            this.index = -1;
        }

        public void push(int x) {
            int count = map.getOrDefault(x, 0);
            if(count == list.size())
            {
                LinkedList<Integer> stack = new LinkedList<>();
                stack.addLast(x);
                list.add(stack);
            }
            else
            {
                LinkedList stack = list.get(count);
                stack.addLast(x);
            }
            index = index < count ? count : index;
            map.put(x, count+1);
        }

        public int pop() {
            LinkedList<Integer> indexList = list.get(index);
            int ans = indexList.pollLast();
            map.put(ans, index);
            if(indexList.size()==0)
            {
                index--;
            }
            return ans;
        }
    }

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
__________________________________________________________________________________________________
sample 54608 kb submission
class FreqStack {
    HashMap<Integer, Integer> freq = new HashMap<>();
    HashMap<Integer, Stack<Integer>> m = new HashMap<>();
    int maxfreq = 0;

    public void push(int x) {
        int f = freq.getOrDefault(x, 0) + 1;
        freq.put(x, f);
        maxfreq = Math.max(maxfreq, f);
        if (!m.containsKey(f)) m.put(f, new Stack<Integer>());
        m.get(f).add(x);
    }

    public int pop() {
        int x = m.get(maxfreq).pop();
        freq.put(x, maxfreq - 1);
        if (m.get(maxfreq).size() == 0) maxfreq--;
        return x;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
__________________________________________________________________________________________________
