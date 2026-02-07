class Solution {
public:
    bool checkString(string s) {
        int bidx = 0;
        for(char c : s)
        {
            bidx++;
            if(c == 'b')
            {
               break; 
            } 
        }
        for(int i = bidx; i < s.length(); i++)
        {
            if(s[i] == 'a')
            {
                return false;
            }
        }
        return true;
    }
};