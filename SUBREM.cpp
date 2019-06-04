#include <bits/stdc++.h>
using namespace std;
int a[100005];
vector<int> g[100005];
long long sum[100005];
long long val[100005];
int x;
long long gmn;
void dfs(int u, int p = -1){
    sum[u] = a[u];
    val[u] = 0ll;
    for(int v : g[u]){
        if(v == p) continue;
        dfs(v, u);
        sum[u] += sum[v];
        val[u] += val[v];
    }
    val[u] = max(val[u], -sum[u] - (long long)x);
    gmn = max(gmn, val[u]);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        gmn = 0ll;
        int n;
        scanf("%d%d",&n,&x);
        long long sum = 0ll;
        for(int i = 0; i < 100005; i++) g[i].clear();
        for(int i = 1; i <= n; i++){
            scanf("%d",a+i);
            sum += (long long)a[i];
        }
        for(int i = 1; i < n; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1);
        printf("%lld\n",sum + gmn);
    }
}