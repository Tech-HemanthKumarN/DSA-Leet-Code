class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0; // ans
        int n = height.size();
        //leftPointer
        int lp = 0;
        //rightPointer
        int rp = n - 1;

        while (lp < rp) {
            // width
            int wd = rp - lp;
            // height
            int ht = min(height[lp], height[rp]);

            int currWater = wd * ht;
            maxWater = max(maxWater, currWater);

            if(height[lp] < height[rp]){
                lp++;
            }
            else{
                rp--;
            }
        }
        return maxWater;
    }
};

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int maxWater = 0;

//         for(int  i = 0; i < height.size(); i++){
//             for(int  j = i + 1; j < height.size(); j++){
//                 int width = j - i;
//                 int ht = min(height[i], height[j]);
//                 int currWater = width * ht;

//                 maxWater = max(maxWater,currWater);
//             }
//         }
//         return maxWater;
//     }
// };