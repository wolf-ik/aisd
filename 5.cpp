#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    if (((n % 4 == 0) && (n % 100 != 0)) || (n % 400 == 0)) {
        s = "YES";
    } else {
        s = "NO";      
    }
    cout << s << endl;
    
    return 0;
}
