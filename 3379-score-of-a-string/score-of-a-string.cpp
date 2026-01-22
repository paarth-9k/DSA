class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for(int i = 0; i < s.length() - 1; i++)
        {
            int x = (int)s[i];
            int y = (int)s[i+1];
            x = abs(x - y);
            score += x;
        }
        return score;
    }
};