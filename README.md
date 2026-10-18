# Sorting Algorithm Analysis

Algorithm Analysis Course — Midterm Assignment  


## Project Structure

```
SortingAlgorithms/
├── README.md              # This file
├── REPORT.md              # Detailed project report
└── src/
    ├── selection_sort.c   # Selection Sort implementation with benchmarks
    └── bubble_sort.c      # Bubble Sort implementation with benchmarks
```

## Selected Algorithms

1. **Selection Sort** — Simple comparison-based sort that minimizes swaps
2. **Bubble Sort** — Adjacent-swap sort with early-exit optimization

## How to Build and Run

### Prerequisites
- GCC compiler (or any standard C compiler)

### Compile
```bash
gcc -O2 -o selection_sort src/selection_sort.c
gcc -O2 -o bubble_sort src/bubble_sort.c
```

### Run
```bash
./selection_sort
./bubble_sort
```

## Quick Complexity Summary

| Algorithm      | Best     | Average  | Worst    | Space | Stable |
|----------------|----------|----------|----------|-------|--------|
| Selection Sort | O(n²)   | O(n²)   | O(n²)   | O(1)  | No     |
| Bubble Sort    | O(n)    | O(n²)   | O(n²)   | O(1)  | Yes    |

