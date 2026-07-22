class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (nums[mid] == target)
                return mid;
            
            // Left half is sorted
            if (nums[start] <= nums[mid]) {
                // Target is in the left sorted half
                if (target >= nums[start] && target <= nums[mid]) {
                    end = mid - 1;  // FIXED: was mid+1
                } else {
                    start = mid + 1;
                }
            } 
            // Right half is sorted
            else {
                // Target is in the right sorted half
                if (target >= nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};