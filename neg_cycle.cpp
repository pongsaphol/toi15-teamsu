#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1000;

int n, m;
int d[N];

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        for(int i = 1; i < n; ++i) d[i] = INF:
        vector<tuple<int, int, int> > E;
        for(int i = 0, u, v, w; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            E.emplace_back(u, v, w);
        } 
        for(int i = 1; i < n; ++i) {
            for(auto edge : E) {
                int u, v, w; tie(u, v, w) = edge;
                if(d[v] > d[u] + w) d[v] = d[u] + w;
            }
        }
        bool possible = true;
        for(auto edge : E) {
            int u, v, w; tie(u, v, w) = edge;
            if(d[v] > d[u] + w) possible = false;
        }
        puts(possible ? "possible" : "not possible");
    }
}