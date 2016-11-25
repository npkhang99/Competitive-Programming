#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 1009;

int n, s, t, d, b[N]={}, ans = 10E7;
ii a[N]={};

int f(int startTime, int p){
    return abs((startTime + a[p].first) - d) * a[p].second;
}

void sub2(int i, int time, int cost){
    if(i == n){
        ans = min(ans, cost);
        return;
    }
    for(int j=0; j<n; j++)
        if(!b[j]){
            b[j] = 1;
            sub2(i+1, time + a[j].first, cost + f(time,j));
            b[j] = 0;
        }
}

void subtask2(){
    int totalNeed = 0;
    for(int i=0; i<n; i++)
        totalNeed += a[i].first;

    for(int i=s; i<=t - totalNeed; i++)
        for(int j=0; j<n; j++){
            b[j] = 1;
            sub2(1, i+a[j].first, f(i,j));
            b[j] = 0;
        }
    printf("%d\n",ans);
}

int comp(ii a, ii b){
    return ((double)(a.second) / (double)(a.first)) > ((double)(b.second) / (double)(b.first));
}

int _comp(ii a, ii b){
    return ((double)(a.second) / (double)(a.first)) < ((double)(b.second) / (double)(b.first));
}

void subtask3(){
    ans = 0;
    sort(a,a+n,comp);
    for(int i=0, time = d; i<n; time+=a[i++].first){
        ans += f(time,i);
    }
    printf("%d\n",ans);
}

void subtask4(){
    ans = 0;
    sort(a,a+n,_comp);
    for(int i=0, time = d; i<n; time+=a[i++].first){
        ans += f(time,i);
    }
    printf("%d\n",ans);
}

int main(){
    // freopen("DBG.inp","r",stdin);
    // freopen("DBG.out","w",stdout);
    scanf("%d%d%d%d",&n,&s,&t,&d);
    for(int i=0; i<n; i++)
        scanf("%d%d",&a[i].first,&a[i].second);
    if(n <= 8) subtask2();
    else if(a == d) subtask3();
    else if(d == b) subtask4();
    return 0;
}
