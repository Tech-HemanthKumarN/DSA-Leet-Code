class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWater = 0;
        int lp = 0;
        int rp = n - 1;

        while (lp < rp) {
            int wd = rp - lp;
            int ht = min(height[lp], height[rp]);
            int currWater = wd * ht;
            maxWater = max(maxWater, currWater);
            // if(height[lp] < height[rp]){
            //     lp++;
            // }
            // else{
            //     rp--;
            // }

            //or 
            
            height[lp] < height[rp] ? lp++ : rp--;
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