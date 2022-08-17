// link to problem - https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        
        for(int i = 0; i < k; i++){
            while(!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
        }
        
        vector<int> ans;
        ans.push_back(nums[q.front()]);
        for(int i = k; i < nums.size(); i++){
            while(!q.empty() && i - q.front() >= k)
                q.pop_front();
                
            while(!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            
            q.push_back(i);
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
