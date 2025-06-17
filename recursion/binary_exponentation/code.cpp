#include <iostream>
using namespace std;

// Recursive Binary Exponentiation
long long binaryExponentiation(long long a, long long b)
{
    // Base case: a^0 = 1
    if (b == 0)
    {
        return 1;
    }

    // Calculate a^(b/2)
    long long half = binaryExponentiation(a, b / 2);

    // Square the result: (a^(b/2))^2
    long long result = half * half;//usually A M (Modulo value) is given

    // If b is odd, multiply by a once more
    if (b % 2 == 1)
    {
        result = result * a;
    }

    return result;
}
