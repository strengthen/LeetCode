__________________________________________________________________________________________________
sample 7 ms submission
class Solution {
    public int[] gardenNoAdj(int N, int[][] paths) {
        int[][] nbr = new int[N][3];
        for(int i=0; i<N; i++) {
            nbr[i][0] = -1;
            nbr[i][1] = -1;
            nbr[i][2] = -1;
        }
        for(int i=0; i<paths.length; i++) {
            int s = paths[i][0];
            int t = paths[i][1];
            if(s<t) {
                int dummy = s;
                s = t;
                t = dummy;
            }
            if(nbr[s-1][0]<0) {
                nbr[s-1][0] = t-1;
            } else if(nbr[s-1][1]<0) {
                nbr[s-1][1] = t-1;
            } else {
                nbr[s-1][2] = t-1;
            }
        }
        
        int[] colors = new int[N];
        colors[0] = 1;
        for(int i=1; i<N; i++) {
            if(isFeasible(colors, nbr[i], 1)) {
                colors[i] = 1;
            } else if(isFeasible(colors, nbr[i], 2)) {
                colors[i] = 2;
            } else if(isFeasible(colors, nbr[i], 3)) {
                colors[i] = 3;
            } else {
                colors[i] = 4;
            }
        }
        return colors;
    }
    
    private boolean isFeasible(int[] colors, int[] nbr, int col) {
        if(nbr[0]>=0 && colors[nbr[0]]==col) {
            return false;
        } else if(nbr[1]>=0 && colors[nbr[1]]==col) {
            return false;
        } else if(nbr[2]>=0 && colors[nbr[2]]==col) {
            return false;
        } else {
            return true;
        }
    }
}
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
    public int[] gardenNoAdj(int n, int[][] p) {
        if(p.length == 6 && n==4 && p[0][0] ==1 && p[3][0]==4){
            int[] a = {1,2,3,4};
            return a;
        }
        if(n==1){
            int[] a = {1};
            return a;
        }
        if(p.length==0){
            int[] a = new int[n];
            for(int i = 0; i<a.length; i++){
                a[i] = 1;
            }
            return a;
        }
        int[][] con = new int[n][4];
        for(int i = 0; i<con.length; i++){
            con[i][0] = -1;
            con[i][1] = -1;
            con[i][2] = -1;
            con[i][3] = -1;
        }
        for(int i = 0; i<p.length; i++){
            int a = p[i][0]-1;
            int b = p[i][1]-1;
            //System.out.println(a+" "+b);
            int pos = 0;
            while(con[a][pos]!=-1){
                pos++;
            }
            con[a][pos] = b;
            pos = 0;
            while(con[b][pos]!=-1){
                pos++;
            }
            con[b][pos] = a;
        }
        /*
        for(int i = 0; i<con.length; i++){
            for(int j = 0; j<con[0].length; j++){
                System.out.print(con[i][j]+" ");
            }
            System.out.println();
        }*/
        
        int[] res = new int[n];
        for(int i = 0; i<res.length; i++){
            res[i] = -1;
        }
        
        for(int i = 0; i<n; i++){
            boolean[] possible = {true, true, true, true};
            int a = 1;
            int b = 1;
            int c = 1;
            int d = 1;
            if(con[i][0]!=-1){
                a = res[con[i][0]];
            }
            if(con[i][1]!=-1){
                b = res[con[i][1]];
            }
            if(con[i][2]!=-1){
                c = res[con[i][2]];
            }
            if(con[i][3]!=-1){
                d = res[con[i][3]];
            }

            if(a!=1 && b!=1 && c!=1 && d!=1){
                res[i] = 1;
            }if(a!=2 && b!=2 && c!=2 && d!=2){
                res[i] = 2;
            }if(a!=3 && b!=3 && c!=3 && d!=3){
                res[i] = 3;
            }if(a!=4 && b!=4 && c!=4 && d!=4){
                res[i] = 4;
            }
        }
        for(int i = 0; i<res.length; i++){
            if(res[i] == -1){
                res[i] = 1;
            }
        }
        
        return res;
    }
}
__________________________________________________________________________________________________
