# Assignment 5: Multistage Graph (Dynamic Programming)

This folder contains the implementation, output, and documentation for **Assignment No. 5: Multistage Graph - SwiftCargo Delivery Route Optimization using Dynamic Programming**.

## Problem Overview

A logistics company, SwiftCargo, specializes in delivering packages across multiple cities. The transportation network is partitioned into multiple stages (warehouses, transit hubs, and final delivery points). Each package must follow the most cost-efficient route from the source to the destination passing through predefined stages.

Using **Backward Dynamic Programming**, optimal routes are calculated in $O(V + E)$ time and $O(V)$ auxiliary space.

---

## Contents of this Folder

| File | Description |
| :--- | :--- |
| [`multistage_graph_dp.cpp`](./multistage_graph_dp.cpp) | Complete C++ implementation of backward multistage graph dynamic programming |
| [`output.png`](./output.png) | Terminal execution output screenshot showing route traversal and minimal cost |
| [`124B1F001_DAA_Assignment_5_Multistage_Graph.pdf`](./124B1F001_DAA_Assignment_5_Multistage_Graph.pdf) | Complete lab report document formatted in institutional standard (PDF) |

---

## How to Compile & Run

```bash
# Compile
g++ multistage_graph_dp.cpp -o multistage_graph_dp

# Run
./multistage_graph_dp
```

---

## Student Details

- **Name**: Om Rajendra Bharambe
- **PRN**: 124B1F001
- **Branch**: Information Technology (IT), Batch A1
- **Course**: BIT25PC04 - Design & Analysis of Algorithms Laboratory
- **Guide**: Dr. Rajesh N. Phursule
