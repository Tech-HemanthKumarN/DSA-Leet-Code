class Solution {
public:
    int search(vector<int>& arr, int target) {
        int  n = arr.size();
        int  start = 0;
        int end = n-1;
        int mid = start + (end - start)/2;

        while(start <= end){
            if(arr[mid] == target){
                return mid;
            }
            if(target > arr[mid]){
                start = mid + 1;
            }
            if(target < arr[mid]){
                end = mid - 1;
            }

            mid = start +(end - start)/2;
        }
        return -1;
    }
};