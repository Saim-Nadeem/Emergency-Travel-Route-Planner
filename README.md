🚨 Emergency Travel Route Planner

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![C++](https://img.shields.io/badge/Built%20with-C++-blue.svg)](https://isocpp.org/)
[![Data Structures](https://img.shields.io/badge/Topic-Graphs%20%26%20BFS-green.svg)]()
[![Project](https://img.shields.io/badge/Project-CS2001%20Semester-blueviolet.svg)]()

A graph-based simulation for computing the **minimum days required** to reach the destination city during an emergency, considering road and aerial routes. Built using **C++** and graph traversal algorithms (BFS).

---

## 🚦 Problem Statement

- A traveler is required to reach the **last city** from the **first city (City 1)** as soon as possible due to an emergency.
- **Road travel:** Up to 6 cities per day.
- **Air travel:** Immediate transfer but **cannot revisit** previous cities via air.
- Avoid cycles caused by aerial routes.
- Minimize the number of days required to reach the destination.

---

## 🔍 Features

- 🌐 **Graph Representation** of cities and routes (road & air)
- 🧭 **BFS Traversal** to calculate shortest path under road/air constraints
- 🛫 **Air Route Handling** with avoidance of reverse/cyclic air jumps
- 📆 **Accurate Day Calculation** based on distance and travel type
- ✅ **Input Validation** to avoid invalid test cases

---

## 🏗️ Project Structure

```
├── main.cpp                    # Full C++ implementation
├── Project_Description.pdf     # Official problem statement and rubric
├── LICENSE                     # License file (MIT recommended)
└── README.md                   # Project documentation
```

---

## 📥 Input Format

```
First line: Number of test cases
For each test case:
    Line 1: Number of cities (N)
    Line 2: Number of aerial routes (k)
    Next k lines: Source and Destination cities for each aerial route
```

### 📤 Sample Input

```
2
30
5
2 21
4 7
10 25
19 28
26 0
98
3
5 29
35 23
24 95
```

### 📤 Sample Output

```
3
4
```

---

## 🧠 Algorithm Overview

- ✅ Graph is created with adjacency lists
- 🚗 Road links are auto-generated between consecutive cities (City *i* to *i+1*)
- 🛫 Aerial routes are added manually with special constraints
- 🔄 BFS is used to find the shortest path, while calculating travel time in **days**
  - 6 cities/day by road
  - 1 city/day if aerial route is used
- 🧮 A queue is used to reverse and reconstruct the shortest path
- ⏱️ Total days calculated based on cumulative travel conditions

---

## 📚 Technologies Used

| Component         | Tools          |
|------------------|----------------|
| Language          | C++            |
| Algorithm         | BFS            |
| Data Structures   | Linked Lists, Queues |
| Input Validation  | Manual checks  |

---

## 🧪 How to Run

### 1️⃣ Compile the Code

```bash
g++ main.cpp -o travel_planner
```

### 2️⃣ Run the Program

```bash
./travel_planner
```

> Follow the prompts to input test cases, cities, and aerial routes.

---

## ✅ Requirements Fulfilled (Based on Rubric)

- ✅ **Graph Creation:** Road + Aerial edges with city link visualization
- ✅ **BFS Traversal:** Optimized path-finding with cycle avoidance
- ✅ **Input Handling:** Robust string parsing and validation
- ✅ **Output Accuracy:** Days and shortest path clearly printed
- ✅ **Code Quality:** Structured, modular, and well-commented
- ✅ **Bonus:** Reverse queue usage to display city sequence

---

## 📈 Example Execution

```
Enter number of Test cases = 1
Test case 1
Enter number of cities = 30
Enter number of aerial_rootes = 2
2 21
4 7
Days = 3
Bonus (Displaying shortest path by name):
1 2 21 27 30
```

---

## 🔐 License

This project is licensed under the **MIT License**.  
See the [LICENSE](LICENSE) file for details.

---

## 🙌 Acknowledgments

- Developed as a part of **CS-2001 Data Structures** course at **FAST NUCES Islamabad**.
- Graph traversal logic inspired by classic **BFS shortest path** algorithm.
- Assignment inspired by real-world **emergency response routing** and time-constrained travel planning.


---

## 👤 Author

**Saim Nadeem**  
🔗 GitHub: [Saim-Nadeem](https://github.com/Saim-Nadeem)

---
