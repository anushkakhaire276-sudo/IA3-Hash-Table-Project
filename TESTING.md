
# Testing and Verification

## Test Configuration

PRN: 202501100053
Dataset size: 20
Hash table size: 23

## Verification

The program was compiled using:

g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o hash_table

The program was executed and its output was checked.

## Test Cases

| Test | Input | Expected behaviour |
|---|---|---|
| 1 | 53 | Bucket 11 |
| 2 | 66 | Bucket 12 |
| 3 | 79 | Bucket 1 |
| 4 | 44 | Collision in bucket 1 |
| 5 | 57 | Another collision in bucket 1 |
| 6 | 0 | Collision in bucket 0 |

## Final Verification

- 20 values processed.
- 23 buckets displayed.
- Collision chains maintained.
- Final output checked against insertion trace.

Result: The observed execution matched the calculated insertion trace.
