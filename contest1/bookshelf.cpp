#include <bits/stdc++.h>
using namespace std;
int h[100005];
int w[100005];
long long dp[100005];
long long qs[100005];
map<int,int> inuse;
map<int,int> bck;
pair<int,int> exph(int x){
    auto it = bck.upper_bound(x);
    it--;
    return *it;
}
int main(){
    int n,l;
    scanf("%d%d",&n,&l);
    for(int i = 1; i <= n; i++){
        scanf("%d%d",h+i,w+i);
        qs[i] = qs[i-1] + w[i];
    }
    set<pair<long long,int> > pick;
    inuse.emplace(0,0);
    bck.emplace(0,0);
    pick.emplace(0ll,0);
    for(int i = 1; i <= n; i++){
        int mindex = 1e9;
        vector<pair<int,int> > er;
        for(pair<int,int> x : inuse){
            if(x.first > h[i]) break;
            int idx = x.second;
            pick.erase(make_pair((long long)x.first + dp[idx], idx));
            mindex = min(mindex, idx);
            er.push_back(x);
        }
        if(mindex != 1e9){
            for (auto x : er){
                inuse.erase(x.first);
                bck.erase(x.second);
            }
            inuse[h[i]] = mindex;
            bck[mindex] = h[i];
            pick.insert(make_pair((long long) h[i] + dp[mindex], mindex));
        }
        int lo = 0;
        int hi = i-1;
        int mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (qs[i] - qs[mid] <= l) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        auto ans = exph(lo);
        while(!pick.empty() && pick.begin()->second < lo){
            int e = exph(pick.begin()->second).second;
            bck.erase(inuse[e]);
            inuse.erase(e);
            pick.erase(pick.begin());
        }
        if(inuse.find(ans.second) == inuse.end()){
            pick.insert(make_pair(ans.second + dp[lo],lo));
            inuse[ans.second] = lo;
            bck.erase(ans.first);
            bck[lo] = ans.second;
        }
        dp[i] = pick.begin()->first;
        if(mindex == 1e9) {
            pick.insert(make_pair((long long) h[i] + dp[i-1], i-1));
            inuse.insert(make_pair(h[i], i-1));
            bck[i-1] = h[i];
        }
        pick.insert(make_pair(dp[i], i));
        inuse.insert(make_pair(0, i));
        bck[i] = 0;
    }
    printf("%lld\n",dp[n]);
    return 0;
}

