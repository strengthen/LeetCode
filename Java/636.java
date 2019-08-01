__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        int[] res = new int[n];
        
        int start = 0;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0, len = logs.size(); i < len; i++) {
            Log log = new Log(logs.get(i));

            if (log.isStart) {
                if (!stack.isEmpty()) {
                    res[stack.peek()] += log.time - start;
                }
                stack.push(log.id);
                start = log.time;
            } else {
                res[stack.pop()] += log.time - start + 1;
                start = log.time + 1;
            }
        }
        
        return res;
    }
}

class Log {
    int id;
    int time;
    boolean isStart;
    
    Log(String logStr) {
        int i = 0, len = logStr.length();
        id = 0;
        while (logStr.charAt(i) != ':') {
            id = id * 10 + (logStr.charAt(i++) - '0');
        }
        
        if (logStr.charAt(++i) == 's') {
            isStart = true;
            i += 6;
        } else {
            isStart = false;
            i += 4;
        }
        
        time = 0;
        while (i < len) {
            time = time * 10 + (logStr.charAt(i++) - '0');
        }
    }
}
__________________________________________________________________________________________________
sample 37004 kb submission
class Solution {
    public int[] exclusiveTime(int n, List<String> l) {
        List<Log> logs = l.stream().map(Log::new).collect(Collectors.toList());
        Stack<Integer> frames = new Stack<>();
        int curId = -1;
        int curStart = -1;
        int[] results = new int[n];
        for (Log log : logs) {
            if (log.isStart()) {
                if (curId != -1) {
                    results[curId] += log.time() - curStart;
                    frames.push(curId);
                }
                curId = log.id();
                curStart = log.time();
            }
            else {
                results[curId] += log.time() - curStart + 1;
                if (!frames.isEmpty()) {
                    curId = frames.pop();
                    curStart = log.time() + 1;
                }
                else {
                    curId = -1;
                    curStart = -1;
                }
            }
        }
        return results;
    }
    
    private class Log {
        private int id;
        private boolean isStart;
        private int time;
        
        public Log(String log) {
            String[] tokens = log.split(":");
            id = Integer.valueOf(tokens[0]);
            isStart = tokens[1].equals("start");
            time = Integer.valueOf(tokens[2]);
        }
        
        public int id() {
            return id;
        }
        
        public int time() {
            return time;
        }
        
        boolean isStart() {
            return isStart;
        }
        
        boolean isEnd() {
            return !isStart();
        }
    }
}
__________________________________________________________________________________________________
