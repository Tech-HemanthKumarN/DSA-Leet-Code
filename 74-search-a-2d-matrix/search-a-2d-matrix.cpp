class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int columns = matrix[0].size();

        //total elements
        int n = row*columns;

        int s = 0;
        int e = n-1;
        int mid = s +(e-s)/2;

        while(s<=e){
            //mid ka use karkek 2D array ka row index and col index find karenge
            int rowIndex = mid/columns;
            int colIndex = mid%columns;

            if(matrix[rowIndex][colIndex] == target){
                return true;
            }
             if( target > matrix[rowIndex][colIndex]){
                //right
                s = mid+1;
             }
             else{
                //left
                e = mid -1;
             }
             //udate mid
             mid = s + (e - s)/2;
        }
        return false;
        
    }
};