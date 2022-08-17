// link to  the problem -> https://leetcode.com/problems/single-number/

// Approach -> basic application of the XOR property

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) ans ^= nums[i];
        return ans;
    }
};
