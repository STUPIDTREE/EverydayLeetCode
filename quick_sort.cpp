#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int Partition(vector<int> & nums, int left, int right) {
    int pivot = nums[right];
    int pivotIdx = left - 1;
    for(int i = left; i < right; i++) {
        if(nums[i] < pivot) {
            pivotIdx++;
            swap(nums[i], nums[pivotIdx]);
        }
    }
    swap(nums[pivotIdx + 1], nums[right]);
    return pivotIdx + 1;

}

void QuickSort(vector<int> & nums, int left, int right) {
    if(left < right) {
        int pivotIdx = Partition(nums, left, right);

        QuickSort(nums, left, pivotIdx - 1);
        QuickSort(nums, pivotIdx + 1, right);
    }
}

int main() {

    vector<int> nums = {2,5,4,8,7};
    QuickSort(nums, 0, nums.size() - 1);

    for(int num:nums) {
        cout << num << " ";
    }

    return 0;
}