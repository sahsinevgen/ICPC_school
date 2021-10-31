#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;
    vector<int> cnt(26);
    vector<int> uses(26, 0);

    for (int i = 0; i < 26; i++) {
        cin >> cnt[i];
    }
    
    int n = s.size();
    int l = 0;
    int r = 0; 
    int ans = 0;

    for (l = 0; l < n; uses[s[l] - 'a']--, l++) {
        while (r < n && uses[s[r] - 'a'] < cnt[s[r] - 'a']) {
            uses[s[r] - 'a']++;
            r++;
            ans = max(ans, r - l);
        }
        /*
        cout << l << " " << r << " " << ans << endl;
        for (int i = 0; i < 26; i++) {
            cout << uses[i] << " ";
        }
        cout << endl;
        */
        if (r == n) {
            break;
        }
        if (r == l) {
            uses[s[r] - 'a']++;
            r++;
        }
    }

    cout << ans << endl;
}
