__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        if(equations==null || equations.size()==0) return new double [] {};
        
        Map<String, String>root=new HashMap<>();
        Map<String, Double>map=new HashMap<>();
        
        for (int i=0;i<equations.size();i++){
            String x1=equations.get(i).get(0), x2=equations.get(i).get(1);
            root.putIfAbsent(x1, x1);
            root.putIfAbsent(x2, x2);
            map.putIfAbsent(x1, 1.0);
            map.putIfAbsent(x2, 1.0);
            
            String r1=find(root, x1);
            String r2=find(root, x2);
            root.put(r2, r1);
            map.put(r2, map.get(x1)*values[i]/map.get(x2));
        }
        
        double[] res=new double[queries.size()];
        for (int i=0;i<queries.size();i++){
            res[i]=-1.0;
            String x1=queries.get(i).get(0), x2=queries.get(i).get(1);
            if (!root.containsKey(x1) || !root.containsKey(x2)) continue;
            String r1=find(root, x1);
            String r2=find(root, x2);
            if (r1.equals(r2))
                res[i]=get(root, map, x2) / get(root, map, x1);
        }
        return res;
        
    }
    
    private String find(Map<String, String>root, String var){
        if (root.get(var).equals(var)) return var;
        return find(root, root.get(var));
    }
    
    private double get(Map<String, String>root, Map<String, Double>map, String var){
        String r=root.get(var);
        double result=map.get(var);
        
        if (r.equals(var)) return result;
        return result*get(root, map, r);
    }
}
__________________________________________________________________________________________________
sample 33864 kb submission
class Solution {
    public double[] calcEquation(String[][] equations, double[] values, String[][] queries) {
        double[] ret= new double[queries.length];
        
        Map<String, List<Node> > graph= new HashMap<>();
        
        
        for(int i=0;i<equations.length;i++){
            graph.computeIfAbsent(equations[i][0],k-> new ArrayList<>()).add(new Node(values[i],equations[i][1]));
            graph.computeIfAbsent(equations[i][1],k-> new ArrayList<>()).add(new Node(1/values[i],equations[i][0]));
        }
       // System.out.println(graph);
        for(int i=0;i<queries.length;i++){
            String s=queries[i][0];
            String d=queries[i][1];
            if(graph.containsKey(s)){
            double[] calVal= new double[]{-1};
            calDist(s,d,graph,calVal,1.0,null);
            // System.out.println(ret[i]);
            ret[i]=calVal[0];
            }else{
                ret[i]=-1.0;
            }
             
        }
        
        return ret;
    }
    
    public void calDist(String s, String d,Map<String, List<Node> > graph, double[] calVal,double temp, String parent ){
        if(s.equals(d)){
            calVal[0]=temp;
           return; 
        } 
        
        List<Node> neig= graph.get(s);
        if(neig!=null){
            for(int i=0;i<neig.size();i++){
                if(!neig.get(i).c.equals(parent))
                calDist(neig.get(i).c,d,graph,calVal,temp*neig.get(i).weight,s);
            }
        }
    }
}

class Node{
    
    Double weight;
    String c;
    
    Node(Double weight,String c){
        this.weight=weight;
        this.c=c;
    }
}
__________________________________________________________________________________________________
