Solving recursion problems in C++ (or any language) involves a structured approach. Here's a **step-by-step guide** to help you master it:

---

### 🔁 **What is Recursion?**

A function that calls itself to solve smaller instances of the same problem.

---

### 🧩 **Steps to Solve Recursion Problems**

#### 1. **Understand the Problem**

* Can it be broken into smaller sub-problems?
* Is the same logic applied to the sub-parts?
* Example: Factorial, Fibonacci, Tower of Hanoi.

#### 2. **Identify the Base Case**

* This is where the recursion stops.
* **Example (Factorial):** `if (n == 0) return 1;`

#### 3. **Write the Recursive Case**

* Reduce the problem size.
* **Example:** `return n * factorial(n - 1);`

#### 4. **Make Sure It Moves Toward the Base Case**

* Every recursive call should bring you closer to the base case.

#### 5. **Dry Run Your Code (Trace Recursion Tree)**

* Follow function calls manually for small inputs to check logic.

---

### 🔧 **Example Problems and Patterns**

#### ✅ **1. Factorial**

```cpp
int factorial(int n) {
    if (n == 0) return 1;              // base case
    return n * factorial(n - 1);       // recursive case
}
```

#### ✅ **2. Fibonacci**

```cpp
int fib(int n) {
    if (n == 0) return 0;              // base case 1
    if (n == 1) return 1;              // base case 2
    return fib(n - 1) + fib(n - 2);    // recursive case
}
```

#### ✅ **3. Sum of Digits**

```cpp
int sumDigits(int n) {
    if (n == 0) return 0;
    return n % 10 + sumDigits(n / 10);
}
```

#### ✅ **4. Print Numbers from N to 1**

```cpp
void print(int n) {
    if (n == 0) return;
    cout << n << " ";
    print(n - 1);
}
```

---

### ⚠️ Common Mistakes

* Forgetting the base case → leads to infinite recursion
* Not reducing problem size → same issue
* Stack overflow → use iteration or memoization if recursion is deep

---

### 🔁 Tip: Convert to Iteration if Needed

If recursion is inefficient, consider converting to a loop or using **dynamic programming (memoization)**.

---

### 🧠 Practice Pattern-Based Problems

1. Backtracking → N-Queens, Sudoku
2. Divide & Conquer → Merge Sort, Binary Search
3. Tree recursion → Tree traversal, DFS
4. Combinatorics → Subsets, Permutations

---
