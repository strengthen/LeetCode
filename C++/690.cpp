__________________________________________________________________________________________________
sample 28 ms submission
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int calculate(unordered_map<int, Employee*>& emp_list, int id) {
        auto emp = emp_list[id];
        int imp = emp->importance;
        for(int x: emp->subordinates) {
            imp += calculate(emp_list, x);
        }
        
        return imp;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        if(employees.empty())
            return 0;
        
        unordered_map<int, Employee*> emp_list;
        transform(employees.begin(), employees.end(), inserter(emp_list, emp_list.end()), [](auto& a){return make_pair(a->id, a);});
        
        return calculate(emp_list, id);
    }
};


static auto s = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;   
}();
__________________________________________________________________________________________________
sample 14112 kb submission
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int get(vector<Employee*>& emp, int id) {
        int res = 0;
        int index = -1;
        for (int i = 0; i < emp.size(); i++) {
            if (emp[i]->id == id) {
                index = i;
                res = emp[i]->importance;
                break;
            }
        }
        for (int i = 0; i < emp[index]->subordinates.size(); i++) {
            int subid = emp[index]->subordinates[i];
            res += get(emp, subid);
        }
        return res;
    }
    int getImportance(vector<Employee*>& employees, int id) {
        return get(employees, id);
    }
};
__________________________________________________________________________________________________
