# LeetCode Solutions

![C++](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=c%2B%2B)
![Python 3](https://img.shields.io/badge/Language-Python_3-3776AB?style=for-the-badge&logo=python)

A collection of LeetCode solutions in **C++** and **Python 3**, focused on clean code, optimal time complexity, and efficient space usage.

---

## 📁 Repository Structure

```text
LeetCode Solution/
├── C++/          # Solutions implemented in C++ (80+ solutions)
├── Python3/      # Solutions implemented in Python 3 (13+ solutions)
└── README.md     # Documentation and guide
```

---

## 🚀 How to Run Locally

Each file contains the standard LeetCode `Solution` class. To test a solution locally:

### 1. C++ Solutions

1. Open the desired file in `C++/` and add a driver `main()` function:
   ```cpp
   #include <iostream>

   int main() {
       Solution solution;
       // Call solution method with your test inputs
       return 0;
   }
   ```

2. Compile and run using any modern C++ compiler (C++17 / C++20):
   ```bash
   # Compile
   g++ -std=c++20 -O2 "C++/<filename>.cpp" -o solution

   # Run
   ./solution
   ```

---

### 2. Python 3 Solutions

1. Open the desired file in `Python3/` and add test invocation at the bottom:
   ```python
   if __name__ == "__main__":
       sol = Solution()
       # print(sol.methodName(args))
   ```

2. Run directly with Python 3:
   ```bash
   python3 "Python3/<filename>.py"
   ```
