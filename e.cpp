#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int64_t> q(n);
    int64_t max_val = 0;
    int64_t cnt = 0;

    for (int i = 0; i < n; i++) {
        cin >> q[i];
        max_val = max(max_val, q[i]);
        cnt += q[i];
    }
    
    cout << min((cnt - max_val) * 2 + 1, cnt) << "\n";
}
