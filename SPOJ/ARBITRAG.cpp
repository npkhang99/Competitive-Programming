#include <bits/stdc++.h>
using namespace std;

const int N = 39;

int n, m, TC = 0;
double d[N][N]={};
map<string,int> a;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin>> n, n){
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(i != j) d[i][j] = 0.0;
                else d[i][j] = 1.0;

        for(int i=0; i < n; i++){
            string st; cin>> st;
            a[st] = i;
        }
        cin>> m;
        while(m--){
            string u, v; double c;
            cin>> u>> c>> v;
            d[a[u]][a[v]] = c;
        }

        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    d[i][j] = max(d[i][j], d[i][k] * d[k][j]);

        bool arbitrage = false;
        for(int i=0; i<n; i++)
            if(d[i][i] - 1.0 > 1e-9) arbitrage = true;

        cout<< "Case "<< ++TC<< ": "<< (arbitrage? "Yes":"No")<< '\n';
    }
    return 0;
}
