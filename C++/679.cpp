__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool game(vector<double> & nums,int n)
    {
        if(n==1)
        {
            if(fabs(nums[0]-24)<1e-6)
                return true;
            else 
                return false;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double a=nums[i];
                double b=nums[j];
                nums[j]=nums[n-1];

                nums[i]=a+b;
                if(game(nums,n-1))
                    return true;

                nums[i]=a-b;
                if(game(nums,n-1))
                    return true;

                nums[i]=b-a;
                if(game(nums,n-1))
                    return true;  

                nums[i]=b*a;
                if(game(nums,n-1))
                    return true;  

                if(b!=0)
                {
                    nums[i]=a/b;
                    if(game(nums,n-1))
                        return true;  
                }

                if(a!=0)
                {
                    nums[i]=b/a;
                    if(game(nums,n-1))
                        return true;  
                }
                nums[i]=a;
                nums[j]=b;
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& nums) {
        vector<double>  qq(nums.size(),0.0);
        for(int i=0;i<4;i++)
            qq[i]=(double)nums[i];
        return game(qq,4);
    }
};
__________________________________________________________________________________________________
sample 8408 kb submission
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        do {
            if (valid(nums)) return true;
        } while(next_permutation(nums.begin(), nums.end()));
        return false;
    }
private:
    bool valid(vector<int>& nums) {
        double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        if (valid(a+b, c, d) || valid(a-b, c, d) || valid(a*b, c, d) || valid(a/b, c, d)) return true;
        if (valid(a, b+c, d) || valid(a, b-c, d) || valid(a, b*c, d) || valid(a, b/c, d)) return true;
        if (valid(a, b, c+d) || valid(a, b, c-d) || valid(a, b, c*d) || valid(a, b, c/d)) return true;
        return false;
    }
    bool valid(double a, double b, double c) {
        if (valid(a+b, c) || valid(a-b, c) || valid(a*b, c) || b&&valid(a/b, c)) return true;
        if (valid(a, b+c) || valid(a, b-c) || valid(a, b*c) || c&&valid(a, b/c)) return true;
        return false;
    }
    bool valid(double a, double b) {
        if (abs(a+b-24.0) < 0.0001 || abs(a-b-24.0) < 0.0001 || abs(a*b-24.0) < 0.0001 || b&&abs(a/b-24.0) < 0.0001)
            return true;
        return false;
    }
};
__________________________________________________________________________________________________
