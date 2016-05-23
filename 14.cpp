#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, x, ans, a[1000];

int main() {
    cin >> x;
    n = 0;
    while (x > 0) {
        a[n] = x % 10;
        x /= 10;
        n++;
    }
    int i = 0;
    while ((i < n) && (a[i] <= a[i+1])) {
        i++;
    }
    i++;
    if ((i >= n) || (n == 1)) {
        cout << -1;
    } else {
        int k = 0;
        while ((a[k] == 0) || (a[k] <= a[i])) { 
            k++;
        }
        int tmp = a[k];
        a[k] = a[i];
        a[i] = tmp;
        i = n - i - 1;
        for (int j = 0; j < n/2; j++) {
            int tmp = a[j];
            a[j] = a[n - 1 - j];
            a[n - 1 - j] = tmp;
        }
        sort(a + i + 1, a + n);
        for (int i = 0; i < n; i++) {
            cout << a[i];
        }
    }


    return 0;
}
