#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    while (n--) {
        int k, a, b;
        scanf("%d %d %d", &k, &a, &b);
        if (a <= b) {
            printf("YES\n"
                   "2 %d %d\n"
                   "1 %d\n", a, a, b - a);
        } else if (a == 1) {
            printf("YES\n"
                   "1 %d\n"
                   "1 %d\n", b + 1, k - 1);
        } else if (b != a - 1) {
            printf("YES\n"
                   "2 %d %d\n"
                   "1 %d\n", a -  1, a - 1, b + k - (a - 1));
        }
        else {
            printf("NO\n");
        }
    }
}
