#include <iostream>
#include "List.h"
#include "Square.h"

int main() {
    // First, create lists L1, L2, L3, and L4, containing zero Square elements
    List<Square> L1;
    List<Square> L2;
    List<Square> L3;
    List<Square> L4;

    srand((unsigned int)time(NULL));// seed rand() with system time

    //insert 20 square objects into L1 in a loop
    while (L1.size() <= 20) {
        // Generate a random integer k in the range 1 to 100
        int k = (rand() % 100) + 1;

        // Construct a Square object x with side value k
        Square x(k);

        // Execute: L1.push_front(x)
        L1.push_front(x);

        // Execute: L2.push_back(x)
        L2.push_back(x);
    }

    return 0;
}