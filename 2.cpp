#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int T, n, m, ans;
int a[55][55];
bool f[55][55];
vector<pair<int,int> > c;
bool ff;
set<int> ss;
vector< vector< pair<int,int> > > g(11111);
vector<pair<int,int> > nex;

void dfs(int i, int j, int h) {
    if (a[i][j] == -1) return;
    if (a[i][j] > h) return;
    int tmp = min(min(a[i+1][j], a[i-1][j]), min(a[i][j+1], a[i][j-1]));
    if (tmp == -1) {
        ff = true;
    }
    if (f[i][j]) return;
    c.push_back(make_pair(i,j));
    f[i][j] = true;
    dfs(i+1, j, h);
    dfs(i-1, j, h);
    dfs(i, j+1, h);
    dfs(i, j-1, h);
}

int main() {
    scanf("%d", &T);
    //cin >> T;
    for (int test = 0; test < T; test++) {
        scanf("%d %d", &n, &m);
        //cin >> n >> m;
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= m + 1; j++) {
                if ((i >= 1) && (i <= n) && (j >= 1) && (j <= m)) {
                    scanf("%d", &a[i][j]);
                    //cin >> a[i][j];
                    f[i][j] = false;
                    ss.insert(a[i][j]);
                    g[a[i][j]].push_back(make_pair(i, j));
                } else {
                    a[i][j] = -1;
                    f[i][j] = false;
                }
            }
        }
        ans = 0;
        int h = *ss.begin();
        ss.erase(ss.begin());
        int     hh;
        while (!ss.empty()) {
            hh = *ss.begin();
            ss.erase(ss.begin());
            int dif = hh - h;
            ans += g[h].size() * dif;
            nex.clear();

            for (vector<pair<int,int> >::iterator ii = g[h].begin(); ii != g[h].end(); ii++) {
                int i = ii->first;
                int j = ii->second;
                ff = false;
                c.clear();
                if (!f[i][j]) dfs(i, j, h);
                for (vector<pair<int,int> >::iterator k = c.begin(); k != c.end(); k++) {
                    if (ff) {
                        a[k->first][k->second] = -1;
                        ans -= dif;
                    } else {
                        nex.push_back(make_pair(k->first, k->second));
                    }
                }
            }
            for (vector<pair<int,int> >::iterator i = nex.begin(); i != nex.end(); i++) {
                g[hh].push_back(make_pair(i->first, i->second));
                f[i->first][i->second] = false;
                a[i->first][i->second] = hh;
            }
            g[h].clear();
            h = hh;
        }
        g[h].clear();
        printf("%d\n", ans);
        //cout << ans << endl;
    }

    return 0;
}
