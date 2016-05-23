#include <iostream>

using namespace std;

typedef long long ll;

int n;

ll h, ans, a[200000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > h) {
            h = a[i];
        }
    }
    ans = h - a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            ans += a[i - 1] - a[i];
        }
    }
    
    cout << ans;
    
    return 0;
}
