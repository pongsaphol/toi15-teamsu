#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int par[N], sz[N];

int find(int u) { return par[u] = u == par[u] ? u : find(par[u]); }

void solve() {
    for(int i = 0; i < N; ++i) par[i] = i, sz[i] = 1;
    map<string, int> Mp;
    int step = 0, m;
    cin >> m;
    for(int i = 0; i < m; ++i) {
        string u, v; cin >> u >> v;
        int nu, nv;
        if(Mp[u]) nu = Mp[u];
        else nu = Mp[u] = ++step;
        if(Mp[v]) nv = Mp[v];
        else nv = Mp[v] = ++step;
        int a = find(nu), b = find(nv);
        if(a != b) {
            par[a] = b;
            sz[b] += sz[a];
            cout << sz[b] << endl;
        } else cout << sz[a] << endl;
    }    
}

int main() {
    int T; cin >> T;
    while(T--) solve();
}