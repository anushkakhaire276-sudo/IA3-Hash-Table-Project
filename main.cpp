/*
 * MIT Academy of Engineering, Alandi
 * Data Structures - Internal Activity 3, Question 2
 * PRN: 202501100053
 * Scenario: Student Marks (PRN mod 3 = 1)
 * Dataset seed S: 53 (last four digits of PRN)
 * Hash function: Mid-Square (PRN is odd)
 * Collision handling: Separate Chaining (PRN mod 2 = 1)
 * Table size: 23 (prime chosen for this implementation; the assignment
 * does not specify a table-size formula for Question 2)
 *
 * Mid-square rule used:
 * 1. Square the key.
 * 2. Write the square as a four-digit string, padding leading zeroes.
 * 3. Extract the middle two digits (string positions 1 and 2).
 * 4. Take those two digits modulo 23 to obtain the bucket index.
 */

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 23;
const int PRN_SEED = 53;
const string PRN = "202501100053";
const vector<int> studentMarks = {
    53, 66, 79, 92, 5, 18, 31, 44, 57, 70,
    83, 96, 9, 22, 35, 48, 61, 74, 87, 0
};

struct HashDetails {
    long long square;
    string paddedSquare;
    int middleTwoDigits;
    int bucket;
};

HashDetails midSquareHash(int key) {
    const long long square = 1LL * key * key;
    string squareText = to_string(square);

    // All personalized marks are between 0 and 99, so their squares
    // need at most four digits. Pad smaller squares to exactly four.
    while (squareText.length() < 4) {
        squareText.insert(squareText.begin(), '0');
    }

    const int middle = stoi(squareText.substr(1, 2));
    return {square, squareText, middle, middle % TABLE_SIZE};
}

class HashTable {
private:
    vector<vector<int>> buckets;

public:
    HashTable() : buckets(TABLE_SIZE) {}

    bool insert(int key) {
        const int index = midSquareHash(key).bucket;
        vector<int>& chain = buckets[index];

        // Do not store the same key twice in one chain.
        if (find(chain.begin(), chain.end(), key) != chain.end()) {
            return false;
        }

        chain.push_back(key); // Separate chaining: append in insertion order.
        return true;
    }

    void printOccupiedBuckets() const {
        bool first = true;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (!buckets[i].empty()) {
                if (!first) cout << " | ";
                cout << i << ": ";
                for (size_t j = 0; j < buckets[i].size(); ++j) {
                    if (j > 0) cout << " -> ";
                    cout << buckets[i][j];
                }
                first = false;
            }
        }
        if (first) cout << "(all buckets empty)";
        cout << '\n';
    }

    void printFinalTable() const {
        cout << "\nFINAL HASH TABLE (all " << TABLE_SIZE << " buckets)\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << setw(2) << i << " : ";
            if (buckets[i].empty()) {
                cout << "NULL";
            } else {
                for (size_t j = 0; j < buckets[i].size(); ++j) {
                    if (j > 0) cout << " -> ";
                    cout << buckets[i][j];
                }
            }
            cout << '\n';
        }
    }
};

int main() {
    cout << "MIT ACADEMY OF ENGINEERING - DATA STRUCTURES IA 3 (Q2)\n";
    cout << "PRN: " << PRN << '\n';
    cout << "Scenario: Student Marks\n";
    cout << "Seed S: " << PRN_SEED << '\n';
    cout << "Hash function: Mid-Square Method\n";
    cout << "Collision handling: Separate Chaining\n";
    cout << "Table size m: " << TABLE_SIZE << " (chosen prime size)\n";
    cout << "Rule: h(k) = middle-two-digits(k*k) mod " << TABLE_SIZE << "\n\n";

    cout << "Personalized dataset (20 marks): ";
    for (size_t i = 0; i < studentMarks.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << studentMarks[i];
    }
    cout << "\n\nINSERTION TRACE\n";

    HashTable table;
    for (size_t i = 0; i < studentMarks.size(); ++i) {
        const int key = studentMarks[i];
        const HashDetails details = midSquareHash(key);

        cout << "Step " << setw(2) << (i + 1)
             << " | key=" << setw(2) << key
             << " | square=" << details.square
             << " | padded=" << details.paddedSquare
             << " | middle=" << setw(2) << setfill('0')
             << details.middleTwoDigits << setfill(' ')
             << " | bucket=" << details.bucket << '\n';

        if (!table.insert(key)) {
            cout << "   Duplicate key ignored: " << key << '\n';
        }

        cout << "   State: ";
        table.printOccupiedBuckets();
    }

    table.printFinalTable();
    cout << "\nInsertion complete: " << studentMarks.size()
         << " personalized values processed.\n";
    return 0;
}
