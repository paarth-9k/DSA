class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        while(s != "1")
        {
            //even
            if(s.back() == '0')
            {
                s.pop_back();
            }
            else if(s.back() == '1')
            {
                int n = s.size() - 1;
                while(n >= 0 && s[n] == '1')
                {
                    s[n] = '0';
                    n--;
                }
                if(n >= 0)
                {
                    s[n] = '1';
                }
                else{
                    s = "1" + s;
                }
            }
            steps++;
        }
        return steps;
    }
};