# Binary Exponentiation | Fast Exponentiation | Detailed For Beginners

Binary Exponentiation, also known as Fast Exponentiation or Exponentiation by Squaring, is one of the most efficient algorithms for calculating large powers of the form $$a^b$$ in $$O(\log b)$$ time complexity[1][2]. This technique is essential for competitive programming and coding interviews, especially when dealing with large numbers or modular arithmetic[3].

## What is Binary Exponentiation?

Binary Exponentiation is a technique that allows us to compute $$a^n$$ using only $$O(\log n)$$ multiplications instead of the naive $$O(n)$$ approach[1]. The algorithm leverages the mathematical property that any number can be represented as a sum of powers of two based on its binary representation[4][5].

## Why Do We Need Binary Exponentiation?

The naive approach to calculate $$a^b$$ involves multiplying $$a$$ by itself $$b$$ times, resulting in $$O(b)$$ time complexity[2][4]. For example:
- To calculate $$2^{10}$$, we multiply 2 ten times
- To calculate $$2^{100000}$$, we would need 100,000 multiplications

This becomes extremely slow for large exponents, making binary exponentiation a crucial optimization[3].

## Mathematical Foundation

The core concept relies on basic mathematical properties[1][3]:

**For even exponents:**
$$ a^b = (a^{b/2})^2 $$

**For odd exponents:**
$$ a^b = a \times (a^{(b-1)/2})^2 $$

### Example Walkthrough

Let's trace through $$3^{13}$$[3]:
1. $$3^{13}$$ → Since 13 is odd: $$3 \times 3^{12}$$
2. $$3^{12}$$ → Since 12 is even: $$(3^6)^2$$
3. $$3^6$$ → Since 6 is even: $$(3^3)^2$$
4. $$3^3$$ → Since 3 is odd: $$3 \times 3^2$$
5. $$3^2$$ → Since 2 is even: $$(3^1)^2$$
6. $$3^1$$ → Base case reached

## C++ Implementation

### Recursive Approach

Here's the recursive implementation based on codestorywithMIK's explanation[3]:

```cpp
#include 
using namespace std;

// Recursive Binary Exponentiation
long long binaryExponentiation(long long a, long long b) {
    // Base case: a^0 = 1
    if (b == 0) {
        return 1;
    }
    
    // Calculate a^(b/2)
    long long half = binaryExponentiation(a, b / 2);
    
    // Square the result: (a^(b/2))^2
    long long result = half * half;
    
    // If b is odd, multiply by a once more
    if (b % 2 == 1) {
        result = result * a;
    }
    
    return result;
}

int main() {
    long long a = 3, b = 13;
    cout << a << " raised to power " << b << " is: " 
         << b

[1] https://cp-algorithms.com/algebra/binary-exp.html
[2] https://takeuforward.org/data-structure/calculate-the-power-of-a-number-binary-exponentiation/
[3] https://www.youtube.com/watch?v=D320QeHS0XQ
[4] https://www.scaler.com/topics/data-structures/binary-exponentiation/
[5] https://www.scaler.in/binary-exponentiation/
[6] https://www.youtube.com/watch?v=L-Wzglnm4dM
[7] https://www.youtube.com/watch?v=iCmOiItNS0k
[8] https://codegolf.stackexchange.com/questions/249463/implement-binary-exponentiation
[9] https://www.cs.uaf.edu/2015/spring/cs463/lecture/02_09_mul_exp.html
[10] https://github.com/Kumar-laxmi/Algorithms/blob/main/C++/Maths/Binary%20Exponentiation%20Algorithm.cpp
[11] https://www.youtube.com/watch?v=0iW3hubeYoI
[12] https://stackoverflow.com/questions/52940030/binary-exponentiation-in-c
[13] https://www.youtube.com/@codestorywithMIK/videos
[14] https://www.youtube.com/channel/UCaw58edcO3ZqMw76Bvs0kGQ/videos
[15] https://www.youtube.com/watch?v=K8mJ27S72v0
[16] https://www.youtube.com/watch?v=1TtWF2ZLNzk