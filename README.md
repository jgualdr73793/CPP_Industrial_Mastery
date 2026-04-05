# 🛡️ Modern C++ Mastery: From Fundamentals to Industrial Architecture

Welcome to my C++ evolution repository. This project documents my journey from basic programming concepts to designing a robust, memory-safe, and scalable **Industrial Monitoring System**.

## 🚀 Project Overview

This repository is divided into two main sections:
1. **Learning Path:** Atomic examples of core C++ concepts.
2. **Final Project:** A professional-grade industrial plant simulator using Modern C++ (C++17).

---

## 📂 Repository Structure

```text
.
├── learning_path/           # Progressive learning modules
│   ├── 01_foundations.cpp   # Classes, Structs, and Encapsulation
│   ├── 02_polymorphism.cpp  # Inheritance and Virtual Functions
│   └── 03_modern_cpp.cpp    # Templates and Smart Pointers
├── final_project/           # The "Industrial Guardian" System
│   ├── include/             # Header files (.hpp)
│   ├── src/                 # Source files (.cpp)
│   ├── CMakeLists.txt       # Build system configuration
│   └── correr.bat           # Windows automation script
├── .gitignore               # Keeps the repo clean from build artifacts
└── README.md                # You are here!

```

## 🧠 Technical Milestones Achieved

### 1. Memory Safety & RAII
* **Eliminated manual memory management:** No more dangerous `new` or `delete` calls.
* **Smart Pointers:** Implemented `std::unique_ptr` to ensure automatic resource cleanup and zero memory leaks.

### 2. Advanced Architecture
* **Namespaces:** Organized code into logical groups (`IndustrialSystem`, `Controllers`) to avoid naming collisions.
* **Polymorphism:** Designed **Abstract Base Classes** (Interfaces) for specialized sensor behavior.
* **Generic Programming:** Leveraged **Templates** to create type-independent and reusable logic.

### 3. Error Resilience
* **Exception Handling:** Implemented a robust `try-catch-throw` system to prevent system crashes during critical hardware failures or invalid data input.

### 4. Professional Tooling
* **CMake:** Automated build process for cross-platform compatibility.
* **Clean Code:** Adhering to modern C++17 standards and professional naming conventions.

---

## 🛠️ How to Run the Project

### Prerequisites
* A C++17 compliant compiler (MSVC, GCC, or Clang).
* **CMake** (version 3.10 or higher) installed.

### Building and Running
If you are on Windows, you can use the provided automation script:
``` text
cd final_project
./correr.bat
```
Alternatively, use standard CMake commands:
``` text
mkdir build
cd build
cmake ..
cmake --build .
./Debug/main.exe
```
