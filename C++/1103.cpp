__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people);
        if(candies < 0 || num_people<=0){
            return res;
        }
        long long int l = 0, r = 100000;
        long long int ans=0;
        while(l<=r){
            long long int m = (l+r)/2;
            long long int sum = m*num_people;
            sum=sum*(sum+1)/2;
            cout<<sum<<" "<<candies<<endl;
            if(sum>candies){
                r=m-1;
            }
            else{
                ans=m;
                l=m+1;
            }
        }
        cout<<ans<<endl;
        for(int i=0;i<num_people;i++){
            if(ans == 0) continue;
            long long int temp = ans*(2*(i+1)+(ans-1)*num_people);
            temp/=2;
            res[i]=temp;
            cout<<res[i]<<" ";
        }
        long long int rem = ans*num_people;
        rem = rem*(rem+1)/2;
        rem = candies - rem;
        cout<<"rem: "<<rem<<endl;
        long long int fact = ans;
        if(ans==0) fact=0;
        for(int i=0;i<num_people and rem>0;i++){
            res[i] += min((fact)*num_people+(i+1), rem);
            rem-=(fact)*num_people+(i+1);
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people);
        if(candies < 0 || num_people<=0){
            return res;
        }
        long long int l = 0, r = 100000;
        long long int ans=0;
        while(l<=r){
            long long int m = (l+r)/2;
            long long int sum = m*num_people;
            sum=sum*(sum+1)/2;
            if(sum>candies){
                r=m-1;
            }
            else{
                ans=m;
                l=m+1;
            }
        }
        for(int i=0;i<num_people;i++){
            if(ans == 0) continue;
            long long int temp = ans*(2*(i+1)+(ans-1)*num_people)/2;
            res[i]=temp;
        }
        long long int rem = ans*num_people;
        rem = rem*(rem+1)/2;
        rem = candies - rem;
        long long int fact = ans;
        if(ans==0) fact=0;
        for(int i=0;i<num_people and rem>0;i++){
            res[i] += min((fact)*num_people+(i+1), rem);
            rem-=(fact)*num_people+(i+1);
        }
        return res;
    }
};
__________________________________________________________________________________________________
