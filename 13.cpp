#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int MAXN = 200000;
ll md = 10000007;

vector < vector<pair<int, int> > > g(MAXN);
vector <pair<pair<int, int>, int> > r;
vector<bool> used(MAXN);
vector<int> cnt(MAXN, 0);
int n;

void dfs(int v) {
    used[v] = true;
    cnt[v] = 1;
    for (vector<pair<int, int> >::iterator i = g[v].begin(); i != g[v].end(); i++) {
        if (!used[i->first]) {
            r.push_back(make_pair(make_pair(v, i->first), i->second));
            dfs(i->first);
            cnt[v] += cnt[i->first];
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    dfs(1); 

    ll ans = 0;
    for (int i = 0; i < r.size(); i++) {
        ll w = r[i].second;
        int from = r[i].first.first;
        int to = r[i].first.second;
        ans += w * (ll)(n - cnt[to]) * (ll)(cnt[to]) * 2;
        ans %= md;
    }
    cout << ans;

    return 0;
}
