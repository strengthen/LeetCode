__________________________________________________________________________________________________
sample 8 ms submission
typedef long long ll;
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        ll sum = 0;
        int n=nums.size();
        for(auto& num : nums)sum += num, num-=1;
        int left, right;
        for (int I=0;I<1;++I){
            left = ceil(1.*sum / threshold);
            right = min(ceil(1.*sum/(threshold-n)),1.*(nums[n-1]+1));
            while(left < right){
                int mid = (left + right) / 2;
				int s = 0;
                //for(auto& num : nums)s += num / mid;
				int *p1=&nums[0],*p2=p1+n;
		__asm__ __volatile__
		(
			"mov $0,%%rcx\n"
			"mov %%rax,%%rsi\n"
			"mov %%edx,%%edi\n"
			"begin:\n"
			"mov $0,%%edx\n"
			"mov (%%rsi),%%eax\n"
			"idivl %%edi\n"
			"add %%eax,%%ecx\n"
			"lea 0x4(%%rsi),%%rsi\n"
			"cmp %%rsi,%%rbx\n"
			"jz end\n"
			"jmp begin\n"
			"end:\n"
			: "=c"(s)
			:"a"(p1), "b"(p2), "d"(mid)
			:
		);
                printf("s=%d %d %d\n",left,right,s);
				s+=n;
                if(s <= threshold)right = mid;
                else left = mid + 1;
            }
        }
        return left;
    }
};
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
__________________________________________________________________________________________________
sample 12 ms submission
typedef long long ll;
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        ll sum = 0;
        int n=nums.size();
        for(auto& num : nums)sum += num, num-=1;
        int left, right;
        for (int I=0;I<1;++I){
            left = ceil(1.*sum / t);
            right = min(ceil(1.*sum/(t-n)),1.*(nums[n-1]+1));
            while(left < right){
                int mid = (left + right) / 2;
				int s = 0;
                //for(auto& num : nums)s += num / mid;
				int *p1=&nums[0],*p2=p1+n;
				__asm__ __volatile__
				(
					"mov %1,%%rax\n"
					"mov %2,%%rbx\n"
					"mov %3,%%r14d\n"
					"mov $0,%%ecx\n"
					"mov %%rax,%%r13\n"
					"begin:\n"
					"mov $0,%%edx\n"
					"mov (%%r13),%%eax\n"
					"idivl %%r14d\n"
					"add %%eax,%%ecx\n"
					"lea 0x4(%%r13),%%r13\n"
					"cmp %%r13,%%rbx\n"
					"jz end\n"
					"jmp begin\n"
					"end:\n"
                    "mov %%ecx,%0\n"
					: "=g"(s)
					:"g"(p1), "g"(p2), "g"(mid)
					: "%r13", "%r14", "%rax", "%rbx", "%rcx"
				);
				s += n;
                if(s <= t)right = mid;
                else left = mid + 1;
            }
        }
        return left;
    }
};
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
__________________________________________________________________________________________________
