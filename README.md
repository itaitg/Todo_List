# Todo List (C++)

A simple command-line **Todo List Manager** written in modern C++.
This project allows users to create, manage, and persist tasks using JSON for storage.

---

## ✨ Features

* Add new tasks with unique IDs
* Mark tasks as completed
* Separate lists for active and finished tasks
* Save and load tasks to/from a JSON file
* Simple command-line interface (CLI) for interaction

---

## 🛠️ Technologies

* **C++17/20**
* [nlohmann/json](https://github.com/nlohmann/json) for JSON serialization
* Standard Template Library (STL)

---

## 📂 Project Structure

```
Todo_List/
├── include/         # Header files
│   ├── Manager.h
│   └── Task.h
├── src/             # Source files
│   ├── main.cpp
│   ├── Manager.cpp
│   └── Task.cpp
├── test.json        # Example saved tasks
└── CMakeLists.txt   # Build configuration
```

---

## 🚀 Getting Started

### Prerequisites

* A C++17 (or later) compiler
* [CMake](https://cmake.org/)
* Git

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/itaitg/Todo_List.git
cd Todo_List

# Create build directory
mkdir build && cd build

# Run CMake and build
cmake ..
make
```

### Run

```bash
./Todo_List
```

---

## 📖 Usage

When you run the program, you can:

1. Add tasks with a description
2. View active and completed tasks
3. Mark tasks as finished
4. Save/Load tasks automatically from `test.json`

---

## 💡 Future Improvements

* Due dates and priorities
* Edit and delete tasks
* Tagging/categorization
* GUI (Qt or ImGui)
* Unit tests

---

## 📜 License

This project is open-source and available under the MIT License.
