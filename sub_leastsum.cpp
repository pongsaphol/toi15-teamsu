#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    int n,s;
    while(scanf("%d%d",&n,&s) != EOF){
        int idx = 0;
        int csum = 0;
        int mn = 1e9;
        for(int i = 1; i <= n; i++){
            scanf("%d",a+i);
            csum += a[i];
            while(csum - a[idx] >= s){
                csum -= a[idx];
                idx++;
            }
            if(csum >= s)
                mn = min(mn, i - idx + 1);
        }
        if(mn == 1e9) mn = 0;
        printf("%d\n",mn);
    }
    return 0;
}
