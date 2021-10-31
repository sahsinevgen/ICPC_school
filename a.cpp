#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> q(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    int m;
    cin >> m;
    vector<int> w(m);
    for (int i = 0; i < m; i++) {
        cin >> w[i];
    }
    
    int i = 0;
    int j = 0;
    int ans = 0;
    for (; i < n && j < m; ans++) {
        if (q[i] == w[j]) {
            i++;
            j++;
        } else if (q[i] < w[j]) {
            i++;
        } else {
            j++;
        }
    }
    ans += n - i;
    ans += m - j;
    cout << ans << "\n";
}
