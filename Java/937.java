__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String[] reorderLogFiles(String[] logs) {
        List<String> orderedLogs = new ArrayList<>();
        List<String> noIdentifierLetterLogs = new ArrayList<>();
        int letterLogCount = 0;

        for(int i = 0; i < logs.length; i++){
            int j = logs[i].indexOf(' ');
            if(Character.isDigit(logs[i].charAt(j + 1))) {
                orderedLogs.add(logs[i]);
                continue;
            }
            
            String next = logs[i].substring(j + 1);
            int index = 0;
			// compare no identifier logs
            while((index < letterLogCount) && (next.compareTo(noIdentifierLetterLogs.get(index)) > 0)){
                ++index;
            }
            // if no identifier logs are equal, compare using full log string
            if(index < letterLogCount && next.compareTo(noIdentifierLetterLogs.get(index)) == 0){
                if(logs[i].compareTo(orderedLogs.get(index)) > 0)
                    ++index;
            }
            orderedLogs.add(index, logs[i]);
            noIdentifierLetterLogs.add(index, next);
            ++letterLogCount;
        }
        return orderedLogs.toArray(new String[orderedLogs.size()]);
    }
}
__________________________________________________________________________________________________
sample 35740 kb submission
class Solution {
    public String[] reorderLogFiles(String[] logs) {
        Arrays.sort(logs, (a,b)->{
            int index1 = a.indexOf(" ");
            int index2 = b.indexOf(" ");
            char c1 = a.charAt(index1+1);
            char c2 = b.charAt(index2+1);
            if (isLetter(c1) && isLetter(c2)) {
                String sub1 = a.substring(index1+1);
                String sub2 = b.substring(index2+1);
                if (!sub1.equals(sub2))
                    return sub1.compareTo(sub2);
                return a.compareTo(b);
            } else if (!isLetter(c1) && isLetter(c2)) {
                return 1;
            } else if (isLetter(c1) && !isLetter(c2)) {
                return -1;
            } else {
                return 0;
            }
        });
        return logs;
    }
    
    private boolean isLetter(char c) {
        if (c >= 'a' && c <= 'z')
            return true;
        return false;
    }
}
__________________________________________________________________________________________________
