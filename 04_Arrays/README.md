# Arrays

This folder contains hands-on C array practice for the `Embedded C Deep Dive` repository.

The goal of this module is to build confidence with:
- array declaration and initialization
- indexing and traversal
- array size calculation using `sizeof`
- array memory basics and pointer-style access
- common array problem-solving patterns used in C and Embedded Systems

## Why Arrays Matter in Embedded C

Arrays are one of the most important building blocks in Embedded C because they are used to store:
- sensor readings
- ADC samples
- UART buffers
- lookup tables
- GPIO state values
- small blocks of fixed-size data

Understanding arrays well also makes pointers, strings, buffers, and memory handling much easier later.

## Practice Files

1. `01_array_declaration.c`
   Basics of declaring an array, reading values using a loop, and printing them safely.

2. `02_array_declaration_variants.c`
   Different styles of array declaration and initialization, including partial initialization, character arrays, strings, and a basic 2D array.

3. `03_array_element_manipulation.c`
   Reading, updating, incrementing, decrementing, swapping, reversing, copying, resetting, and pointer-style element access.

4. `04_array_traversal_patterns.c`
   Forward traversal, reverse traversal, partial traversal, and selected-index traversal patterns.

5. `05_array_size_calculation.c`
   Using `sizeof(array) / sizeof(array[0])` to find the element count and avoid hardcoding loop limits.

6. `06_array_memory_basics.c`
   Array addresses, element addresses, pointer arithmetic, and the relationship between `a`, `&a[0]`, and `&a`.

7. `07_sum_avg_min_max.c`
   Basic aggregate operations such as sum, average, minimum, and maximum.

8. `08_search_elements.c`
   Linear search to find whether an element exists in an array.

9. `09_reverse_array.c`
   In-place array reversal using two indices.

10. `10_count_occurrences.c`
    Counting how many times a value appears in an array.

11. `11_rotation_right.c`
    Right rotation by one position and by `k` positions.

12. `12_second_largest.c`
    Finding the largest and second-largest elements.

13. `13_remove_duplicate_elements.c`
    Practice attempt for removing duplicate values from an array.

14. `14_bubble_sort.c`
    Practice implementation of bubble sort in ascending order.

## Key Takeaways

- Array indexing starts from `0`
- Valid indices go from `0` to `size - 1`
- Accessing outside array bounds causes undefined behavior
- Local arrays should be initialized before use
- `a[i]` and `*(a + i)` refer to the same element
- `sizeof(array) / sizeof(array[0])` is the standard way to calculate element count in the same scope