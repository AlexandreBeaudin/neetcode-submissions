class Solution {
public:
    int partition(vector<int> &nums, int left, int right) {
        int pivot = nums[right];
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (nums[j] < pivot) {
                i++;
                // swap
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
        }
        int temp = nums[i + 1];
        nums[i + 1] = nums[right];
        nums[right] = temp;

        return i + 1;
    }

    void quickSort(vector<int> &nums, int left, int right) {
        if (left < right) {
            int newMid = partition(nums, left, right);
            quickSort(nums, left, newMid - 1);
            quickSort(nums, newMid + 1, right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};