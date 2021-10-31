#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> q(n);
    int max_val = 0;

    for (int i = 0; i < n; i++) {
        cin >> q[i];
        max_val = max(max_val, q[i]);
    }
    
    for (int i = 0; i < n; i++) {
        cout << (q[i] * 100) / max_val << " ";
    }

    cout << "\n";
}
