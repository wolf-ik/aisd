#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

int main() {
    ll n;
    cin >> n;
    if (n % 10 == 0) {
        cout << "NO";
    } else {
        cout << n % 10;
    }

    return 0;
}
