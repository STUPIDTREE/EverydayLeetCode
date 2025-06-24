#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// int findUnsortedSubarray(vector<int>& nums) {
//     int end = -1;
//     int max_num = nums[0];
//     int len = nums.size();
//     int start = -1;
//     int min_num = nums[len - 1];
//     for(int i = 0; i < nums.size(); i++) {
//         if(nums[i] < max_num) {
//             end = i;
//         }
//         else {
//             max_num = nums[i];
//         }

//         if(nums[len - 1 - i] > min_num) {
//             start = len - 1 - i;
//         }
//         else {
//             min_num = nums[len - 1 - i];
//         }
//     }

//     return end == -1 ? 0 : end - start + 1; 
// }

int mypartition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int end = right;
    int start = left;
    while(start < end) {
        if(nums[start] > pivot) {
            swap(nums[start], nums[end - 1]);
            end--;
        }
        else {
            start++;
        }
    }
    swap(nums[start], nums[right]);
    return start;
}

void quickSort(vector<int>& nums, int left, int right) {
    if(left < right) {
        int pivot_idx = mypartition(nums, left, right);
        quickSort(nums, left, pivot_idx - 1);
        quickSort(nums, pivot_idx + 1, right);
    }
}

int findUnsortedSubarray(vector<int>& nums) {
    vector<int> sorted_num = nums;
    // sort(sorted_num.begin(), sorted_num.end());
    quickSort(sorted_num, 0, sorted_num.size() - 1);
    int start = 0;
    while(start < nums.size() && sorted_num[start] == nums[start]) {
        start++;
    }
    int end = nums.size() - 1;
    while(end >= 0 && sorted_num[end] == nums[end]) {
        end--;
    }

    return end > start ? end - start + 1 : 0;
}



int main() {

    vector<int> nums = {1,2,3,4}; // [1,2,3,4]  [1] [2,6,4,8,10,9,15]
    int result = findUnsortedSubarray(nums);
    cout << result << endl;

    return 0;
}