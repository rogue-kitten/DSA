// link to the problem -> https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// similar to the part one of this problem, just adding the while statement before to check. 
// In the worst case, the code runs in O(n), avg case O(logn)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1, m, ans = -1;
        while(nums[s] == nums[e] && e > s)
            e--;
        while(s <= e){
            m = s + (e-s)/2;
            if(nums[m] < nums[0]){
                ans = nums[m];
                e = m - 1;
            }
            else
                s = m + 1;
        }
        return ans == -1 ? nums[0] : ans;
    }
};
