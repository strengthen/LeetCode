__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int minMutation(String start, String end, String[] bank) {
        HashSet<String> set = new HashSet<>();
        Queue<String>queue = new LinkedList<>();
        queue.offer(start);
        set.add(start);
        int count = 0;
        while(!queue.isEmpty()) {
            count++;
            for (int i = 0; i < queue.size(); i++) {
                String s = queue.poll();
                for (String b: bank) {
                    if (!set.contains(b) && differByOne(s, b)) {
                        if (b.equals(end)) {
                            return count;
                        }
                        queue.offer(b);
                        set.add(b);
                    }
                }
            }
        }
        return -1;
    }
    
    boolean differByOne(String s, String b) {
        boolean found = false;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != b.charAt(i)) {
                if (found) return false;
                else found = true;
            }
        }
        return found;
    }
}
__________________________________________________________________________________________________
sample 33152 kb submission
    class Solution {
        class State {
            String current;
            Set<String> prev;
            int mutationLength = 0;

            public State(String current, Set<String> prev, int mutationLength) {
                this.current = current;
                this.prev = new HashSet<>(prev);
                this.mutationLength = mutationLength;
            }
        }

        private int strDiff(String s, String t) {
            int diff = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) != t.charAt(i)) {
                    diff++;
                }
            }
            return diff;
        }

        public int minMutation(String start, String end, String[] bank) {
            if (start == null || end == null || bank == null) {
                return -1;
            }
            if (start.length() != end.length()) {
                return -1;
            }

            Queue<State> queue = new PriorityQueue<>(Comparator.comparingInt(c -> c.mutationLength));
            State init = new State(start, new HashSet<>(), 0);
            queue.add(init);

            while (!queue.isEmpty()) {
                State cur = queue.remove();

                if (cur.current.equals(end)) {
                    return cur.mutationLength;
                }
                for (String s : bank) {
                    if (cur.prev.contains(s)) {
                        continue;
                    }

                    int diff = strDiff(cur.current, s);
                    if (diff != 1) {
                        continue;
                    }
                    State next = new State(s, cur.prev, cur.mutationLength + diff);
                    next.prev.add(cur.current);

                    queue.add(next);
                }
            }
            return -1;
        }
    }
__________________________________________________________________________________________________
