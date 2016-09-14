#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

const int N=100009;

typedef pair<int,int> ii;

ii a[N], cbook;
int n;
priority_queue<ii,vector<ii>,greater<ii> > q;

void doc(){
    cin>> n;
    for(int i=0; i<n; i++) cin>> a[i].second>> a[i].first;
    a[n]=ii(0,-1);
}

int comp(ii a, ii b){
    return a.second<b.second || (a.second==b.second && a.first<b.first);
}

void push_ctime(int &i){
    if(i==0) q.pop();
    int ctime=a[i].second;
    while(a[i].second==ctime) q.push(a[i++]);
}

void xuly(){
    sort(a,a+n,comp);
    int time=a[0].second, i=0;
    long long ans=0;
    q.push(ii(0,0));
    while(!q.empty()){
        push_ctime(i);
        while(time!=a[i].second){
            if(cbook.first>q.top().first){
                q.push(cbook); cbook=q.top(); q.pop();
            }else if(cbook.first==0){
                cbook=q.top(); q.pop();
            }
            int remain=a[i].second-time;
            if(cbook.first<=remain){
                time+=cbook.first; ans+=time;
                cbook=q.top(); q.pop();
            }else{ time+=remain; cbook.first-=remain; }
        }
    }
    cout<< ans;
}

int main(){
    freopen("Pulp.inp","r",stdin);
    // freopen("Pulp.out","w",stdout);
    doc();
    xuly();
    return 0;
}
