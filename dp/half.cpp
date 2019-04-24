#include <bits/stdc++.h>
using namespace std;
const int MAGIC = 10005;
bool dp[128][20050];
int a[128];
int main(){
    int n;
    scanf("%d",&n);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d",a+i);
        sum += a[i];
    }
    dp[0][MAGIC] = true;
    for(int i = 1; i <= n; i++){
        for(int j = i-1; j >= 0; j--){
            for(int k = -10000; k <= 10000; k++){
                if(dp[j][MAGIC+k] && k+a[i] <= 10000 && k+a[i] >= -10000)
                    dp[j+1][MAGIC+k+a[i]] = true;
            }
        }
    }
    int mn = 1e9;
    for(int j = -10000; j <= 10000; j++){
        if(dp[n/2][MAGIC+j]){
            mn = min(mn, abs(sum - 2*j));
        }
    }
    printf("%d\n",mn);
}
