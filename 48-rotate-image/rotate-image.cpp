class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //step 1: transpose
        int nrows = matrix.size();// rows
        int ncols = matrix[0].size();// cols

        for(int i=0; i<nrows; i++){
            for(int j=i; j<ncols; j++)
            swap(matrix[i][j],matrix[j][i]);
        }

        //step 2: revers row wise
        for(int i=0; i<nrows; i++)
            reverse(matrix[i].begin(), matrix[i].end());
        
    }
};