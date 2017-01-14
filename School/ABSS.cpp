#include <bits/stdc++.h>
using namespace std;

const int N = 1000009;

int n, vt[2*N]={}, a[N]={}, b[N]={};
char st[N]={};

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("ABSS.inp","r",stdin);
    // freopen("ABSS.out","w",stdout);
    while(cin>> st){
        n = strlen(st);
        memset(vt,-1,sizeof(vt));
        int ans = 1; vt[n] = 0;
        for(int i=1, h=n; i<=n; i++){
            if(st[i-1] == 'A') h+=1;
            else h-=1;
            for(int j=h-1; j<=h+1; j++)
                if(vt[j] != -1) ans = max(ans, i - vt[j]);
            if(vt[h] == -1) vt[h] = i;
        }
        cout<< ans<< '\n';
    }
    return 0;
}
