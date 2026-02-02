class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        multiset<pair<int,int>> small, large;
        long long curr = 0;

        // initial window: indices [1 .. dist+1]
        for (int i = 1; i <= dist + 1; i++) {
            small.insert({nums[i], i});
        }

        // keep only k-1 smallest in small
        while ((int)small.size() >= k) {
            auto it = prev(small.end());   // largest in small
            large.insert(*it);
            small.erase(it);
        }

        // compute initial sum
        for (auto &p : small) curr += p.first;
        long long res = curr;

        // sliding window
        for (int i = dist + 2; i < n; i++) {
            pair<int,int> pkey = {nums[i - dist - 1], i - dist - 1};
            pair<int,int> nkey = {nums[i], i};

            // remove left
            if (small.count(pkey)) {
                small.erase(small.find(pkey));
                curr -= pkey.first;

                if (!large.empty()) {
                    auto it = large.begin();   // smallest in large
                    small.insert(*it);
                    curr += it->first;
                    large.erase(it);
                }
            } else {
                large.erase(large.find(pkey));
            }

            // add right
            small.insert(nkey);
            curr += nkey.first;

            if ((int)small.size() >= k) {
                auto it = prev(small.end());   // largest in small
                curr -= it->first;
                large.insert(*it);
                small.erase(it);
            }

            res = min(res, curr);
        }

        // add nums[0] cost
        return res + nums[0];
    }
};