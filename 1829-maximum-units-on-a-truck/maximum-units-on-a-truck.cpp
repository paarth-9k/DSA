class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // seperate 2d arr to map
        // sort them both descending order of numberof units
        sort(boxTypes.begin(), boxTypes.end(),
             [](auto& a, auto& b) { return a[1] > b[1]; });
        // start filling while dec the capacity and boxes

        int totalUnits = 0;
        for(auto &box : boxTypes)
        {
            int count = min(truckSize, box[0]);
            totalUnits += count * box[1];
            truckSize -= count;

            if(truckSize == 0)
                break;
        }
        return totalUnits;
        // if boxes 0 move
    }
};