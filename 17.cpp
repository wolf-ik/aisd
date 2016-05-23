#include <iostream>
#include <cmath>

using namespace std;

int n, m, x, y, xx, yy;

int main() {
    cin >> n >> m >> x >> y >> xx >> yy;
    if (abs(x - xx) == abs(y - yy)) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}
