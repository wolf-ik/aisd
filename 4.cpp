#include <iostream>

using namespace std;

typedef long long ll;

int n, a[2000000], t[2000000];
ll ans;

int sum(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r+1)) -1) {
        res += t[r];
    }
    return res;
}

void inc(int i, int d) {
    for (; i < n; i = (i | (i+1))) {
        t[i] += d;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n / 2; i++) {
        int tmp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = tmp;
    }
    for (int i = 0; i < n; i++) {
        ans += sum(a[i] - 1);
        inc(a[i] - 1, 1);
    }

    cout << ans;

    return 0;
}
