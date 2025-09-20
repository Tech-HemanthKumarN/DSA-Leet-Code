class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int mid = s + (e - s)/2;

        while(s <= e){
            //single element

            if(s == e){
                return arr[e];
            }

            //mid-1 index per value 
            int leftValue = -1;
            //mid+1 index per value
            int rightValue = -1;
            //mid index per value
            int currValue = arr[mid];

            if(mid - 1 >= 0){
                leftValue = arr[mid - 1];
            }
            if(mid + 1 < n){
                rightValue = arr[mid+1];
            }

            //case 2:
            if(currValue != leftValue && currValue != rightValue ){
                return currValue;
            }
            //case 3:
            if(currValue == leftValue && currValue != rightValue){
                int pairStartingIndex = mid - 1;  
                if(pairStartingIndex & 1){
                    e = mid -1;
                }
                else{
                    s =mid+1;
                }

            }

            //case 4:
            else if( currValue == rightValue && currValue != leftValue){
                int pairStartingIndex = mid;
                if(pairStartingIndex & 1){
                    e = mid -1;
                }
                else{
                     s = mid +1;
                }
            }
            mid = s + (e - s)/2;
        }
        return -1;
        
    }
};