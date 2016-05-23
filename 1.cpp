#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int MAXN = 200000;

vector < vector<int> > g(MAXN);
vector<bool> used(MAXN);
vector<int> with(MAXN);
vector<int> without(MAXN);
int n;

void dfs(int v) {
    bool f = false;
    used[v] = true;
    with[v] = 0;
    without[v] = 0;
    for (vector<int>::iterator i = g[v].begin(); i != g[v].end(); i++) {
        if (!used[*i]) {
            dfs(*i);
            if (without[*i] + 1 > with[*i]) {
                if (f) {
                    with[v] += max(with[*i], without[*i]);
                } else {
                    with[v] += without[*i] + 1;
                    f = true;
                }
            } else {
                with[v] += with[*i];
            }
            without[v] += max(without[*i], with[*i]);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    cout << max(with[1], without[1]);

    return 0;
}
