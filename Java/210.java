__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List[] course=new List[numCourses];
        int[] map=new int[numCourses];
        List<Integer> ans = new ArrayList<Integer>();
        
        for(int i=0;i<numCourses;i++){
            course[i]=new ArrayList<Integer>();
        }
       
        for(int i=0;i<prerequisites.length;i++){
            course[prerequisites[i][0]].add(prerequisites[i][1]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(dfs(course,i,ans,map)==false) {
                return new int[0]; 
            }
        }
       
        int[] an = new int[ans.size()];
        for(int i = 0; i < ans.size(); i++){
            an[i] = ans.get(i);
        }
        
        return an;
    }
    public boolean dfs(List[] course,int req,List<Integer> ans,int[] map) {
        //post-order traverse
        if(map[req] == 0) {
            map[req] = 1;
            for(int i=0;i<course[req].size();i++) {
                if(dfs(course,(int)course[req].get(i),ans,map)==false) {
                   return false; 
                }
            }
            
            map[req]=2;
        } else if(map[req]==1) {
            return false;
        } else if(map[req]==2) {
            return true;
        }
        ans.add(req);
        return true;
    }
}
__________________________________________________________________________________________________
sample 36820 kb submission
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
         int[] indegree = new int[numCourses];
        for(int[] pre:prerequisites){
            indegree[pre[0]]++;
        }
        int count=0;
        int[] res = new int[numCourses];
        Queue<Integer> q = new LinkedList<>();
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.offer(i);
            }
        }
        while(!q.isEmpty()){
            int cur = q.poll();
            res[count++]=cur;
            for(int[] pre:prerequisites){
                if(pre[1]==cur){
                    --indegree[pre[0]];
                    if(indegree[pre[0]]==0){
                        q.offer(pre[0]);}
                }
            }
        }
        return count==numCourses?res:new int[0];
    }
}
__________________________________________________________________________________________________
