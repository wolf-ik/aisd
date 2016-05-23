#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

string s;
int n, q, a[200000];

int main() {
    cin >> s;
    n = s.length();
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if (r < l) {
            int tmp = l;
            l = r;
            r = tmp;
        }
        a[l-1]++;
        a[r]--;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        k += a[i];
        if (k % 2 == 1) {
            if (isupper(s[i])) {
                s[i] = tolower(s[i]);
            } else {
                s[i] = toupper(s[i]);
            }
        }
    }
    
    cout << s;
       
    return 0;
}
