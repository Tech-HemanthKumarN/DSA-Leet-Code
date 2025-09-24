class Solution {
public:
    void findFirstOccurence(vector<int>arr, int n, int target, int &ansIndex){
        int s = 0;
        int e = n-1;
        int mid = s + (e - s)/2;

        while(s <= e){
            if(arr[mid] == target){
                ansIndex = mid;
                e = mid - 1;
            }
            if(target >  arr[mid]){
                s = mid + 1;
            }
            if( target < arr[mid]){
                e = mid - 1;
            }
             
            mid = s + (e - s)/2;
        }
    }

    void findLastOccurence(vector<int>arr, int n, int target, int &ansIndex){
        int s = 0 ;
        int e = n-1;
        int mid = s + (e - s)/2;

        while(s <= e){
            if(arr[mid] == target){
                ansIndex = mid;
                s =  mid + 1;
            }

            if(target > arr[mid]){
                s = mid + 1;
            }
            if(target < arr[mid]){
                e = mid - 1;
            }
            mid = s + (e - s)/2;
        }
    }
    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        int firstOccIndex = -1;
        findFirstOccurence(arr,n,target,firstOccIndex);
        
        int LastOccIndex = -1;
        findLastOccurence(arr,n,target,LastOccIndex);

        vector<int> temp(2);
        temp[0] = firstOccIndex;
        temp[1] = LastOccIndex;
        return temp;
        

        
    }
};