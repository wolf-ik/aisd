#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll md = 1000000007;

ll a[111][111];
int n, m, u, v, l;


void mul(ll aa[][111], ll bb[][111], ll c[][111]) {
    ll a[111][111], b[111][111];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = aa[i][j];
            b[i][j] = bb[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += (a[i][k] * b[k][j]) % md;
            }
            c[i][j] %= md;
        }
    }
}

void binpow(ll a[][111], int nn) {
    if (nn == 1) return;
    if (nn % 2 == 1) {
        ll b[111][111];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b[i][j] = a[i][j];
            }
        }
        binpow(a, nn-1);
        mul(a, b, a);
    } else {
        binpow(a, nn/2);
        mul(a, a, a);
    }
}

int main() {
    cin >> n >> m;
    cin >> u >> v >> l;
    if (l == 0) {
        if (u == v) {
            cout << 1;
        } else {
            cout << 0;
        }
        return 0;
    }
    for (int i = 0; i < m; i++) {
        int aa, bb;
        cin >> aa >> bb;
        a[aa-1][bb-1]++;
        a[bb-1][aa-1]++;
    }
    binpow(a, l);
    cout << a[u-1][v-1] % md << endl;

    return 0;
}
