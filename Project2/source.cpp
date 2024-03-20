#include <iostream>
#include "List.h"

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

        //check if list L3 already contains square objject of size k
        bool found = false;
        for (auto i = L3.begin(); i != L3.end(); ++i) {
			if ((*i).getSide() == k) {
				found = true;
				break;
			}
		}
        //if not found then insert x into L3 at random pos P between - and L3.size()
        if (!found) {
			int P = (rand() % (L3.size() + 1));
			auto i = L3.begin();
			for (int j = 0; j < P; ++j) {
				++i;
			}
			L3.insert(i, x);
		}
        if (L3.size() == 5) {
            L4 = L3;
            L4.pop_front();
            L3.pop_back();
        }
        //print L1,L2, L3, and L4
        // Print L1
        cout << "L1: ";
        for (const auto& sq : L1) {
            cout << sq << " ";
        }
        cout << endl;

        // Print L2
        cout << "L2: ";
        for (const auto& sq : L2) {
            cout << sq << " ";
        }
        cout << endl;

        // Print L3
        cout << "L3: ";
        for (const auto& sq : L3) {
            cout << sq << " ";
        }
        cout << endl;

        // Print L4
        cout << "L4: ";
        for (const auto& sq : L4) {
            cout << sq << " ";
        }
        cout << endl;

    }

    return 0;
}