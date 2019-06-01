__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    HashMap<String, PriorityQueue<String>> flights;
    LinkedList<String> path;
    public List<String> findItinerary(String[][] tickets) {
        flights = new HashMap<>();
        path = new LinkedList<>();
        for (String[] ticket : tickets) {
            if (!flights.containsKey(ticket[0])) {
                flights.put(ticket[0], new PriorityQueue<String>());
                flights.get(ticket[0]).add(ticket[1]);
            }else {
                flights.get(ticket[0]).add(ticket[1]);
            }
        }
        dfs("JFK");
        return path;
    }
    
    public void dfs(String from) {
        PriorityQueue<String> from_to = flights.get(from);
        while (from_to != null && !from_to.isEmpty()) {
            dfs(from_to.poll());
        }
        path.addFirst(from);
    }
}
__________________________________________________________________________________________________
sample 35960 kb submission
class Solution {
    Map<String, Map<String, Integer>> graph = new HashMap<>();
    int totalTickets;

    private static class Edge {
        String from;
        String to;

        Edge(String from, String to) {
            this.from = from;
            this.to = to;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Edge edge = (Edge) o;
            return Objects.equals(from, edge.from) &&
                    Objects.equals(to, edge.to);
        }

        @Override
        public int hashCode() {
            return Objects.hash(from, to);
        }
    }

    public List<String> findItinerary(String[][] tickets) {

        totalTickets = tickets.length;
        for (String[] flight : tickets) {
            String from = flight[0];
            String to = flight[1];

            graph.computeIfAbsent(from, k -> new TreeMap<>());
            graph.get(from).compute(to, (k, v) -> v == null ? 1 : v + 1);
        }

        List<String> result = new ArrayList<>();
        Map<Edge, Integer> visited = new HashMap<>();
        findPath("JFK", visited, 0, result);
        result.add("JFK");

        Collections.reverse(result);
        return result;
    }

    private boolean findPath(String current, Map<Edge, Integer> visited, int visitedTotal, List<String> result) {
        Map<String, Integer> probablyNext = graph.get(current);

        if (probablyNext != null) {
            for (String next : probablyNext.keySet()) {
                Edge edge = new Edge(current, next);
                if (visited.getOrDefault(edge, 0) < probablyNext.get(next)) {
                    visited.compute(edge, (k, v) -> v == null ? 1 : v + 1);
                    if (visitedTotal + 1 == totalTickets || findPath(next, visited, visitedTotal + 1, result)) {
                        result.add(next);
                        return true;
                    }
                    visited.remove(edge);
                }
            }
        }
        return false;
    }
}
__________________________________________________________________________________________________
