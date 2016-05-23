#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int n, m, parent[20000];

void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent[b] = a;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        make_set(i);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        union_set(a, b);
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (find_set(i) != find_set(i+1)) {
            ans++;
            union_set(i, i+1);
        }
    }

    cout << ans;

    return 0;
}
