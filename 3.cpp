#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

bool check(string s) {
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] != s[i+1]) return false;
    }
    return true;
}

bool check_palindrom(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i -1]) return false;
    }
    return true;
}

string s;

int main() {
    cin >> s;
    int ans;
    if (check(s)) {
        ans = -1;
    } else {
        if (check_palindrom(s)) {
            ans = s.length() -1;
        } else {
            ans = s.length();
        }
    }

    cout << ans;

    return 0;
}
