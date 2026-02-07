class Solution {
public:
    bool checkRecord(string s) {
        if(s.find("LLL") != string::npos)
            return false;
        int act = 0;
        for(char c : s)
        {
            if(c == 'A')
            {
                act++;
            }
        }
        if(act >= 2)
            return false;
        
        return true;
    }
};