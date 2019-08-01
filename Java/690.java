__________________________________________________________________________________________________
sample 4 ms submission
/*
// Employee info
class Employee {
    // It's the unique id of each node;
    // unique id of this employee
    public int id;
    // the importance value of this employee
    public int importance;
    // the id of direct subordinates
    public List<Integer> subordinates;
};
*/
class Solution {
    int res = 0;
    Employee[] emp = new Employee[20001];
    public int getImportance(List<Employee> employees, int id) {
       for(Employee employee : employees)  emp[employee.id] = employee;
       calculateImportance(id);
        return res;
    }
    
    private void calculateImportance(int id) {
        Employee employee = emp[id];
        res += employee.importance;
        for(Integer sub : employee.subordinates) calculateImportance(sub);
    }
}
__________________________________________________________________________________________________
sample 42908 kb submission
/*
// Employee info
class Employee {
    // It's the unique id of each node;
    // unique id of this employee
    public int id;
    // the importance value of this employee
    public int importance;
    // the id of direct subordinates
    public List<Integer> subordinates;
};
*/
class Solution {
    Map<Integer, Employee> emap = new HashMap<>();
    public int getImportance(List<Employee> employees, int id) {
        for (Employee e : employees) {
            emap.put(e.id, e);  
        }
        return dfs(id);
    }
    
    private int dfs(int id)  {
        Employee emp = emap.get(id);
        int ans = emp.importance;
        for (int subId: emp.subordinates) {
            ans += dfs(subId);
        }
        return ans;
    }
}
__________________________________________________________________________________________________
