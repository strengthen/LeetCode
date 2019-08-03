__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0, tempS = 0, base = 0, i = 1;
        for (int e: A) sum += e;
        if (sum % 3 != 0) return false;
        base = sum / 3;
        for (int e: A) {
            tempS += e;
            if (tempS == base * i) i++;
        }
        return i==4;
    }
}
__________________________________________________________________________________________________
sample 44796 kb submission
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int total = Arrays.stream(A).sum();
        if (total % 3 != 0) return false;
        System.out.println("Total: " + total);
        
        int sum = 0;
        int parts = 0;
        for (int i = 0; i < A.length; i++) {
            sum += A[i];
            System.out.println("Cur sum: " + sum);
            if (sum == (total / 3)) {
                parts++;
                sum = 0;
                System.out.println("Parts: " + parts);
            }
            // if (parts == (total != 0 ? 2 : 3)) break;
            if (parts == 2) break;
        }
        
        // return parts == (total != 0 ? 2 : 3);
        return parts == 2;
    }
}
__________________________________________________________________________________________________
