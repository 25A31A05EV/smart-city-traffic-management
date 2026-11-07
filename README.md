# 🚦 Smart City Traffic Management System

### Project 03 | Advanced Data Structures (ADS) | C++

A graph-based traffic management system that identifies efficient routes between city locations using shortest-path algorithms and data structures.

## 📌 Project Overview

Traffic congestion is a major challenge in modern cities. It causes delays, increases fuel consumption, and affects transportation efficiency.

The Smart City Traffic Management System demonstrates how graph algorithms can help identify efficient routes between different city locations.

This project uses **Dijkstra's Shortest Path Algorithm** to calculate minimum travel-time routes and **Breadth-First Search (BFS)** to explore road connectivity.

It also supports updating road travel times to simulate changing traffic conditions.

## 🎯 Objectives

- Represent city locations and roads using graph data structures.
- Find the shortest travel-time route between two locations.
- Explore road connectivity using BFS.
- Simulate traffic congestion by updating road weights.
- Demonstrate practical applications of graph algorithms.

## 🛠️ Technologies Used

| Technology | Purpose |
|---|---|
| C++ | Core programming language |
| C++17 | Language standard |
| Graph | City and road representation |
| Adjacency List | Graph representation |
| Priority Queue | Efficient shortest-path processing |
| Dijkstra's Algorithm | Shortest-path calculation |
| BFS | Graph traversal |
| HTML, CSS, JavaScript | Web-based prototype |
| Git & GitHub | Version control and collaboration |

## ⚙️ Key Features

1. **City Graph Representation:** Represents city locations as vertices and roads as weighted edges.
2. **Shortest Path Calculation:** Finds the minimum travel-time route using Dijkstra's algorithm.
3. **Traffic Simulation:** Updates road weights to represent traffic congestion.
4. **BFS Traversal:** Explores connected locations.
5. **Route Information:** Displays the selected route and estimated travel time.
6. **Web Prototype:** Provides a browser-based demonstration of the traffic management concept.

## 🧠 Algorithms and Data Structures

| Algorithm / Data Structure | Application |
|---|---|
| Graph | Represents city roads and locations |
| Adjacency List | Stores road connections |
| Priority Queue | Selects the minimum-distance vertex |
| Dijkstra's Algorithm | Finds the shortest travel-time path |
| Breadth-First Search | Traverses connected locations |

### Dijkstra's Algorithm – Working

1. Initialize the source location's distance as zero.
2. Set all other distances to infinity.
3. Insert the source into a min-priority queue.
4. Select the location with the minimum current distance.
5. Examine its adjacent roads.
6. Update distances when a shorter route is found.
7. Continue until the destination is processed.
8. Reconstruct and display the shortest route.

## 📂 Project Structure

```text
Smart_City_Traffic_Management/
│
├── src/
│   └── main.cpp
│
├── web/
│   └── index.html
│
├── docs/
│   ├── Project_Report.docx
│   ├── Project_Presentation.pptx
│   └── flowchart.mmd
│
├── tests/
│   └── test_cases.md
│
├── README.md
└── GITHUB_COMMITS.md
```

## ▶️ How to Run the Project

### Prerequisites

- C++ compiler (GCC / MinGW)
- C++17 support

### Step 1: Compile

```bash
g++ -std=c++17 -Wall -Wextra src/main.cpp -o traffic
```

### Step 2: Run on Windows

```bash
traffic.exe
```

### Run on Linux / macOS

```bash
./traffic
```

## 📊 Sample Demonstration

Example route:

**Central Station → Market Square → University → Airport**

Estimated travel time: **25 minutes**

*Note: The project uses illustrative sample road and travel-time data. It does not connect to live traffic sensors or real-time traffic APIs.*

## 🌍 Real-World Applications

- Smart city transportation systems
- GPS navigation applications
- Emergency vehicle route planning
- Road network analysis
- Traffic congestion simulation
- Logistics and delivery route optimization

## 🚀 Future Enhancements

- Integration with real-time traffic APIs.
- Dynamic traffic updates using live sensors.
- Emergency vehicle priority routing.
- Interactive city maps.
- Machine learning-based traffic prediction.
- Multiple-route comparison and optimization.

## 📑 Project Documentation

- [C++ Source Code](Smart_City_Traffic_Management/src/main.cpp)
- [Web Prototype](Smart_City_Traffic_Management/web/index.html)
- [Project Report](Smart_City_Traffic_Management/docs/Project_Report.docx)
- [Project Presentation](Smart_City_Traffic_Management/docs/Project_Presentation.pptx)
- [Flowchart](Smart_City_Traffic_Management/docs/flowchart.mmd)
- [Test Cases](Smart_City_Traffic_Management/tests/test_cases.md)

## 👥 Project Team

This project was collaboratively developed by:

1. **Sowmya Velugubantla**
2. **Shiny Hadassah**
3. **Mounika Surya**
4. **Sai Kiran**

**Department:** Computer Science and Engineering  
**College:** Pragati Engineering College  
**Subject:** Advanced Data Structures (ADS)

---

⭐ If you find this project useful, consider giving it a star!

**Project 03 | Team Project | C++ | Advanced Data Structures**
