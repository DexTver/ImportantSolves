#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long double x, y, r, a, b, c, s;
    cin >> x >> y >> r >> a >> b >> c;
    cout.precision(20);
    s = abs((a * x + b * y + c) / sqrt(a * a + b * b));
    if (r < s) {
        cout << 0;
        return 0;
    }
    if (abs(r - s) < 0.000001) {
        cout << 1 << endl;
        if (abs(a * x + b * y + r * (a * a + b * b) + c) < 0.000001) {
            cout << x + (r * a) / sqrt(a * a + b * b) << ' ' << y + (r * b) / sqrt(a * a + b * b);
        }
        else { cout << x - (r * a) / sqrt(a * a + b * b) << ' ' << y - (r * b) / sqrt(a * a + b * b); }
    }
    else {
        cout << 2 << endl;
        if (abs(a * (x + s * a / sqrt(a * a + b * b)) + b * (y + s * b / sqrt(a * a + b * b)) + c) > 0.000001) {
            cout << x + (-s * a - b * sqrt(r * r - s * s)) / sqrt(a * a + b * b) << ' '
                 << y + (-s * b + a * sqrt(r * r - s * s)) / sqrt(a * a + b * b) << endl;
            cout << x + (-s * a + b * sqrt(r * r - s * s)) / sqrt(a * a + b * b) << ' '
                 << y + (-s * b - a * sqrt(r * r - s * s)) / sqrt(a * a + b * b) << endl;
        }
        else {
            cout << x + (s * a - b * sqrt(r * r - s * s)) / sqrt(a * a + b * b) << ' '
                 << y + (s * b + a * sqrt(r * r - s * s)) / sqrt(a * a + b * b) << endl;
            cout << x + (s * a + b * sqrt(r * r - s * s)) / sqrt(a * a + b * b) << ' '
                 << y + (s * b - a * sqrt(r * r - s * s)) / sqrt(a * a + b * b) << endl;
        }
    }
    return 0;
}