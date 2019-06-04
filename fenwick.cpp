#include <bits/stdc++.h>
using namespace std;
int FT[100005];
void add(int idx, int amt){
    while(idx < 100005){
        FT[idx] += amt;
        idx += idx & -idx;
    }
}
int sum(int idx){
    int ret = 0;
    while(idx > 0){
        ret += FT[idx];
        idx -= idx & -idx;
    }
    return ret;
}
int main(){
    add(5,1);
    add(7,2);
    add(3,-1);
    printf("%d\n",sum(9));
    printf("%d\n",sum(1));
    printf("%d\n",sum(4));
    return 0;
}
