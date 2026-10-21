# Assignment 1: Merge Sort

This folder contains the implementation, test output, and complete documentation for **Assignment No. 1: Customer Order Sorting using Merge Sort**.

## Problem Overview

Arrange customer orders efficiently based on order timestamps using the **Merge Sort** (Divide and Conquer) algorithm to handle large datasets (up to 1,000,000 records) with $O(n \log n)$ time complexity and minimal overhead.

---

## Contents of this Folder

| File | Description |
| :--- | :--- |
| [`customer_order_merge_sort.cpp`](./customer_order_merge_sort.cpp) | Complete C++ implementation of Merge Sort with CSV dataset parsing and timestamp ordering |
| [`customer_orders.csv`](./customer_orders.csv) | E-commerce customer orders dataset containing order IDs, customer IDs, statuses, and purchase timestamps |
| [`output.png`](./output.png) | Terminal execution output screenshot showing sorted customer order records |
| [`124B1F001_DAA_Assignment_1_Merge_Sort.pdf`](./124B1F001_DAA_Assignment_1_Merge_Sort.pdf) | Complete lab report document formatted in institutional standard (PDF) |

---

## Repository Links

- **Main Repository**: [om29dev/DAA_Lab_Submission](https://github.com/om29dev/DAA_Lab_Submission)
- **Assignment 1 Folder**: [Assignment 1 on GitHub](https://github.com/om29dev/DAA_Lab_Submission/tree/main/Assignment%201)

---

## How to Compile & Run

```bash
# Compile
g++ -O2 customer_order_merge_sort.cpp -o customer_order_merge_sort

# Run
./customer_order_merge_sort
```

The program automatically reads and parses [`customer_orders.csv`](./customer_orders.csv) located in the current working directory. The dataset schema includes:

```text
order_id,customer_id,order_status,order_purchase_timestamp,order_approved_at,...
```

The timestamps follow the standard ISO format (`YYYY-MM-DD HH:MM:SS`) and are sorted in chronological ascending order using Merge Sort ($O(n \log n)$). The top sorted records and total order counts are displayed in tabular format.

---

## Student Details

- **Name**: Om Rajendra Bharambe
- **PRN**: 124B1F001
- **Branch**: Information Technology (IT), Batch A1
- **Course**: BIT25PC04 - Design & Analysis of Algorithms Laboratory
- **Guide**: Dr. Rajesh N. Phursule
