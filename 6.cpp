#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int MAXN = 2000000;
ll INF = 10000000000000000;

vector < vector< pair<int, int> > > g(MAXN);
vector<ll> d(MAXN, INF);
vector<bool> used(MAXN);

int n, m, start, finish;

int main() {
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    cin >> start;
    cin >> finish;
    d[start] = 0;
    set < pair<ll, int> > q;
    q.insert(make_pair(d[start], start));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        
        for (vector< pair<int,int> >::iterator i = g[v].begin(); i != g[v].end(); i++) {
            int to = i->first;
            int w = i->second;
            
            if (d[to] > d[v] + (ll)w) {
                q.erase(make_pair(d[to], to));
                d[to] = d[v] + (ll)w;
                q.insert(make_pair(d[to], to));
            }
        }
    }

    cout << d[finish];

    return 0;
}
