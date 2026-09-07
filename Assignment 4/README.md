# Assignment 4: Dijkstra's Algorithm

This folder contains the implementation, test output, and complete documentation for **Assignment No. 4: Smart City Emergency Response System using Dijkstra's Algorithm**.

## Problem Overview

In a smart city infrastructure, ambulances must navigate road networks to reach the nearest hospital in the minimum possible travel time. Road networks are modeled as weighted graphs $G = (V, E)$, where intersections represent vertices and edges represent roads with weights indicating real-time travel times based on traffic congestion.

Using **Dijkstra's Algorithm** with a priority queue (min-heap), the system dynamically computes the shortest travel-time path from the ambulance's initial location (source node $S$) to the nearest hospital in $O((V + E) \log V)$ time complexity, and adapts to real-time traffic updates.

---

## Contents of this Folder

| File | Description |
| :--- | :--- |
| [`nearest_hospital_dijkstra.cpp`](./nearest_hospital_dijkstra.cpp) | Complete C++ implementation of Dijkstra's algorithm for nearest hospital routing |
| [`output.png`](./output.png) | Terminal execution output screenshot showing shortest travel time and optimal routing |
| [`124B1F001_DAA_Assignment_4_Dijkstra_Algorithm.pdf`](./124B1F001_DAA_Assignment_4_Dijkstra_Algorithm.pdf) | Complete lab report document formatted in institutional standard (PDF) |

---

## Repository Links

- **Main Repository**: [om29dev/DAA_Lab_Submission](https://github.com/om29dev/DAA_Lab_Submission)
- **Assignment 4 Folder**: [Assignment 4 on GitHub](https://github.com/om29dev/DAA_Lab_Submission/tree/main/Assignment%204)

---

## How to Compile & Run

```bash
# Compile
g++ nearest_hospital_dijkstra.cpp -o nearest_hospital_dijkstra

# Run
./nearest_hospital_dijkstra
```

---

## Student Details

- **Name**: Om Rajendra Bharambe
- **PRN**: 124B1F001
- **Branch**: Information Technology (IT), Batch A1
- **Course**: BIT25PC04 - Design & Analysis of Algorithms Laboratory
- **Guide**: Dr. Rajesh N. Phursule
