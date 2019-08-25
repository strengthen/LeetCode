__________________________________________________________________________________________________
sample 42 ms submission
class Solution {
    public List<String> invalidTransactions(String[] transactions) {
        Set<String> result = new HashSet<>();
        Map<String, List<Transaction>> map = new HashMap<>();
        for (String s : transactions) {
            Transaction t = new Transaction(s);
            map.computeIfAbsent(t.name, (k) -> new ArrayList<>()).add(t);
        }
        for (List<Transaction> l : map.values()) {
            Collections.sort(l);
            int i = 0;
            while (i < l.size()) {
                Transaction t = l.get(i);
                int j = i + 1;
                while (j < l.size()) {
                    Transaction other = l.get(j);
                    if (other.time - t.time > 60) {
                        break;
                    }
                    if (!t.city.equals(other.city)) {
                        result.add(t.s);
                        break;
                    }
                    j++;
                }
                j = i - 1;
                while (j >= 0) {
                    Transaction other = l.get(j);
                    if (t.time - other.time > 60) {
                        break;
                    }
                    if (!t.city.equals(other.city)) {
                        result.add(t.s);
                        break;
                    }
                    j--;
                }
                if (t.amount > 1000) {
                    result.add(t.s);
                }
                i++;
            }
        }
        return new ArrayList<>(result);
    }
    
    private class Transaction implements Comparable<Transaction> {
        String name;
        int time;
        int amount;
        String city;
        String s;
        
        Transaction(String t) {
            String[] words = t.split(",");
            name = words[0];
            time = Integer.parseInt(words[1]);
            amount = Integer.parseInt(words[2]);
            city = words[3];
            s = t;
        }
        
        @Override
        public int compareTo(Transaction o) {
            return time - o.time;
        }
        
        @Override
        public String toString() {
            return s;
        }
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
