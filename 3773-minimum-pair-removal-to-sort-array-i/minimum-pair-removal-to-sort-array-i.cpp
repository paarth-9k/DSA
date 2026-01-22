class Solution {
public:
    int minPair(vector<int> v) {
        int minsum = 1e9;
        int pos = -1;
        for (int i = 0; i < (int)v.size() - 1; i++) {
            if (v[i] + v[i + 1] < minsum) {
                minsum = v[i] + v[i + 1];
                pos = i;
            }
        }
        return pos;
    }
    void sumPair(vector<int> &v, int pos) {
        v[pos] += v[pos + 1];
        v.erase(v.begin() + pos + 1);
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while(!is_sorted(nums.begin(), nums.end()))
        {
            sumPair(nums, minPair(nums));
            ops++;
        }
        return ops;
    }
};