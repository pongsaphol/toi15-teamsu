#include <cstdio>
#include <cstring>
char a[100005];
char b[100005];
int main(){
    int t;
    scanf("%d",&t);
    int h;
    int c;
    int m,n;
    int k;
    int d;
    int e = 53;
    for(int i = 0; i < t; i++){
        scanf("%s%s",a,b);
        m = strlen(a);
        n = strlen(b);
        h = 0;
        k = 1;
        for(int j = 0; j < m; j++){
            h *= e;
            h += a[j];
            k *= e;
        }
        c = 0;
        for(int j = 0; j < m; j++){
            c *= e;
            c += b[j];
        }
        d = 0;
        if(c == h)d++;
        for(int j = m; j < n; j++){
            c *= e;
            c -= b[j-m]*k;
            c += b[j];
            if(c == h){
                d++;
            }
        }
        printf("%d\n",d);
    }
    return 0;
}

