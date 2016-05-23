#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

ll NUMBER_1 = 1021;
ll NUMBER_2 = 1031;
ll NUMBER_3 = 1033;

set<ll> a;
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.insert(tmp);
    }
    bool f = false;
    if ((a.find(NUMBER_1) != a.end()) && (a.find(NUMBER_2) != a.end()) && (a.find(NUMBER_3) != a.end())) f = true;
    if ((a.find(NUMBER_1 * NUMBER_2) != a.end()) && (a.find(NUMBER_3) != a.end())) f = true;
    if ((a.find(NUMBER_1 * NUMBER_3) != a.end()) && (a.find(NUMBER_2) != a.end())) f = true;
    if ((a.find(NUMBER_2 * NUMBER_3) != a.end()) && (a.find(NUMBER_1) != a.end())) f = true;
    if (a.find(NUMBER_1 * NUMBER_2 * NUMBER_3) != a.end()) f = true;
    if (f) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
