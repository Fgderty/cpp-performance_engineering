# C++ Core Fundamentals & Performance Foundations

A collection of 44 solved programming exercises in C++. These tasks cover the fundamental building blocks required for systems programming and high-performance engineering: memory management, pointers, multidimensional arrays, and algorithmic logic.

## 📌 Project Context & Scope
The original textbook contained roughly 60 exercises across three chapters. However, **44 tasks were selected and solved**. 

*Why 44?* As an engineer, my goal was not to blindly complete every single exercise, but to master the underlying concepts. Tasks that were highly repetitive (e.g., multiple variations of basic console I/O or simple loops) were intentionally skipped to focus on complex topics that directly impact systems programming:
* Memory management and pointer arithmetic.
* Multidimensional arrays (matrix transposition, cyclic shifts).
* Implementing mathematical algorithms (Taylor series, Fibonacci).

This selective approach demonstrates the ability to prioritize learning objectives and focus on tasks that build a solid foundation for low-level optimization and performance engineering.

## 🛠️ Topics Covered
The exercises are organized by chapters and cover the following concepts:
* **Control Flow & Loops:** `for`, `while`, `do-while`, nested loops with complex termination conditions.
* **Functions & Parameters:** Passing by value, by pointer, and by reference.
* **Memory & Pointers:** Dynamic memory allocation, pointer arithmetic, and array decay.
* **Arrays & Matrices:** 1D and 2D arrays, transposition, cyclic shifts, and multi-dimensional data processing.
* **Math & Algorithms:** Fibonacci sequence, natural logarithms, sine/cosine approximations via Taylor series, and matrix operations.

## ⚙️ How to Build and Run
Ensure you have `g++` installed on your system.
To compile and run any specific task (e.g., a task from Chapter 1):
```bash
g++ -std=c++17 Chapter_1/Task_1.cpp -o Task_1
./Task_1
