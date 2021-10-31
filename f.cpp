#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int v;
    int val;
    
    edge(int v_ = 0, int val_ = 0): v(v_), val(val_) {

    }
};

vector<vector<edge> > g;
vector<int> col;

bool dfs(int v) {
    for (int i = 0; i < g[v].size(); i++) {
        int u = g[v][i].v;
        if (col[u] == -1) {
            col[u] = (col[v] + g[v][i].val) % 2;
            if (!dfs(u)) {
                return false;
            }
        } else if (col[u] != (col[v] + g[v][i].val) % 2) {
            //cout << u + 1 << " " << v + 1 << endl;
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    g.resize(n, vector<edge>(0));
    col.resize(n, -1);

    for (int i = 0; i < m; i++) {
        int u, v, val;
        cin >> u >> v >> val;
        u--;
        v--;
        val--;
        g[u].emplace_back(v, val);
        g[v].emplace_back(u, val);
    }
    
    for (int i = 0; i < n; i++) {
        if (col[i] != -1) {
            continue;
        }
        col[i] = 0;
        if (!dfs(i)) {
            cout << "NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << col[i] + 1 << " ";
    }
    cout << "\n";
}
