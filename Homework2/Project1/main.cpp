#include "class.h"

using namespace std;

// Define an output operator for Square
ostream& operator<< (ostream& out, const Square& rhs)
{
    rhs.print(out);
    return out;
}
ostream& operator<< (ostream& out, const Rectangle& rhs)
{
    rhs.print(out);
    return out;
}

/*
* Return the maximum item in array a.
* Assumes a.size( ) > 0.
* Comparable objects must provide operator< and operator=
*/
template <typename Comparable>
const Comparable& findMax(const vector<Comparable>& a)
{
    int maxIndex = 0;

    for (int i = 1; i < a.size(); ++i)
        if (a[maxIndex] < a[i])
            maxIndex = i;

    return a[maxIndex];
}

int main()
{
    vector<Square> v = { Square{ 3.0 }, Square{ 2.0 }, Square{ 2.5 } };
    vector<Rectangle> r = { Rectangle{ 3.0, 4.0 }, Rectangle{ 2.0, 3.0 }, Rectangle{ 2.5, 3.5 } };

    Square test1{ 3.0 };
    cout << "test1: " << test1 << endl;

    cout << "Largest square: " << findMax(v) << endl;
    cout << "Largest rectangle: " << findMax(r) << endl;
    char c;
    cout << "Enter any char to continue : ";
    cin >> c;
    vector<Square> u(10);
    vector<Rectangle> t(10);
    double x;
    srand(time(NULL)); // seed rand() with system time
    for (int i = 0; i < u.size(); ++i) {
        x = (double)(rand() % 100); // limit data to 0 to 99.

        u[i].setSide(x);
        cout << u[i];
    }
    double y;
    for (int i = 0; i < t.size(); ++i) {
        x = (double)(rand() % 100); // limit data to 0 to 99.
        y = (double)(rand() % 100); // limit data to 0 to 99.

        t[i].setLength(x);
        t[i].setWidth(y);
        cout << t[i];
    }

    cout << "Largest square: " << findMax(u) << endl;
    cout << "Largest rectangle: " << findMax(t) << endl;
    cout << "Enter any char to exit : ";
    cin >> c;
    return 0;
}
