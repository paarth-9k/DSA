class Solution {
public:
    double myPow(double x, int n) {
        // Initialize result
        double ans = 1.0;
        // Convert n to long long to handle INT_MIN case
        long long nn = n; 
        // Make power positive, we'll handle negative power later
        if (nn < 0)
            nn = -1 * nn;
        
        // Binary exponentiation loop
        while (nn) {
            // If power is odd
            if (nn % 2) {
                ans = ans * x;    // Multiply x once and reduce power by 1
                nn = nn - 1;
            } else {
                x = x * x;        // Square the base
                nn = nn / 2;      // Reduce power by half
            }
        }
        
        // If original power was negative, take reciprocal
        if (n < 0)
            ans = 1.0 / ans;
        
        return ans;
    }
};