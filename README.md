# Custom Forward List (C++ Implementation) 🔗

A high-performance, custom implementation of the _ `std::forward_list_ ` container. This project demonstrates advanced C++ concepts including manual memory management, template programming, and move semantics.

## ✨ Features

- `Complete Life Cycle* `: Full support for Rule of 5 (Copy/Move constructors and assignment operators).
- `Efficient Memory Management* `: Custom destructor and `clear()` methods to prevent memory leaks.
- `Rich API* `: Includes standard methods for insertion, deletion, and sequence manipulation.
- `Advanced Sorting* `: Implementation of sorting and merging algorithms specifically for linked structures.
- `Operator Overloading* `: Comprehensive set of operators for comparison, assignment, and stream output.

## 🛠 Tech Stack

- `Language`: C++11 and higher
- `Concepts`: Dynamic Memory Allocation, Template Classes, Move Semantics, Linked Data Structures.

## 📖 API Reference

**Constructors & Big Five**
|Type | Status|
| :--- | :--- |
|**TypeStatusDefault Constructor** | ✅ Implemented |
|**Parameterized (std::initializer_list)** | ✅ Implemented |
|**Copy Constructor / Assignment** | ✅ Implemented |
|**Move Constructor / Assignmen**t |✅ Implemented |
|**Destructor** | ✅ Implemented |

## Key Methods

- `push_front()` / `pop_front()` — Standard stack-like operations.
- `insert()` / `erase()` / `emplace()` — Positional element management.
- `reverse()` — In-place reversal of the list nodes.
- `sort()` — Efficiently organizes elements.
- `remove_if()` — Conditional element deletion using predicates.

## Overloaded Operators

- **Comparison**: `==,` `!=`, `<`, `>`, `<=`, `>=`
- **Arithmetic/Logic**: `+`, `+=`
- **Output**: `<<` (direct integration with `std::cout`)

## 🚀 Usage Example

```cpp
  #include "forward_list.hpp"
  #include <iostream>

  int main() {
      // Initialization with list
      ForwardList<int> list = {3, 1, 4, 1, 5};

      list.push_back(9);
      list.sort();

      std::cout << list << std::endl; // Output: 1 1 3 4 5 9
      return 0;
  }
```

## 📁 Project Structure
* `forward_list.hpp` — Main template class definition.
* `forward_list_constructors.hpp` — Logic for all construction types.
* `forward_list_methods.hpp` — Core functionality (sort, reverse, etc.).
* `forward_list_operators.hpp` — Implementation of overloaded operators.
* `Makefile` — Build system for easy compilation.