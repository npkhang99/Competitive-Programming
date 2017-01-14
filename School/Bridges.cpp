#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 1000009;

int n, a[N]={}, ans = 0;

void btrack(int i, int f){
    if(!a[i] && !a[i-1]){
        ans = max(ans, f);
        return;
    }
    if(a[i]){
        a[i]--;
        btrack(i+1, f+1);
        a[i]++;
    }
    if(a[i-1]){
        a[i-1]--;
        btrack(i-1, f+1);
        a[i-1]++;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("Bridges.inp","r",stdin);
    // freopen("Brigdes.out","w",stdout);
    cin>> n;
    for(int i=1; i<n; i++)
        cin>> a[i];

    for(int i=1; i<=n; i++)
        btrack(i,0);
    cout<< ans<< '\n';
    return 0;
}
