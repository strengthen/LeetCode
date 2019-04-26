__________________________________________________________________________________________________
sample 84 ms submission
static int io_optimize = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0; } ();

typedef int ParamType;
const int _max_len = 5e4;
static ParamType _swap_arr[_max_len];

class Solution {
    int mergesort_binary(ParamType* A, int mid, int right) {
        int sum = 0;
        ParamType *end = A + mid, *begin = A;
        for (int j = mid; j <= right; ++j) {
            ParamType* p = std::upper_bound(begin, end,
                                            2 * static_cast<long long>(A[j]));
            if (p == end) break;
            sum += end - p;
            begin = p;
        }
        int i = 0, j = mid, k = 0;
        ParamType* T = _swap_arr;
        do {
            if (A[i] <= A[j]) {
                T[k++] = A[i++];
                if (i >= mid) {
                    while (j <= right) T[k++] = A[j++];
                    break;
                }
            } else {
                T[k++] = A[j++];
                if (j > right) {
                    while (i < mid) T[k++] = A[i++];
                    break;
                }
            }
        } while (true);
        memcpy(A, T, sizeof(T[0]) * k);
        return sum;
    }

    int mergesort(ParamType* A, int mid, int right) {
        int sum = 0;
        ParamType *end = A + mid, *begin = A;
        int i = 0, j = mid, k = 0;
        ParamType* T = _swap_arr;
        for (; j <= right; ++j) {
            register ParamType tmp = A[j];
            while (i < mid && A[i] <= tmp) T[k++] = A[i++];
            T[k++] = tmp;
            long long tmp_d = static_cast<long long>(tmp) * 2;
            while (*begin <= tmp_d) {
                if (++begin >= end) {
                    for (++j; j <= right; ++j) {
                        register ParamType tmp = A[j];
                        while (i < mid && A[i] <= tmp) T[k++] = A[i++];
                        T[k++] = tmp;
                    }
                    goto _sort;
                }
            }
            sum += end - begin;
        }
    _sort:
        while (i < mid) T[k++] = A[i++];
        memcpy(A, T, sizeof(T[0]) * k);
        return sum;
    }

    int merge(ParamType* begin, int right) {
        // if (left >= right) return;
        int sum = 0;
        int mid = right / 2;
        if (0 < mid) sum += merge(begin, mid);
        if (mid + 1 < right) sum += merge(begin + mid + 1, right - mid - 1);
        if (0 < right) sum += mergesort(begin, mid + 1, right);
        return sum;
    }
public:
    int reversePairs(std::vector<ParamType>& nums) {
        return merge(nums.data(), nums.size() - 1);
    }
};
__________________________________________________________________________________________________
sample 15644 kb submission
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;
        int res = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
        for (int i = left, j = mid + 1; i <= mid; ++i) {
            while (j <= right && nums[i] / 2.0 > nums[j]) ++j;
            res += j - (mid + 1);
        }
        sort(nums.begin() + left, nums.begin() + right + 1);
        return res;
    }
};
__________________________________________________________________________________________________
