class Solution {
public:
    int maxDistinct(string s) {
        set<char> sett(s.begin(), s.end());
        return sett.size();
    }
};