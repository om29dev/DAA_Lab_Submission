# Assignment 7: University Timetable Scheduling (Graph Colouring)

This folder contains the implementation, output, and documentation for **Assignment No. 7: University Exam Timetable Scheduling using Graph Colouring**.

## Problem Overview

A university faces scheduling clashes when students are enrolled in multiple courses simultaneously. The problem is modeled as an undirected conflict graph $G = (V, E)$, where courses represent vertices and shared students form edges. Graph Colouring (Welsh-Powell degree-ordered Greedy heuristic) assigns conflict-free exam time slots (colors) minimizing total slots, followed by classroom allocation matching student counts to room capacities.

---

## Contents of this Folder

| File | Description |
| :--- | :--- |
| [`exam_timetable_graph_colouring.cpp`](./exam_timetable_graph_colouring.cpp) | Complete C++ implementation of graph colouring and room allocation |
| [`output.png`](./output.png) | Terminal execution output screenshot showing conflict-free exam slots and room assignment |
| [`124B1F001_DAA_Assignment_7_University_Timetable_Scheduling.pdf`](./124B1F001_DAA_Assignment_7_University_Timetable_Scheduling.pdf) | Complete lab report document formatted in institutional standard (PDF) |

---

## How to Compile & Run

```bash
# Compile
g++ exam_timetable_graph_colouring.cpp -o exam_timetable_graph_colouring

# Run
./exam_timetable_graph_colouring
```

---

## Student Details

- **Name**: Om Rajendra Bharambe
- **PRN**: 124B1F001
- **Branch**: Information Technology (IT), Batch A1
- **Course**: BIT25PC04 - Design & Analysis of Algorithms Laboratory
- **Guide**: Dr. Rajesh N. Phursule
