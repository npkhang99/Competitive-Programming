// SPOJ submission 15784256 (C++ 5) plaintext list. Status: AC, problem FSELECT, contest SPOJVN. By mansblacks (Khang), 2015-12-05 10:59:10.
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#define forit(i,c) for(__typeof(c).begin() i=(c).begin(); i!=(c).end(); i++)
#define log2(i) trunc(log(i)/log(2))+1
using namespace std;

const int N=200000;
const int N_=log2(N);
vector< vector<int> > g(N);
struct ban{
    int cha, hen, d, dinh;
}a[N+9];
int n, k, head[N+9], goc, L[N+9][N_+1], high[N+9];
bool b[N+9];
//---------------------------------------------------------
void doc(){
    cin>> n>> k;
    for(int i=1; i<=n; i++){
        cin>> a[i].hen>> a[i].cha;
        g[a[i].cha].push_back(i); g[i].push_back(a[i].cha);
        head[a[i].hen]++;
        if (a[i].cha==0) goc=i;
        a[i].dinh=i;
    }
}
//---------------------------------------------------------
int comp1(ban a, ban b){
    return a.hen<b.hen || (a.hen==b.hen && a.d>b.d);
}
//---------------------------------------------------------
void DFS(int i){
    b[i]=true;
    forit(it,g[i])
        if(!b[*it]){
            high[*it]=a[*it].d=a[i].d+1;
            DFS(*it);
        }
}
//---------------------------------------------------------
int getbit(int x, int i){
    return (x >> i) & 1;
}
//---------------------------------------------------------
int LCA(int u, int v){
    int LCA_, t;
    if (high[u]>=high[v]){
        if(high[u]>high[v]){
            t=high[u]-high[v];
            for(int i=log2(t); i>=0; i--)
                if(getbit(t,i)==1) u=L[u][i];
        }
        for(int i=log2(n); i>=0; i--)
            if(L[u][i]!=L[v][i]){
                u=L[u][i]; v=L[v][i];
            }else LCA_=L[u][i];
        if (u==v) LCA_=u;
        return LCA_;
    }else return LCA(v,u);
}
//---------------------------------------------------------
void xuly(){
    a[goc].d=1; high[goc]=1;
    DFS(goc);
    //L[i][j] tổ tiên thứ 2^j của đỉnh i
    for(int i=0; i<=n; i++) L[i][0]=a[i].cha;
    for(int j=1; j<=log2(n); j++)
        for(int i=1; i<=n; i++)
            L[i][j]=L[ L[i][j-1] ] [j-1];
    sort(a+1,a+n+1,comp1);
}
//---------------------------------------------------------
int kc(int u, int v){
    int _kc=high[u]+high[v]-2*high[LCA(u,v)];
    return _kc;
}
//---------------------------------------------------------
void xuat(){
    for(int i=2; i<=k; i++) head[i]=head[i-1]+head[i]; head[0]=0;
    for(int i=1; i<=k; i++){
        int r=0;
        int u=a[head[i-1]+1].dinh;
        for(int v=head[i-1]+2; v<=head[i]; v++){
            r=max(r, kc(u, a[v].dinh));
            //if(a[head[i]].d==a[v].d) break;
        }
        cout<< r<< endl;
    }
}
//---------------------------------------------------------
int main(){
    doc();
    xuly();
    xuat();
    return 0;
}