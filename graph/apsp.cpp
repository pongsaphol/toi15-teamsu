#include <bits/stdc++.h>
using namespace std;

const int N = 255;

int n, m;
int d[N][N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &d[i][j]);
        }
    }
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    scanf("%d", &m);
    for(int i = 0, a, b, c; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        int val = d[a][b] + d[b][c];
        printf("%d %d\n", val, val - d[a][c]);
    }
}
