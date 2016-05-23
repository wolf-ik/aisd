#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

ll a[200000];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    ll ans = a[n-1] * a[n-2];
    if (a[0] * a[1] > ans) {
        ans = a[0] * a[1];
    }
    cout << ans;

    return 0;
}
