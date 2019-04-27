__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int calPoints(vector<string>& ops) {
        std::stack<int> opS;
        int sum {0};
        for (const auto& op : ops) {
            if (op == "C") {
                if (!opS.empty()) {
                    int top = opS.top();
                    sum -= top;
                    opS.pop();
                }
            } else if (op == "D") {
                if (!opS.empty()) {
                    int top = opS.top();
                    opS.push(top*2);
                    sum += (opS.top());
                }
            } else if (op == "+") {
                int top0 {0}, top0Flag {0};
                int top1 {0}, top1Flag {0};
                if (!opS.empty()) {
                    top0 = opS.top();
                    top0Flag = 1;
                    opS.pop();
                }
                if (!opS.empty()) {
                    top1 = opS.top();
                    top1Flag = 1;
                    opS.pop();
                }
                if (top1Flag == 1) {
                    opS.push(top1);
                }
                if (top0Flag == 1) {
                    opS.push(top0);
                }
                opS.push(top0 + top1);
                sum += opS.top();
            } else {
                int opV = std::stoi(op);
                sum += opV;
                opS.push(opV);
            }
        }
        return sum;
    }
};

static int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    return 0;
}();
__________________________________________________________________________________________________
sample 9316 kb submission
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n=ops.size();
        int arr[n];
        int top=-1;
        for(int i=0;i<n;i++)
        {
            if(ops[i]=="C")
                top--;
            else if(ops[i]=="D")
            {
                arr[top+1]=2*arr[top];
                top++;
            }
            else if(ops[i]=="+")
            {
                arr[top+1]=arr[top]+arr[top-1];
                top++;
            }
            else
                arr[++top]=stoi(ops[i]);
        }
        int sum=0;
        for(int i=0;i<=top;i++)
        {
            sum+=arr[i];
        }
        return sum;
    }
};
__________________________________________________________________________________________________
