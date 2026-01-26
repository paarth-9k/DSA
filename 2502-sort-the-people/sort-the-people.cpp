class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<pair<int, string>> maxHeap;
        for(int i = 0; i < names.size(); i++)
            maxHeap.push({heights[i], names[i]});
        vector<string> result;
        while(!maxHeap.empty())
        {
            string name = maxHeap.top().second;
            result.push_back(name);
            maxHeap.pop();
        }
        return result;
    }
};