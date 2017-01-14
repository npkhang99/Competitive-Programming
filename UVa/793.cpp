#include <bits/stdc++.h>
using namespace std;

const int N=1000009;

int n, T, par[N]={}, x, y;
char c;
string st;

int root(int p){
    return p == par[p]? p:root(par[p]);
}

void join(int p, int q){
    par[root(p)] = root(q);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>> T;
    for(int t=0; t<T; t++){
        if(t) cout<< '\n';
        cin>> n; cin.ignore();
        int a[2] = {0,0};
        for(int i=1; i<=n; i++) par[i] = i;
        while(getline(cin,st), !st.empty()){
            istringstream ss(st);
            ss>> c>> x>> y;
            if(c == 'q') a[root(x) == root(y)? 1:0]+=1;
            else join(x,y);
        }
        cout<< a[1]<< ','<< a[0]<< '\n';
    }
    return 0;
}
