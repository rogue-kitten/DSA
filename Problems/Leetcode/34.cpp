// link to the problem -> https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        //finding the first position
        int s = 0, e = n - 1, m, ans = -1;
        while(s <= e){
            m = s + (e - s)/2;
            if(nums[m] == target){
                ans = m;
                e = m - 1;
            }
            else if(nums[m] < target)
                s = m + 1;
            else
                e = m - 1;
        }
        
        vector<int> res(2, -1);
        if(ans == -1)
            return res;
        res[0] = ans;
        s = 0, e = n - 1, m, ans = -1;
        while(s <= e){
            m = s + (e - s)/2;
            if(nums[m] == target){
                ans = m;
                s = m + 1;
            }
            else if(nums[m] < target)
                s = m + 1;
            else
                e = m - 1;
        }
        res[1] = ans;
        return res;
    }
};
