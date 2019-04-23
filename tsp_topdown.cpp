#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
int dp[1048576][32];
pair<int,int> arr[32];
int n;
int dist(int x,int y){
    return abs(arr[x].first - arr[y].first) + abs(arr[x].second - arr[y].second);
}
int tsp(int bit,int cur){
    if(dp[bit][cur])
        return dp[bit][cur];
    bit &= ~(1 << cur);
    if(!bit){
        if(!cur){
            return 1e9;
        }
        return dist(cur,0);
    }
    int mn = 1e9;
    for(int i = 0; i < n; i++){
        if(bit & (1 << i)){
            mn = min(mn,tsp(bit,i) + dist(cur,i));
        }
    }
    return dp[bit | (1 << cur)][cur] = mn;
}
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    arr[0] = make_pair(x,y);
    scanf("%d",&n);
    if(!n){
        printf("0");
        return 0;
    }
    ++n;
    for(int i = 1; i < n; i++){
        scanf("%d%d",&arr[i].first,&arr[i].second);
    }
    int fullbit = 1 << n;
    --fullbit;
    --fullbit;
    int mn = 1e9;
    for(int i = 1; i < n; i++){
        mn = min(mn,tsp(fullbit,i) + dist(i,0));
    }
    printf("%d",mn);
    return 0;
}

