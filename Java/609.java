__________________________________________________________________________________________________
sample 13 ms submission
class Solution {
       public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> map = new HashMap<>();
        List<List<String>> ans = new ArrayList<>();

        for (int n = 0; n < paths.length; n++) {
            char[] sa = paths[n].toCharArray();
            int b = 0;
            int i = 0;
            while (sa[i] != ' ') {
                i++;
            }
            String path = paths[n].substring(b, i);
            b = i + 1;
            while (i < sa.length) {
                while (sa[i] != ' ') {
                    i++;
                }
                b = i + 1;
                while (sa[i] != '(') {
                    i++;
                }
                String fileName = paths[n].substring(b, i);
                b = i + 1;
                while (sa[i] != ')') {
                    i++;
                }
                String content = paths[n].substring(b, i);
                String fullFileName = path + "/" + fileName;
                List<String> pli = map.get(content);
                if (pli == null) {
                    pli = new ArrayList<>();
                    map.put(content, pli);
                }
                pli.add(fullFileName);
                i++;
            }
        }
        for(List<String> pli : map.values()) {
            if(pli.size() > 1) {
                ans.add(pli);
            }
        }
        return ans;
    }
}
__________________________________________________________________________________________________
sample 50880 kb submission
class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> contentFiles =new HashMap<>();
        for (String p : paths) {
            String[] ps = p.split(" ");
            for (int i = 1; i < ps.length; i++) {
                String file = ps[i];
                String fileName = file.substring(0, file.indexOf("("));
                String content = file.substring(file.indexOf("(") + 1, file.length() -1);
                String newPath = ps[0] + "/" + fileName;
                if (contentFiles.containsKey(content)) {
                    contentFiles.get(content).add(newPath);
                } else {
                    List<String> newPaths = new ArrayList<>();
                    newPaths.add(newPath);
                    contentFiles.put(content, newPaths);
                }
            }
        }
        return contentFiles.values().stream().filter(l -> l.size() > 1).collect(Collectors.toList());
    }
}
__________________________________________________________________________________________________
