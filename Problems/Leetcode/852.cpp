// link to the problem -> https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int s = 1, e = n - 2, m, ans  = -1;
        if(s == e)
            return 1;
        
        while(s <= e){
            m = s + (e - s)/ 2;
            if(arr[m] > arr[m + 1] && arr[m] > arr[m -1])
                return m;
            if(arr[m] > arr[m + 1] && arr[m] < arr[m -1])
                e = m - 1;
            else
                s = m + 1;
        }
        
        return -1;
    }
};
