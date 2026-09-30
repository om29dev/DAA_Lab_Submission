# Assignment 6: Disaster Relief Resource Allocation (0/1 Knapsack)

This folder contains the implementation, output, and documentation for **Assignment No. 6: Disaster Relief Resource Allocation using 0/1 Knapsack Dynamic Programming**.

## Problem Overview

Following a natural disaster, a relief organization transports essential supplies using limited-capacity trucks (capacity $W$ kg). There are $N$ types of items with distinct weights and utility values. Using the **0/1 Knapsack dynamic programming paradigm**, the optimal item subset is selected in $O(N \cdot W)$ time and $O(N \cdot W)$ space to maximize total life-saving utility without exceeding truck capacity.

---

## Contents of this Folder

| File | Description |
| :--- | :--- |
| [`disaster_relief_knapsack.cpp`](./disaster_relief_knapsack.cpp) | Complete C++ implementation of 0/1 Knapsack dynamic programming |
| [`output.png`](./output.png) | Terminal execution output screenshot showing items selected, total utility, and capacity |
| [`124B1F001_DAA_Assignment_6_Disaster_Relief_Knapsack.pdf`](./124B1F001_DAA_Assignment_6_Disaster_Relief_Knapsack.pdf) | Complete lab report document formatted in institutional standard (PDF) |

---

## How to Compile & Run

```bash
# Compile
g++ disaster_relief_knapsack.cpp -o disaster_relief_knapsack

# Run
./disaster_relief_knapsack
```

---

## Student Details

- **Name**: Om Rajendra Bharambe
- **PRN**: 124B1F001
- **Branch**: Information Technology (IT), Batch A1
- **Course**: BIT25PC04 - Design & Analysis of Algorithms Laboratory
- **Guide**: Dr. Rajesh N. Phursule
