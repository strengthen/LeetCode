__________________________________________________________________________________________________
0ms
class Solution {
public:
    int maximumNumberOfOnes(int w, int h, int s, int mo) {
        int ans=0;
        int lx,ly,nx,ny;
        lx=w%s;
        ly=h%s;
        nx=w/s;
        ny=h/s;
        
        ans=nx*ny*mo;
        if(mo<=lx*ly) 
        {
            ans+=(nx+ny+1)*mo;
            return ans;
        }
        else
        {
            ans+=(nx+ny+1)*lx*ly;
            mo-=lx*ly;
            if(nx>ny)
            {
                if(mo<=(s-lx)*ly)
                {
                    ans+=(nx)*mo;
                    return ans;
                }
                else
                {
                    ans+=(s-lx)*ly*(nx);
                    mo-=(s-lx)*ly;
                    ans+=min(mo, (s-ly)*lx )*ny;
                    return ans;
                }
            }
            else
            {
                if(mo<=(s-ly)*lx)
                {
                    ans+=(ny)*mo;
                    return ans;
                }
                else
                {
                    ans+=(s-ly)*lx*(ny);
                    mo-=(s-ly)*lx;
                    ans+=min(mo, (s-lx)*ly )*nx;
                    return ans;
                }
            }
        }
        
    }
};
__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        int x=width/sideLength;
        int y=height/sideLength;
        int a=width%sideLength;
        int b=height%sideLength;
        int sq=x*y*maxOnes;
        if(maxOnes<=a*b)
            return (x+1)*(y+1)*maxOnes;
        if(maxOnes>=(a+b)*sideLength-a*b)
            return sq+(a*y+b*x)*sideLength+a*b;
        int bo1, ri1;
        if(maxOnes<=a*sideLength)
        {
            bo1=maxOnes;
            ri1=a*b;
        }
        else
        {
            bo1=a*sideLength;
            ri1=maxOnes-a*(sideLength-b);
        }
        int bo2, ri2;
        if(maxOnes<=b*sideLength)
        {
            ri2=maxOnes;
            bo2=a*b;
        }
        else
        {
            ri2=b*sideLength;
            bo2=maxOnes-b*(sideLength-a);
        }
        return sq+a*b+max(bo1*y+ri1*x, bo2*y+ri2*x);
    }
};
__________________________________________________________________________________________________
