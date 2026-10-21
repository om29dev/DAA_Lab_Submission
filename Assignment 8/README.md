# Assignment 8: Optimizing Delivery Routes for a Logistics Company (TSP - Least Cost Branch & Bound)

This folder contains the implementation, output, and documentation for **Assignment No. 8: Optimizing Delivery Routes for a Logistics Company (TSP - Least Cost Branch & Bound)**.

## Problem Overview

A leading logistics company, SwiftShip, is responsible for delivering packages to multiple cities. To minimize fuel costs and delivery time, the company needs to find the shortest possible route that allows a delivery truck to visit each city exactly once and return to the starting point. The problem is modeled as the Travelling Salesman Problem (TSP) on an $N \times N$ cost matrix. Since a brute-force search checking all $(N-1)!$ permutations is computationally infeasible for large $N$, the solution implements an LC (Least Cost) Branch and Bound algorithm utilizing matrix reduction lower bounds and a min-heap priority queue to prune suboptimal search branches.

---

## Contents of this Folder

| File | Description |
| :--- | :--- |
| [`swiftship_delivery.cpp`](./swiftship_delivery.cpp) | Complete C++ implementation of LC Branch and Bound for TSP delivery route optimization |
| [`output.png`](./output.png) | Terminal execution output screenshot showing cost matrix input and optimal delivery route |
| [`124B1F001_DAA_Assignment_8_Optimizing_Delivery_Routes_TSP.pdf`](./124B1F001_DAA_Assignment_8_Optimizing_Delivery_Routes_TSP.pdf) | Complete lab report document formatted in institutional standard (PDF) |

---

## How to Compile & Run

```bash
# Compile
g++ swiftship_delivery.cpp -o swiftship_delivery

# Run
./swiftship_delivery
```

### Sample Input & Output
```text
SwiftShip Delivery Route Optimization
------------------------------------
Enter the number of cities: 4

Enter the cost matrix (4 x 4):
Enter 0 for the distance from a city to itself.
Enter costs from City 0: 0 10 15 20
Enter costs from City 1: 10 0 35 25
Enter costs from City 2: 15 35 0 30
Enter costs from City 3: 20 25 30 0

----------- Optimal Route -----------
Minimum Delivery Cost: 80
Optimal Route: City 0 -> City 1 -> City 3 -> City 2 -> City 0
-------------------------------------
```

---

## Student Details

- **Name**: Om Rajendra Bharambe
- **PRN**: 124B1F001
- **Branch**: Information Technology (IT), Batch A1
- **Course**: BIT25PC04 - Design & Analysis of Algorithms Laboratory
- **Guide**: Dr. Rajesh N. Phursule

