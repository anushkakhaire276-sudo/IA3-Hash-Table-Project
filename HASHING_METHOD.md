
# Hashing Method – Technical Explanation

## 1. Mid-Square Hashing

The Mid-Square method generates a hash index by squaring a key and extracting its middle two digits.

Formula:

h(k) = middle digits(k × k) % 23

Example:

Key = 53
Square = 53 × 53 = 2809
Middle digits = 80
Hash index = 80 % 23 = 11

## 2. Separate Chaining

When two or more keys generate the same index, they are stored in a linked chain at that bucket.

Example:

Bucket 1:
79 → 44 → 57 → 74

Bucket 0:
92 → 0

## 3. Advantages

- Handles collisions effectively.
- Allows multiple keys in one bucket.
- Makes insertion straightforward.
- Avoids replacing previously inserted values.

## 4. Project Configuration

- Table size: 23
- Hashing: Mid-Square
- Collision handling: Separate Chaining
- Number of keys: 20
