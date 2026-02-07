class Solution {
public:
    int minimumDeletions(string s) {
        int absum = 0;
        for(char c: s)
        {
            if(c == 'a')
                absum++;
        }
        if(absum == 0)
        {
            return 0;
        }
        int result = absum;
        for(char c : s)
        {
            if(c == 'a')
            {
                absum--;
            }
            else if(c == 'b')
            {
                absum++;
            }
            result = min(result, absum);
        }
        return result;
    }
};