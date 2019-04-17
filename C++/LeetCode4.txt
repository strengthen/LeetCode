__________________________________________________________________________________________________
12ms
static auto _ = [](){ios_base::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr); return 0; }();

inline double avg(double a, double b) {
    return (a + b) / 2.0;
}

class Solution {
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) swap(nums1, nums2);
        
        int n1 = (int)nums1.size();
        int n2 = (int)nums2.size();
        
        int start = 0;
        int end = n1;
        
        while(start <= end) {
            
            int n1_left = start + (end - start) / 2;
            int n2_left = (n1 + n2 + 1) / 2 - n1_left;
            
            int L1 = n1_left == 0 ? INT_MIN : nums1[n1_left - 1];
            int R1 = n1_left == n1 ? INT_MAX : nums1[n1_left];
            
            int L2 = n2_left == 0 ? INT_MIN : nums2[n2_left - 1];
            int R2 = n2_left == n2 ? INT_MAX : nums2[n2_left];
            
            if(L1 <= R2 && L2 <= R1) {
                if((n1 + n2) % 2) return max(L1, L2);
                else return avg(max(L1, L2), min(R1, R2));
            }
            else if(L1 <= R2) start = n1_left + 1;
            else end = n1_left - 1;
        }
        
        return -1.0;
    }
};
__________________________________________________________________________________________________
16ms
class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) 
    {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int m = A.size(), n = B.size();
        if(m > n)
        {
            swap(n, m);
            swap(A, B);
        }
        
        int iMin = 0, iMax = m, halfLen = (n + m + 1) / 2;
        while(true)
        {
            int i = (iMin + iMax) / 2, j = halfLen - i;
            if (i < m && A[i] < B[j - 1])
                iMin = i + 1;
            else if (i > 0 && B[j] < A[i - 1])
                iMax = i - 1;
            else
            {
                int leftMax = 0;
                if (i == 0)
                    leftMax = B[j - 1];
                else if (j == 0)
                    leftMax = A[i - 1];
                else
                    leftMax = max(A[i - 1], B[j - 1]);
                
                if ((n + m) & 1)
                    return leftMax;
                
                int rightMin = 0;
                if (i == m)
                    rightMin = B[j];
                else if (j == n)
                    rightMin = A[i];
                else
                    rightMin = min(A[i], B[j]);

                return static_cast<double>(leftMax + rightMin) / 2;
            }
        }
        return 0;
    }
};
__________________________________________________________________________________________________
24ms
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }        
        int len = nums1.size() + nums2.size(), cut1 = 0, cut2 = 0, curL = 0, curR = nums1.size();
        while(cut1 <= nums1.size()){
            cut1 = (curL+curR)/2, cut2 = (len/2)-cut1;
            int L1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int L2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            int R1 = cut1 == nums1.size() ? INT_MAX : nums1[cut1];
            int R2 = cut2 == nums2.size() ? INT_MAX : nums2[cut2];
            if(L1 > R2){
                curR = cut1-1;
            }else if(L2 > R1){
                curL = cut1+1;
            }else{
                if(len%2==0){
                    L1 = L1 > L2 ? L1 : L2;
                    R1 = R1 < R2 ? R1 : R2;
                    return (L1+R1)/2.0;
                }else{
                    return R1 < R2 ? R1 : R2;
                }
            }
        }
        return -1;        
    }
};
__________________________________________________________________________________________________
9536 kb
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        
        int x=0,y=0;
        int k = 0,k1 = 0;
        int len = nums1.size() + nums2.size();
        if (len == 1) {
            return nums1.empty() ? nums2.front() : nums1.front();
        }
        
        // generating next element in sorted array
        for(int i=0; i <= len / 2; i++) {
            swap(k, k1);
            if (x != nums1.size() && y != nums2.size()) {
                if (nums1[x] < nums2[y]) {
                    k = nums1[x];
                    x++;
                } else {
                    k = nums2[y];
                    y++;
                }
            } else if (x == nums1.size()) {
                k = nums2[y];
                y++;
            
            } else {
                k = nums1[x];
                x++;
            }
        }        
        return !(len % 2) ? (double) (k+k1) / 2 : (double)k;
        
    }
};
__________________________________________________________________________________________________
9548 kb
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = a.size(), m = b.size();
        if((n+m)%2==0)
        {
            return (kth(a,b,((n+m)/2)) + kth(a,b,(n+m)/2-1)) / 2.0;
        }
        else
        {
            return kth(a,b,(n+m)/2);
        }
    }
    int kth(vector<int>& a, vector<int>& b, int k) {
       // cout << "k = " << k << endl;
        int n = a.size(), m = b.size();
        int low = 0, high = n-1;
        while(low <= high)
        {
            int mid=low+(high-low)/2;
            int big = mid + upper_bound(b.begin(),b.end(),a[mid])-b.begin();
            int less = mid + upper_bound(b.begin(),b.end(),a[mid]-1)-b.begin();
            if(less <= k && k <= big)
                return a[mid];
            if(less<k) low=mid+1;
            else if(less>k) high=mid-1;
        }
        //cout << "bs turn\n";
        low=0,high=m-1;
        while(low <= high)
        {
            int mid=low+(high-low)/2;
            int big = mid + upper_bound(a.begin(),a.end(),b[mid])-a.begin();
            int less = mid + upper_bound(a.begin(),a.end(),b[mid]-1)-a.begin();
          //  cout << b[mid] << " " << less << " " << less <<  " " << big << endl;
            if(less <= k && k <= big)
                return b[mid];
            if(big<k) low=mid+1;
            else if(less>k) high=mid-1;
            //cout << "low = " << low << " high = " << high << endl;
        }
        return 0;
    }
};
__________________________________________________________________________________________________
