#include <bits/stdc++.h>
using namespace std;

const int N=109;

int n, m, ans[N][N]={}, t=0;
string a[N];

bool inrange(int check, int lo, int hi){
    return lo <= check && check < hi;
}

bool can(int i, int j){
    return inrange(i,0,n) && inrange(j,0,m) && a[i][j]!='*';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin>> n>> m, n && m){
        if(t) cout<< '\n';
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) ans[i][j] = 0;

        for(int i=0; i<n; i++) cin>> a[i];

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(a[i][j] == '*'){
                    ans[i][j] = -1;
                    if(can(i-1,j-1)) ans[i-1][j-1] +=1;
                    if(can(i-1,j)) ans[i-1][j] +=1;
                    if(can(i-1,j+1)) ans[i-1][j+1] +=1;
                    if(can(i,j-1)) ans[i][j-1] +=1;
                    if(can(i,j+1)) ans[i][j+1] +=1;
                    if(can(i+1,j-1)) ans[i+1][j-1] +=1;
                    if(can(i+1,j)) ans[i+1][j] +=1;
                    if(can(i+1,j+1)) ans[i+1][j+1] +=1;
                }

        cout<< "Field #"<< ++t<< ":\n";
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(ans[i][j]!=-1) cout<< ans[i][j];
                else cout<< '*';
            }
            cout<< '\n';
        }
    }
    return 0;
}
