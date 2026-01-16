class Solution {
public:
    bool judgeCircle(string moves) {
        int h = 0, v = 0;
        if(moves.empty())
            return true;
        for(char c : moves)
        {
            if(c == 'L')
            {
                h--;
            }
            else if(c == 'R')
            {
                h++;
            }
            else if(c == 'U')
            {
                v++;
            }
            else if(c == 'D')
            {
                v--;
            }
        }
        if(h == 0 && v == 0)
            return true;
        return false;
    }
};