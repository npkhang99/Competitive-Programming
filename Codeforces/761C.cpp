#include <bits/stdc++.h>
using namespace std;

const int N = 59;

int n, m, b[9][N]={};
string a[N];

int calc(int x){
    int steps = 0, p = 0;
    while(p != x) p = (p - 1 + m) % m, steps++;
    return min(steps, x);
}

int main(){
    while(cin>> n>> m){
        for(int i=1; i<=3; i++)
            for(int j=0; j<n; j++)
                b[i][j] = 1e5;

        for(int i=0; i<n; i++)
            cin>> a[i];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if('a' <= a[i][j] && a[i][j] <= 'z') b[2][i] = min(b[2][i], calc(j));
                if('0' <= a[i][j] && a[i][j] <= '9') b[1][i] = min(b[1][i], calc(j));
                if(a[i][j] == '*' || a[i][j] == '#' || a[i][j] == '&') b[3][i] = min(b[3][i], calc(j));
            }
        }

        for(int i=0; i<n; i++){
            for(int j=1; j<=3; j++)
                cerr<< b[j][i]<< " ";
            cerr<< endl;
        }

        int ans = 1e9;
        for(int i=0; i<n; i++)
            if(~b[1][i])
                for(int j=0; j<n; j++)
                    if(~b[2][j] && j != i)
                        for(int k=0; k<n; k++)
                            if(~b[3][k] && k != i && k != j)
                                ans = min(ans, b[1][i] + b[2][j] + b[3][k]);
        cout<< ans<< endl;
    }
    return 0;
}
