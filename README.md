# LeetCode Solutions

A collection of C++ solutions to LeetCode problems, focused on clean code, optimal time complexity, and efficient space usage.

## How to Run Locally

Each file contains the standard LeetCode `Solution` class. To test a solution locally:

1. Open the desired file and add a simple `main()` driver function:

   ```cpp
   #include <iostream>

   int main() {
       Solution solution;
       // Call solution method with your test inputs
       return 0;
   }
   ```

2. Compile and execute using any modern C++ compiler (C++17 / C++20):

   ```bash
   # Compile
   g++ -std=c++20 -O2 "<filename>.cpp" -o solution

   # Run
   ./solution
   ```
