__________________________________________________________________________________________________
class MajorityChecker {
    int n,a[20005];
public:
    MajorityChecker(vector<int>& arr) {
        n=arr.size();
        for(int i=0;i<n;i++)a[i]=arr[i];
    }
    
    int query(int left, int right, int threshold) {
        int i,j,k;
        j=k=0;
        for(i=left;i<=right;i++)if(a[i]==j)k++;
        else if(k)k--;
        else
        {
            j=a[i];
            k=1;
        }
        for(i=left,k=0;i<=right;i++)if(a[i]==j)k++;
        if(k<threshold)j=-1;
        return j;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */

__________________________________________________________________________________________________

__________________________________________________________________________________________________
