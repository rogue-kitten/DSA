// link to the problem -> https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
private:
    int getPivot(vector<int> &nums, int n){
        int s = 0, e = n - 1, m, ans = -1;
        while(s <= e){
            m = s + (e-s)/2;
            if(nums[m] < nums[0]){
                ans = m;
                e = m - 1;
            }
            else
                s = m + 1;
        }
        return ans == -1 ? 0 : ans;
    }
    
    int solve(vector<int> & nums, int s, int e, int target){
        int m;
        while(s <= e){
            m = s + (e - s)/2;
            if(nums[m] == target)
                return m;
            if(nums[m] < target)
                s = m + 1;
            else
                e = m - 1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1){
            return nums[0] == target ? 0 : -1;
        }
        int pivot = getPivot(nums, n);
        
        if(nums[pivot] == target)
            return pivot;
        if(pivot == 0)
            return solve(nums, 0, n - 1, target);
        if(target >= nums[0])
            return solve(nums, 0, pivot - 1, target);
        else
           return solve(nums, pivot, n - 1, target);
        
    }
};
