#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1006][1006];
int main(){
    int n;
    int g;
    int t;
    int p,w;
    int mw;
    scanf("%d",&t);
    while(t--){
        for(int i = 0; i < 1006; i++){
            for(int j = 0; j < 1006; j++){
                dp[i][j] = 0;
            }
        }
        scanf("%d",&n);
        for(int i = 1; i <= n; i++){
            scanf("%d%d",&p,&w);
            dp[i][w] = p;
            for(int j = 1; j < w; j++){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            for(int j = w; j <= 1005; j++){
                dp[i][j] = max(max(dp[i-1][j],dp[i][j-1]),p + dp[i-1][j-w]);
            }
        }
        scanf("%d",&g);
        int sum = 0;
        for(int i = 0; i < g; i++){
            scanf("%d",&mw);
            sum += dp[n][mw];
        }
        printf("%d\n",sum);
    }
    return 0;
}
