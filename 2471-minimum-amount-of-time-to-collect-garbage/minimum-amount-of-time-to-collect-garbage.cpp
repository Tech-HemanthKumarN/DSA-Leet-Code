class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // p truck
        int pickP = 0;
        int travelP = 0;
        int lastHouseP = 0;
        // M truck
        int pickM = 0;
        int travelM = 0;
        int lastHouseM = 0;
        // G truck
        int pickG = 0;
        int travelG = 0;
        int lastHouseG = 0;

        // let's travel to the street of houses
        for (int i = 0; i < garbage.size(); i++) {
            // ith house

            string currHouse = garbage[i];

            // let dive into current house and see the type of garbage present
            for (int j = 0; j < currHouse.length(); j++) {
                char garbageType = currHouse[j];

                if (garbageType == 'P') {
                    pickP++;

                    // till here the 'p' truck is come, lets store it here
                    lastHouseP = i; // i will show current house index
                }
                if (garbageType == 'M') {
                    pickM++;
                    lastHouseM = i;
                }
                if (garbageType == 'G') {
                    pickG++;
                    lastHouseG = i;
                }
            }
        }
        // let's calculate travel time for P
        for (int i = 0; i < lastHouseP; i++) {
            travelP = travelP + travel[i];
        }

        // let's calculate travel time for M
        for (int i = 0; i < lastHouseM; i++) {
            travelM = travelM + travel[i];
        }
        // let's calculate travel time for G
        for (int i = 0; i < lastHouseG; i++) {
            travelG = travelG + travel[i];
        }

        int totalPickingTime = pickP + pickM + pickG;
        int totalTravelTime = travelP + travelM + travelG;

        int totalTime = totalPickingTime + totalTravelTime;
        return totalTime;
    }
};