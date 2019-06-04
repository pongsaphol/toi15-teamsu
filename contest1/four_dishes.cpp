#include <bits/stdc++.h>
using namespace std;
int a[5005];
unordered_map<long long,int> um;
int main(){
    int n;
    long long s;
    scanf("%d%lld",&n,&s);
    for(int i = 0; i < n; i++){
        scanf("%d",a+i);
    }
    long long cnt = 0ll;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            cnt += um[s - a[i] - a[j]];
        }
        for(int j = 0; j < i; j++){
            um[(long long)(a[j]) + (long long)a[i]]++;
        }
    }
    printf("%lld\n",cnt*24ll);
    return 0;
}

