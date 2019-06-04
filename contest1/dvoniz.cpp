#include <bits/stdc++.h>
using namespace std;
int a[100005];
int qs[100005];
int q[100005];
int main(){
	int n,s;
	scanf("%d%d",&n,&s);
	for(int i = 1; i <= n; i++){
		scanf("%d",a+i);
		qs[i] = qs[i-1] + a[i];
	}
	for(int i = 1; i < n; i++){
		// Considering between i and i+1
		if(a[i] > s || a[i+1] > s) continue;
		int lo = 1;
		int hi = min(i,n-i);
		int mid;
		while(lo < hi){
		  mid = (lo + hi + 1)/2;
		  if(qs[i+mid] - qs[i] <= s && qs[i] - qs[i-mid] <= s){
		    lo = mid;
		  }else{
		    hi = mid-1;
		  }
		}
		q[i-lo+1] = max(q[i-lo+1],2*lo);
	}
	int csz = 0;
  for(int i = 1; i <= n; i++){
    csz = max(csz,q[i]);
    printf("%d\n",csz);
    csz -= 2;
  }
	return 0;
}

