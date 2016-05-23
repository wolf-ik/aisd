#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int MAXN = 200000;
ll md = 1000000007;

vector <ll> neg;
vector <ll> pos;
int n, k;
ll ans;

ll posmod(ll a) {
    ll b = a % md;
    if (b < 0) b += md;
    return b;
}

ll mod(ll a) {
    return a % md;
}

int main() {
//    cout << mod(-1) << endl;
//    cout << posmod(-md*2) << endl;
    ans = 1;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (a >= 0) {
            pos.push_back(a);
        } else {
            neg.push_back(abs(a));
        }

        if (n == k) {
            ans *= mod(a);
            ans = mod(ans);
        }
    }
    if (n == k) {
        cout << posmod(ans);
        return 0;
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    
    
//    for (int i = 0; i < pos.size(); i++) {
//        pos[i] = mod(pos[i]);
//    }
//    for (int i = 0; i < neg.size(); i++) {
//        neg[i] = mod(neg[i]);
//    }
    
    if ((pos.size() == 0) && (k % 2 == 1)) {
        ans = 1;
        for (int i = 0; i < k; i++) {
            ans *= mod(neg[i]);
            ans = mod(ans);   
        }
        cout << posmod(-ans);
        return 0;
    }
    
    reverse(pos.begin(), pos.end());
    reverse(neg.begin(), neg.end());

    ans = 1;
    if (k % 2 == 1) {
        k--;
        ans = mod(pos[0]);
        pos.erase(pos.begin());
    }
    
//    for (int i = 0; i < pos.size(); i++) {
//        cout << pos[i] << ' ';
//    }

    int i = 0, j =0;
    while (k > 0) {
        if (i + 1 < pos.size()) {
            if (j + 1 < neg.size()) {
                if (pos[i] * pos[i+1] > neg[j] * neg[j+1]) {
                    ans *= mod(pos[i] * pos[i+1]);
                    ans = mod(ans);
                    i += 2;
                } else {
                    ans *= mod(neg[j] * neg[j+1]);
                    ans = mod(ans);
                    j += 2;
                }
            } else {
                ans *= mod(pos[i] * pos[i+1]);
                ans = mod(ans);
                i += 2;
            }
        } else {
            ans *= mod(neg[j] * neg[j+1]);
            ans = mod(ans);
            j += 2;
        }
    k -= 2;
    }
    cout << ans;

    return 0;
}
