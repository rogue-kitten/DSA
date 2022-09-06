// link to the problem -> https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int n = arr.size();
        int s = 0, e = n - 1, m, ans = -1;
        while(s <= e){
            m = s + (e - s) / 2;
            if(m == 0 || arr[m] > arr[m - 1]){
                ans = m;
                s = m + 1;
            }
            else
                e = m - 1;
        }
        return ans;
    }
};
