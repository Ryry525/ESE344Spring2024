#include "class.h"

using namespace std;

int main()
{
    vector<Square> v = { Square{ 3.0 }, Square{ 2.0 }, Square{ 2.5 } };
    vector<Rectangle> r = { Rectangle{ 3.0, 4.0 }, Rectangle{ 2.0, 3.0 }, Rectangle{ 2.5, 3.5 } };

    cout << "Largest square: " << findMax(v) << endl;
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
    cout << "Largest square: " << findMax(u) << endl;
    cout << "Largest rectangle: " << findMax(r) << endl;
	cout << "Enter any char to continue : ";
    cin >> c;
    double y;
    for (int i = 0; i < t.size(); ++i) {
        x = (double)(rand() % 100); // limit data to 0 to 99.
        y = (double)(rand() % 100); // limit data to 0 to 99.

        t[i].setLength(x);
        t[i].setWidth(y);
        cout << t[i];
    }

    
    cout << "Largest rectangle: " << findMax(t) << endl;
    return 0;
}
