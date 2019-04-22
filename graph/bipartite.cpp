#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, m;
bool isbi = true;
col[N]; // 0 no col, 1 blue, 2 red
vector<int> g[N];

void dfs(int u) {
    for(int v : g[u]) {
        if(col[v] == 0) {
            if(col[u] == 1) col[v] = 2;
            else col[v] = 1;
            dfs(v);
        } else {
            if(col[u] == col[v]) isbi = false;
        }
    }
}

void dfs(int u) {
    for(int v : g[u]) 
        if(!col[v]) col[v] = col[u] ^ 3, dfs(v);
        else if(col[v] != col[u] ^ 3) isbi = false;
}

int main() {
    cin >> n >> m;
    for(int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    int count = 0;
    for(int i = 1; i <= n; ++i) if(col[i] == 0) {
        col[i] = 1;
        dfs(i);
        count++;
    }

}