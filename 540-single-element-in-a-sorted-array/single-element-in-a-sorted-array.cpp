class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;

        while (s <= e) {
            if (s == e) {
                // this is my single element
                return arr[s];
            }
            // duplicate element does not exist
            int leftValue = -1;
            int rightValue = -1;
            int currValue = arr[mid];

            if (mid - 1 >= 0) {
                leftValue = arr[mid - 1];
            }
            if (mid + 1 < n) {
                rightValue = arr[mid + 1];
            }

            // case 1:
            if (currValue != leftValue && currValue != rightValue) {
                return currValue;
            }

            // case 2: duplicate exist in left side
            if (currValue == leftValue && currValue != rightValue) {
                int pairStartingIndex = mid - 1;
                if (pairStartingIndex & 1) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            // case 3: duplicate exist in right side
            if (currValue == rightValue && currValue != leftValue) {
                int pairStartingIndex = mid;
                if (pairStartingIndex & 1) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            mid = s + (e - s) / 2;
        }
        return -1;
    }
};