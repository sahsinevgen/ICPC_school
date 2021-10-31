#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int64_t M = 1'000'000'007;
int p = 31;
vector<int64_t> p_pow(40);

bool check(const string &a, const string &b) {
    int n = a.size();
    int m = b.size();
    if ((n + m) % 2 == 1) {
        return false;
    }
    for (int i = 0; i < (n + m) / 2; i++) {
        int j = i + (n + m) / 2;
        char c1 = (i < n ? a[i] : b[i - n]);
        char c2 = (j < n ? a[j] : b[j - n]);
        if (c1 != c2) {
            return false;
        }
    }
    if (a == b) {
        return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<string> strs(n);
    vector<vector<int64_t> > hashs(n);
    map<int64_t, int> full_hashs;
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
        int sz = strs[i].size();
        hashs[i].resize(sz + 1);
        hashs[i][0] = 0;
        for (int j = 0; j < sz; j++) {
            hashs[i][j + 1] = (hashs[i][j] * p + strs[i][j] - 'a' + 1) % M;
        }
        full_hashs[hashs[i][sz]] = i;
    }

    p_pow[0] = 1;
    for (int i = 1; i < 40; i++) {
        p_pow[i] = (p_pow[i - 1] * p) % M;
    }

    for (int i = 0; i < n; i++) {
        int sz = strs[i].size();
        for (int j = sz - 1; j >= 0; j--) {
            
            int64_t other_hash = 
                (hashs[i][j + 1] - 
                 (hashs[i][sz - 1 - j] * p_pow[2 * (j + 1) - sz]) % M + M) % M;
            
            if (full_hashs.count(other_hash) &&
                check(strs[i], strs[full_hashs[other_hash]])) {
                cout << "YES\n" << i + 1 << " " << 
                        full_hashs[other_hash] + 1 << endl;
                return 0;
            }
        }

        for (int j = 0; j < sz; j++) {
            
            int64_t other_hash = 
                (hashs[i][sz - j] -
                 (hashs[i][j] * p_pow[sz - 2 * j]) % M + M) % M;
            
            if (full_hashs.count(other_hash) &&
                check(strs[i], strs[full_hashs[other_hash]])) {
                cout << "YES\n" << i + 1 << " " << 
                        full_hashs[other_hash] + 1 << endl;
                return 0;
            }
        }
    }
    cout << "NO\n";
}
