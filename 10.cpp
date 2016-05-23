#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int INF = 1000000000;

int t[1000000];
int n, m;
vector<pair<pair<int,int>, int> > q;

bool my_comp(pair<pair<int, int>, int> i, pair<pair<int,int>,int> j) {
    return (i.second > j.second);
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = -1;
        return;
    }
    int tm = (tl + tr) / 2;
    build(v*2, tl, tm);
    build(v*2+1, tm + 1, tr);
    t[v] = -1;
}

void update(int v, int tl, int tr, int l, int r, int val) {
    if ((l > r) || (t[v] != -1))
        return;
    if ((tl == l) && (tr == r)) {
        t[v] = val;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(tm, r), val);
        update(v*2+1, tm+1, tr, max(tm+1, l), r, val);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        int ret = get(v*2, tl, tm, pos);
        if (ret == -1) ret = t[v];
        return ret;
    } else {
        int ret = get(v*2+1, tm+1, tr, pos);
        if (ret == -1) ret = t[v];
        return ret;
    }
}

int main() {
    cin >> n >> m;
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        q.push_back(make_pair(make_pair(l, r), v));
    }
    sort(q.begin(), q.end(), my_comp);
    for (vector<pair<pair<int,int>,int> >::iterator i = q.begin(); i != q.end(); i++) {
        update(1, 1, n, i->first.first, i->first.second, i->second);
    }
    for (int i = 1; i <= n; i++) {
        int ans = get(1, 1, n, i);
        if (ans == -1) ans = INF;
        cout << ans << ' ';
    }

    return 0;
}
