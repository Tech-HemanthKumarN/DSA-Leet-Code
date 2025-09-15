class Solution {
public:
//Pivot mathod 
    int getPivotIndex(vector<int>& arr){ 
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int mid = s+(e-s)/2;

        while(s<=e){
            if( s == e){
                return s;
            }
            if(mid+1 < n && arr[mid] > arr[mid+1]){
                return mid;
            }
            if(arr[s] > arr[mid]){
                 e =mid -1;
            }else{
                s =mid+1;
            }
            mid = s+(e-s)/2;
        }
        return -1;

    }
// Binary search 
    int binarySearch(int s, int e, int target, vector<int>& arr){
        int mid = s+ (e-s)/2;
        while(s<=e){
            if(arr[mid] == target){
                return mid;
            }
            if(target > arr[mid]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        return -1;
    }


    int search(vector<int>& nums, int target) {
       
        int pivotIndex = getPivotIndex(nums);
        //line->A->index->0 -->PivotIndex;
        //line->B-ivotIndex+1->n-1

        // if target lies insode line->A then search in line->A
        int n = nums.size();
        if( target >= nums[0] && target<= nums[pivotIndex]){
            //BS Apply
            int ans =binarySearch(0,pivotIndex,target,nums);
            return ans;
        }//if target lies in line->B then search in line-> B
        else{
            //BS Apply
            int ans = binarySearch(pivotIndex+1,n-1,target,nums);
            return ans;
        }
        return -1;
    }
};