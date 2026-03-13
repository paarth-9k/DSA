class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        long long rev = 0;
        long long temp = x;
        while(temp > 0)
        {
            int lastDigit = temp % 10;
            rev = rev * 10 + lastDigit;
            temp /= 10;
        }
        cout << rev;
        if(rev == x)
            return true;
        
        return false;
    }
};