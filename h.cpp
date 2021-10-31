#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int tree[800'000];
vector<pair<int, int> > w;

int update(int i, int l, int r, int x) {
    if (l == r - 1) {
        tree[i] += w[l].first + w[l].second * x;
        return l;
    }
    
    int m = (l + r) / 2;
    int ans = 0;
    if (tree[2 * i + 1] <= tree[2 * i + 2]) {
        ans = update(2 * i + 1, l, m, x);
    } else {
        ans = update(2 * i + 2, m, r, x);
    }
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
    return ans;
}

int get_ans(int i, int l, int r) {
    if (l == r - 1) {
        return tree[i];
    }

    int m = (l + r) / 2;
    return max(get_ans(2 * i + 1, l, m),
               get_ans(2 * i + 2, m, r));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> q(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    
    w.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> w[i].first >> w[i].second;
    }

    vector<int> anss(n);
    for (int i = 0; i < n; i++) {
        anss[i] = update(0, 0, m, q[i]);
    }
    cout << get_ans(0, 0, m) << endl;
    for (int i = 0; i < n; i++) {
        cout << anss[i] + 1 << " ";
    }
    cout << endl;
}
