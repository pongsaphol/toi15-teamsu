#include <bits/stdc++.h>
using namespace std;
vector<int> g[200005];
int dp[200005][2];
void dfs(int u, int p = -1){
    int mx = 0;
    for(int v : g[u]){
        if(v == p) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][1], dp[v][0]);
        dp[u][1] += max(dp[v][1], dp[v][0]);
        mx = max(mx, 1 + dp[v][0] - max(dp[v][1], dp[v][0]));
    }
    dp[u][1] += mx;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i < n; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    printf("%d\n",max(dp[1][0], dp[1][1]));
    return 0;
}
