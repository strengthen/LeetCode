__________________________________________________________________________________________________
120ms
public class Solution {
      public double FindMedianSortedArrays(int[] nums1, int[] nums2)
        {
            int[] nArr = new int[nums1.Length + nums2.Length];
            int oneIn = 0;
            int twoIn = 0;
            for (int i = 0; i < nums1.Length + nums2.Length; i++)
            {
                if (oneIn >= nums1.Length)
                {
                    nArr[i] = nums2[twoIn++];
                }
                else
                if (twoIn >= nums2.Length)
                {
                    nArr[i] = nums1[oneIn++];
                }

                else if(nums1[oneIn] <= nums2[twoIn])
                {
                    nArr[i] = nums1[oneIn++];
                }
                else
                {
                    nArr[i] = nums2[twoIn++];
                }
            }
            return GetMed(nArr, 0, nArr.Length - 1);
        }


        public double FindMedianSortedArraysHelper(int[] nums1, int[] nums2, int nSt, int nEnd, int n2St, int n2End)
        {
            double med = 0.0;

            double med1 = GetMed(nums1,nSt, nEnd);
            int mid1 = medEl;
            double med2 = GetMed(nums2, n2St, n2End);
            int mid2 = medEl;
            if (nums1.Length <= nEnd || nums1.Length <= nSt) return med2;
            if (nums2.Length <= n2End || nums2.Length <= n2St) return med1;
            if (med1 == med2) return med1;
            if (nums2[n2St] > nums1[nEnd])
            {
                int l1 = nEnd - nSt + 1;
                int l2 = n2End - n2St + 1;
                if (l1 == l2) return Convert.ToDouble(nums1[nEnd] + nums2[nSt]) / 2;
                else if (l1 < l2)
                {
                    return nums2[n2St + l2 - ((l1 + l2 + 1) / 2)];
                    // 1 2 3 
                    // 4 5 6 7
                }
                else
                {
                    return nums1[nSt + l1 - ((l1 + l2 + 1) / 2)];
                }
            }
            else if (nums1[nSt] > nums2[n2End])
            {
                int l1 = nEnd - nSt;
                int l2 = n2End - n2St;
                if (l1 == l2) return Convert.ToDouble(nums1[nEnd] + nums2[nSt]) / 2;
                else if (l1 < l2)
                {
                    return nums2[n2St + l2 - ((l1 + l2 + 1) / 2)]; 
                    // 2
                    // -2 -1
                }
                else
                {
                    return nums1[nSt + l1 - ((l1 + l2 + 1) / 2)];
                }
            }
            else if (med1 < med2)
            {
                med = FindMedianSortedArraysHelper(nums1, nums2, mid1 + 1, nEnd, n2St, mid2 - 1);
            }
            else
            {
                med = FindMedianSortedArraysHelper(nums1, nums2, nSt, mid1 - 1, mid2 + 1, n2End);
            }

            return med;

        }
        int medEl = 0;
        private double GetMed(int[] arr,int fr, int to)
        {
            double med = 0.0;

            if (arr.Length == 0 || fr > to) return med;
            if (arr.Length == 1 || fr == to ) return arr[fr];
            medEl = fr + (to - fr) / 2;

            if ((to-fr+1) % 2 == 0)
            {
                med = Convert.ToDouble( (arr[medEl] + arr[medEl + 1])) / 2;
            }
            else
                med = arr[medEl];
            return med;
        }
}
__________________________________________________________________________________________________
124ms
public class Solution {
    public double FindMedianSortedArrays(int[] a, int[] b) {
        if (a == null) throw new ArgumentNullException(nameof(a));
            if (b == null) throw new ArgumentNullException(nameof(b));
            /// Zero length is handled in <see cref="GetKthItem"/>

            var combinedLength = a.Length + b.Length;

            // For Odd array length return a single middle element of the array
            if (combinedLength % 2 == 1) return GetKthItem(a, b, 0, 0, (combinedLength + 1) / 2);

            // For Even array length return an Average of two middle elements of the array
            return (GetKthItem(a, b, 0, 0, combinedLength / 2) + GetKthItem(a, b, 0, 0, combinedLength / 2 + 1)) / 2.0;
    }
    
    private static double GetKthItem(int[] a, int[] b, int aPos, int bPos, int k)
        {
            var aLengthRemainder = a.Length - aPos;
            var bLengthRemainder = b.Length - bPos;

            // for example: when k==0, or greater than combined array lengths
            if (k == 0 || (aLengthRemainder + bLengthRemainder) < k) return -1;
            // for example: when a.Length==0 and aPos==0
            if (aLengthRemainder <= 0) return b[bPos + k - 1];
            // for example: when b.Length==0 and bPos==0
            if (bLengthRemainder <= 0) return a[aPos + k - 1];
            // base condition for recursion: when k==1, select a Min element out of 2 first elements: a[aPos] & b[bPos]
            if (k == 1) return Math.Min(a[aPos], b[bPos]);

            var aValue = (aLengthRemainder >= k / 2) ? a[aPos + k / 2 - 1] : int.MaxValue;
            var bValue = (bLengthRemainder >= k / 2) ? b[bPos + k / 2 - 1] : int.MaxValue;

            if (aValue >= bValue) return GetKthItem(a, b, aPos, bPos + k / 2, k - k / 2);

            return GetKthItem(a, b, aPos + k / 2, bPos, k - k / 2);
        }
}
__________________________________________________________________________________________________
128ms
public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        int num=0;
        int n3m=0;
        int[] n=nums1.Length>=nums2.Length?nums1:nums2;
        int[] n2=n==nums1?nums2:nums1;
        int[] n3=new int[nums1.Length+nums2.Length];     
        int i=0;
        if(n3.Length<=2){
            if(n.Length==0)
                return n2.Length==1?n2[0]:(double)(n2[0]+n2[1])/2;
            if(n.Length==1)
                return n2.Length==1?(double)(n[0]+n2[0])/2:n[0];
        }
        for(i=0;n3m<n3.Length/2+1;i++,n3m++){
            if(num<n2.Length&&i>=n.Length){
                n3[n3m]=n2[num];
                ++num;
                continue;
            }
            if(num<n2.Length&&n2[num]<n[i]){
               n3[n3m]=n2[num];
                ++num;
                --i;
            }
            else{
                n3[n3m]=n[i];
            }
        }
        n3m=n3m>0?n3m-1:0;
        Console.WriteLine(n3m+"|"+n3.Length+"|"+n3[n3m-1]+"|"+n3[n3m]);
            return   n3.Length%2==0?(double)(n3[n3m-1]+n3[n3m])/2:n3[n3m];
    }
}
__________________________________________________________________________________________________
24988 kb
public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2)
    {
        int[] A, B;
        if (nums1.Length < nums2.Length)
        {
            A = nums1;
            B = nums2;
        }
        else
        {
            A = nums2;
            B = nums1;
        }
        int n = A.Length, m = B.Length,
            i = 0, j = 0,
            imin = 0, imax = n,
            half = (n + m + 1) / 2,
            median = 0;

        while (imin <= imax)
        {
            i = (imin + imax) / 2;
            j = half - i;

            if (i < n && j > 0 && B[j - 1] > A[i])
                imin = i + 1;
            else if (j < m && i > 0 && A[i - 1] > B[j])
                imax = i - 1;
            else
            {
                median =
                    i == 0
                        ? B[j - 1]
                        : j == 0
                            ? A[i - 1]
                            : Math.Max(A[i - 1], B[j - 1]);
                break;
            }
        }

        if ((n + m) % 2 == 1)
            return median;

        if (i == n)
            return (median + B[j]) / 2.0;

        if (j == m)
            return (median + A[i]) / 2.0;

        return (median + Math.Min(A[i], B[j])) / 2.0;
    }
}
__________________________________________________________________________________________________
25424 kb
public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2)
        {
            int lengthOfFirstArray = nums1.Length;
            int lengthOfSecondArray = nums2.Length;
            int totalLength = (lengthOfFirstArray + lengthOfSecondArray);
            bool medianIsAverageOfTwoNumbers = ((totalLength % 2) == 0);
            int indexOfMedian = totalLength / 2; // this is the index of median in the imaginary combined array
            int median = 0;
            int lowerMedian = 0;// for cases where median is an average
            for (int medianCounter = 0, indexOfFirstArray =0, indexOfSecondArray=0; medianCounter <= indexOfMedian; medianCounter++)
            {
                lowerMedian = median;
                if (indexOfFirstArray < lengthOfFirstArray && indexOfSecondArray < lengthOfSecondArray)
                {
                    if (nums1[indexOfFirstArray] < nums2[indexOfSecondArray])
                    {
                        median = nums1[indexOfFirstArray];
                        indexOfFirstArray++;
                    }
                    else
                    {
                        median = nums2[indexOfSecondArray];
                        indexOfSecondArray++;
                    }
                }
                else if (indexOfFirstArray < lengthOfFirstArray)
                {
                    median = nums1[indexOfFirstArray];
                    indexOfFirstArray++;
                }
                else
                {
                    median = nums2[indexOfSecondArray];
                    indexOfSecondArray++;
                }
            }

            if (medianIsAverageOfTwoNumbers)
                return (double)(lowerMedian + median) / 2;
            return median;
        }
}
__________________________________________________________________________________________________
