# Sorting Algorithms in C

This repository contains two C programs implementing classic sorting techniques:

- **Problem 1:** Bucket Sort for strings using ASCII-based bucketing
- **Problem 2:** Radix Sort for signed integers using hexadecimal bucketing

---

## Problem 1: Bucket Sort for Strings

This program implements a simple bucket sort for strings using the ASCII value of the first character of each string to determine its bucket placement.

### Features
- Accepts multiple strings from standard input.
- Uses an array of 128 buckets (for extended ASCII characters).
- Sorts each bucket using basic string comparison.
- Prints all strings in lexicographic order.

### How to Run
```bash
gcc 31586302_Problem1.c -o bucket_sort
./bucket_sort
