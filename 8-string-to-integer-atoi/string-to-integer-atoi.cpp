class Solution {
public:
    int helper(string &s, int i, long long num, int sign) {
        // Base case: stop if out of bounds or not a digit
        if (i >= s.size() || !isdigit(s[i]))
            return (int)(sign * num);

        int digit = s[i] - '0';

        // Check overflow before adding digit
        if (num > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        num = num * 10 + digit;

        // Recursive call for next character
        return helper(s, i + 1, num, sign);
    }

    int myAtoi(string s) {
        int i = 0;
        int n = s.size();

        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Start recursion from first digit
        return helper(s, i, 0, sign);
    }
};
