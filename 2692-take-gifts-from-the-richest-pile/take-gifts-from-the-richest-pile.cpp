class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum = 0;
        priority_queue<int> maxh;
        for(int i = 0; i < gifts.size(); i++)
        {
            maxh.push(gifts[i]);
        }
        for(int i = 0; i < k; i++)
        {
            int value = maxh.top();
            value = sqrt(value);
            maxh.pop();
            maxh.push(value);
        }
        
        for(int i = 0; i < gifts.size(); i++)
        {
            sum += maxh.top();
            maxh.pop();
        }
        return sum;
    }
};