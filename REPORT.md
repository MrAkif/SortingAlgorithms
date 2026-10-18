# Sorting Algorithm Analysis — Project Report

**Course:** Algorithm Analysis  
**Lecturer:** Dr. Coşkun Şahin  
**Student Name:** ………………………………  
**Student Number:** ………………………………  
**Date:** October 2026  

---

## 1. Introduction

This report analyzes two sorting algorithms: **Selection Sort** and **Bubble Sort**. For each algorithm, we explain how it works, analyze its time and space complexity, and compare them.

---

## 2. Selection Sort

### How It Works

Selection Sort divides the array into sorted and unsorted parts. Each step, it finds the **minimum** element from the unsorted part and swaps it to the end of the sorted part.

```
SELECTION-SORT(A, n)
    for i = 0 to n-2
        minIdx = i
        for j = i+1 to n-1
            if A[j] < A[minIdx]
                minIdx = j
        swap A[i] and A[minIdx]
```

### Example

Sorting `[64, 25, 12, 22, 11]`:

| Step | Action | Result |
|------|--------|--------|
| 1 | Min=11, swap with 64 | [11, 25, 12, 22, 64] |
| 2 | Min=12, swap with 25 | [11, 12, 25, 22, 64] |
| 3 | Min=22, swap with 25 | [11, 12, 22, 25, 64] |
| 4 | Already in place | [11, 12, 22, 25, 64] ✓ |

### Complexity Analysis

**Time Complexity:**

The inner loop always runs n(n-1)/2 times, regardless of input order.

| Case | Time | Explanation |
|------|------|-------------|
| Best | O(n²) | Still scans entire unsorted part even if sorted |
| Average | O(n²) | Same number of comparisons |
| Worst | O(n²) | Same number of comparisons |

**Space Complexity:** O(1) — only uses a few extra variables (temp, minIdx).

**Swap count:** At most n-1 swaps (very few writes).

**Stable:** No — swapping can change the order of equal elements.

### Benchmark Results

| n | Best (s) | Worst (s) | Random (s) |
|---|----------|-----------|------------|
| 1,000 | 0.001 | 0.000 | 0.001 |
| 5,000 | 0.022 | 0.022 | 0.022 |
| 10,000 | 0.087 | 0.087 | 0.088 |
| 20,000 | 0.344 | 0.344 | 0.351 |

> All three cases have nearly identical times → confirms O(n²) always.

---

## 3. Bubble Sort

### How It Works

Bubble Sort compares **adjacent elements** and swaps them if they are in wrong order. After each pass, the largest unsorted element "bubbles" to the end. With the **early-exit optimization**, if no swaps happen in a pass, the array is sorted and we stop.

```
BUBBLE-SORT(A, n)
    for i = 0 to n-2
        swapped = false
        for j = 0 to n-2-i
            if A[j] > A[j+1]
                swap A[j] and A[j+1]
                swapped = true
        if not swapped
            break
```

### Example

Sorting `[5, 3, 8, 4, 2]`:

| Pass | Comparisons & Swaps | Result |
|------|---------------------|--------|
| 1 | 5↔3, 8↔4, 8↔2 | [3, 5, 4, 2, **8**] |
| 2 | 5↔4, 5↔2 | [3, 4, 2, **5**, 8] |
| 3 | 4↔2 | [3, 2, **4**, 5, 8] |
| 4 | 3↔2 | [**2**, 3, 4, 5, 8] ✓ |

### Complexity Analysis

**Time Complexity:**

| Case | Time | Explanation |
|------|------|-------------|
| Best | O(n) | Already sorted → 1 pass, no swaps, exits early |
| Average | O(n²) | Roughly half the pairs need swapping |
| Worst | O(n²) | Reverse sorted → every pair swaps, no early exit |

**Space Complexity:** O(1) — only uses a few extra variables (temp, swapped).

**Stable:** Yes — only swaps adjacent elements when strictly out of order.

### Benchmark Results

| n | Best (s) | Worst (s) | Random (s) |
|---|----------|-----------|------------|
| 1,000 | 0.000 | 0.000 | 0.001 |
| 5,000 | 0.000 | 0.014 | 0.019 |
| 10,000 | 0.000 | 0.057 | 0.101 |
| 20,000 | 0.000 | 0.218 | 0.463 |

> Best case stays 0.000s → confirms O(n). Worst/average grow quadratically.

---

## 4. Comparison

| | Selection Sort | Bubble Sort |
|---|---|---|
| **Best Case** | O(n²) | **O(n)** ✅ |
| **Average Case** | O(n²) | O(n²) |
| **Worst Case** | O(n²) | O(n²) |
| **Space** | O(1) | O(1) |
| **Stable** | ❌ No | ✅ Yes |
| **Adaptive** | ❌ No | ✅ Yes |
| **Swaps (worst)** | **O(n)** ✅ | O(n²) |

### When to Use Which?

- **Selection Sort:** When writes/swaps are expensive (e.g., flash memory), because it does at most n-1 swaps.
- **Bubble Sort:** When data is already nearly sorted, because it can finish in O(n).
- **Neither:** For large data — use Quick Sort, Merge Sort, or Heap Sort instead.

---

## 5. Conclusion

Both algorithms are O(n²) on average, making them impractical for large datasets. However, they each have a unique strength: Selection Sort minimizes swaps, while Bubble Sort can detect sorted data and finish early. Understanding these trade-offs is the foundation for appreciating more advanced algorithms.

---

## 6. References

1. Cormen, T. H. et al. *Introduction to Algorithms* (4th ed.). MIT Press, 2022.
2. Sedgewick, R. & Wayne, K. *Algorithms* (4th ed.). Addison-Wesley, 2011.

---

## 7. AI Usage Statement

"Claude (Anthropic, Claude Opus 4.6 Thinking) was used in the [Code Generation, Documentation, and Report Writing] section of this product. The tool was utilized via the prompt 'Help create sorting algorithm implementations and project report for Algorithm Analysis course assignment' for the purpose of code generation, algorithm analysis, documentation, and text structuring. The output generated has been reviewed and verified by me for technical accuracy, safety, and originality. I bear full responsibility for the work."
