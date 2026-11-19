
# Data Structures Internal Activity 3
## Question 2 – Hash Table Implementation

**Institution:** MIT Academy of Engineering

### Student Details
- PRN: 202501100053
- Scenario: Student Marks
- Dataset Size: 20
- Seed (S): 53

### Project Overview
This project implements a hash table to store student marks using the Mid-Square hashing method and Separate Chaining for collision handling.

### Hashing Technique
The Mid-Square method is used to calculate the hash index.

1. Square the input key.
2. Pad the square to four digits when necessary.
3. Extract the middle two digits.
4. Apply modulo 23 to obtain the bucket index.

Hash function:

h(k) = middle-two-digits(k × k) mod 23

### Collision Handling
Separate Chaining is used to handle collisions. Multiple values assigned to the same bucket are stored in a linked chain.

### Personalized Dataset
53, 66, 79, 92, 5, 18, 31, 44, 57, 70, 83, 96, 9, 22, 35, 48, 61, 74, 87, 0

### Files Included
- main.cpp – C++ implementation
- actual_console_output.txt – Program execution output
- Trace_Match_Report.pdf – Predicted and actual trace comparison
- Debugging_Log_Report.pdf – Debugging documentation
- VIDEO_DEMO_SCRIPT.txt – Demonstration narration

### Compilation and Execution
Compile:
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o hash_table

Run:
./hash_table

### Testing Results
- 20 personalized marks processed.
- Mid-Square hashing applied.
- Collisions handled using Separate Chaining.
- All 23 buckets displayed in the final hash table.

### Note
The table size of 23 is a chosen prime-size assumption because no table-size rule was specified in the assignment.

