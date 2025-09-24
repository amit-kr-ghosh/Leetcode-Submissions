class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Make sure mid is even
            if (mid % 2 == 1) mid--;

            // Check the pair
            if (nums[mid] == nums[mid + 1]) {
                // Single element is on the right
                left = mid + 2;
            } else {
                // Single element is on the left (including mid)
                right = mid;
            }
        }

        return nums[left];
    }
};
