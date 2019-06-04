#include <bits/stdc++.h>
using namespace std;
char str[1000005];
long long qs[1000005];
unordered_map<long long,int> ump;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",str+1);
    int mx = 0;
    ump[0] = 0;
    for(int i = 1; i <= n; i++){
        qs[i] = qs[i-1] + (long long)(str[i] == 'R' ? -k : 1);
        if(ump.find(qs[i]) == ump.end()){
            ump[qs[i]] = i;
        }else{
            mx = max(mx, i - ump[qs[i]]);
        }
    }
    printf("%d\n",mx);
    return 0;
}
