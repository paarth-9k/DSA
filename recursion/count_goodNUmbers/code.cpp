class Solution {
public:
    const int M = 1e9 + 7;
    long long pow(long long x, long long y) {
        if (y == 0)
            return 1;
        long long half = pow(x, y / 2);
        long long result = (half * half) % M;
        if (y % 2)
            result = (result * x) % M;
        return result;
    }

    int countGoodNumbers(long long n) {
        return (pow(5, (n + 1) / 2) * pow(4, (n) / 2)) % M;
    }
};