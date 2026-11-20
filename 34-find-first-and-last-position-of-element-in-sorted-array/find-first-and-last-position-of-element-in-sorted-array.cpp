class Solution {
public:
    int findFirst(vector<int>& nums, int target, int low, int high) {
        if (low > high) {
            return -1;
        }
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            int leftOccr = findFirst(nums, target, low, mid - 1);
            return (leftOccr != -1) ? leftOccr : mid;
        }
        if (nums[mid] < target) {
            return findFirst(nums, target, mid + 1, high);
        }
        return findFirst(nums, target, low, mid - 1);
    }

    int findLast(vector<int>& nums, int target, int low, int high) {
        if (low > high) {
            return -1;
        }
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            int rightOccr = findLast(nums, target, mid + 1, high);
            return (rightOccr != -1) ? rightOccr : mid;
        }
        if (nums[mid] < target) {
            return findLast(nums, target, mid + 1, high);
        }
        return findLast(nums, target, low, mid - 1);
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int firstIdx = findFirst(nums, target, 0 ,n-1);
        int lastIdx = findLast(nums, target,0,n-1);
        return {firstIdx, lastIdx};
    }
};