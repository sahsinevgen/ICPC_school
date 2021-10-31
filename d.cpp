#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <inttypes.h>
#include <cmath>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int64_t n;
        scanf("%" PRId64 "", &n);
        if (n < 6) {
            printf("0\n");
            continue;
        }
        int64_t len = sqrt(2 * n);

        for (; len * (len + 1) / 2 <= n; len++);
        len--;

        printf("%" PRId64 "\n", len * (len + 1) / 2);
    }
}
