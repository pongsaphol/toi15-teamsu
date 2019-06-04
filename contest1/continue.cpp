#include <bits/stdc++.h>
using namespace std;
int r[500005];
int indeg[500005];
long long dp[500005];
int v[500005];
long long dpans[2][500005];
vector<int> g[500005];
int comp[500005];
vector<long long> items[500005];
int init[500005];
void dfs(int u, int c = -1){
    if(c == -1) c = u;
    comp[u] = c;
    for(int v : g[u]){
        if(init[v] != 0) continue;
        dfs(v,c);
    }
}
class qstr{
public:
    int b;
    int i;
    long long v;
    qstr(int x, int y, long long z) : b(x), i(y), v(z) {}
    friend bool operator<(qstr x, qstr y){
        return x.v < y.v;
    }
};
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d",r+i,v+i);
        indeg[r[i]]++;
        init[r[i]]++;
        g[r[i]].push_back(i);
    }
    int k;
    scanf("%d",&k);
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(init[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(!--init[r[cur]]){
            q.push(r[cur]);
        }
    }
    for(int i = 1; i <= n; i++){
        if(init[i]){
            dfs(i);
        }
    }
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        dp[cur] += (long long)v[cur];
        if(dp[cur] > dp[r[cur]]) {
            if(dp[r[cur]]) items[comp[r[cur]]].push_back(dp[r[cur]]);
            dp[r[cur]] = dp[cur];
        }else{
            items[comp[cur]].push_back(dp[cur]);
        }
        if(!--indeg[r[cur]]){
            q.push(r[cur]);
        }
    }
    for(int i = 1; i <= n; i++){
        if(indeg[i]) items[i].push_back(dp[i]);
    }
    vector<vector<long long> > vals;
    for(int i = 1; i <= n; i++){
        if(indeg[i]){
            int x = r[i];
            long long s = v[i];
            vector<long long> cur = items[i];
            while(x != i){
                s += (long long)v[x];
                for(long long y : items[x]){
                    cur.push_back(y);
                }
                indeg[x] = 0;
                x = r[x];
            }
            sort(cur.begin(),cur.end(), greater<long long>());
            cur[0] += s;
            vals.push_back(cur);
            indeg[i] = 0;
        }
    }
    long long ans = 0ll;
    priority_queue<qstr> pq;
    for(int i = 0; i < vals.size(); i++){
        pq.emplace(i,0,vals[i][0]);
    }
    while(!pq.empty() && k >= 0){
        qstr cur = pq.top();
        pq.pop();
        k--;
        ans += cur.v;
        if(cur.i+1 < vals[cur.b].size()){
            pq.emplace(cur.b,cur.i+1,vals[cur.b][cur.i+1]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}

