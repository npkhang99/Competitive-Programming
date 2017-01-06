#include <bits/stdc++.h>
using namespace std;

const int N = 50009;

int n, a[N]={}, ans = 0;
bitset<N> b;

int calc(){
    vector<int> s1, s2;
    for(int i=0; i<n; i++)
        if(b[i]) s1.push_back(a[i]);
        else s2.push_back(a[i]);
    if(s1.empty() || s2.empty()) return 0;
    int gcd1 = s1[0], gcd2 = s2[0];
    for(int i=1; i<s1.size(); i++)
        gcd1 = __gcd(gcd1, s1[i]);
    for(int i=1; i<s2.size(); i++)
        gcd2 = __gcd(gcd2, s2[i]);
    return min(gcd1, gcd2);
}

void btrack(int i){
    if(i == n){
        ans = max(ans, calc());
        return;
    }

    for(int j=0; j<2; j++){
        b[i] = j;
        btrack(i+1);
    }
}

int main(){
    int TC; scanf("%d",&TC);
    while(TC--){
        scanf("%d",&n); ans = 0;
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        btrack(0);
        printf("%d\n",ans);
    }
    return 0;
}
