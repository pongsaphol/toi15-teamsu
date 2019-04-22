#include <bits/stdc++.h>
using namespace std;

const int N = 255;

int n;
bool dp[N][N][3];
char inp[N];
int oper[3][3] = {  {2, 1, 0},
                    {2, 1, 1},
                    {1, 2, 1}};

vector<pair<int, int>> op[3];

void solve() {
    scanf("%d", &n);
    memset(dp, 0, sizeof dp); 
    scanf("%s", inp);
    for(int i = 0; i < n; ++i) {
        inp[i] -= '0';
        dp[i][i][inp[i]] = true;
    }
    for(int len = 2; len <= n; ++len) 
        for(int l = 0, r = l+len-1; r < n; ++l, ++r) 
            for(int k = l; k < r; ++k) 
                for(int z = 0; z < 3; ++z) 
                    for(auto x : op[z])
                        if(dp[l][k][x.first] && dp[k+1][r][x.second]) dp[l][r][z] = true;
    puts(dp[0][n-1][0] ? "yes" : "no");
}

int main() {
    for(int i = 0; i < 3; ++i) for(int j = 0; j < 3; ++j) 
    op[oper[i][j]].emplace_back(i, j);
    int t = 20;
    while(t--) solve();
}