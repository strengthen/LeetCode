__________________________________________________________________________________________________
class FileSystem {
    Map<String, Integer> map;

    public FileSystem() {
        map = new HashMap<>();
        map.put("", 0);
    }
    
    public boolean create(String path, int value) {
        if(map.containsKey(path)){
            return false;
        }
        
        int pos = path.lastIndexOf("/");
        String par = path.substring(0, pos);
        if(!map.containsKey(par)){
            return false;
        }
        map.put(path, value);
        return true;
    }
    
    public int get(String path) {
        return map.containsKey(path) ?  map.get(path) : -1;
    }
}	
__________________________________________________________________________________________________

__________________________________________________________________________________________________
