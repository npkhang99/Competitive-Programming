// SPOJ submission 17221616 (C++ 5) plaintext list. Status: AC, problem POSTERS, contest SPOJ. By mansblacks (Khang), 2016-07-04 04:25:51.
#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int N=40009;

int n, m=0, _m=10E8, b[N]={};
map<int,vector<int> > a;

void doc(){
    cin>> n;
    for(int i=0; i<n; i++){
        int x,y; cin>> x>> y;
        a[x].push_back(i+1);
        a[y+1].push_back(-i-1);
        m=max(m,y); _m=min(_m,x);
        b[i+1]=0;
    }
}

void xuly(){
    set<int> bst;
    int ans=0, curr=-1;
    for(int i=_m; i<=m; i++){
        if(a.find(i)==a.end()) continue;
        for(int j=0; j<a[i].size(); j++){
            int u=a[i][j];
            if(u>0) bst.insert(u);
            else bst.erase(-u);
        }
        if(bst.empty()) continue;
        set<int>::iterator it=bst.end();
        curr=*(--it);
        if(!b[curr]){ ans+=1; b[curr]=1; }
    }
    printf("%d\n",ans);
}

int main(){
    int t;
    cin>> t;
    for(int _=0; _<t; _++){
        doc();
        xuly();
        a.clear();
    }
    return 0;
}