#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

#define x first
#define y second

const int N = 29;

int T, n, m;
char a[N][N]={};

bool horizontal(int x, int y){
    if(m - y < 3) return false;
    string st;
    for(int i=0; i<3; i++)
        st += a[x][y+i];
    return st == "pie" || st == "eip";
}

bool verticle(int x, int y){
    if(n - x < 3) return false;
    string st;
    for(int i=0; i<3; i++)
        st += a[i+i][y];
    return st == "pie" || st == "eip";
}

bool m_diagonal(int x, int y){
    if(m - y < 3 || n - x < 3) return false;
    string st;
    for(int i=0; i<3; i++)
        st += a[x+i][y+i];
    return st == "pie" || st == "eip";
}

bool s_diagonal(int x, int y){
    if(x < 2 || y < 2) return false;
    string st;
    for(int i=0; i<3; i++)
        st += a[x-i][y-i];
    return st == "pie" || st == "eip";
}

int main(){
    cin>> T;
    while(T--){
        cin>> n>> m;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>> a[i][j];

        bool flag = false;
        vecotr<ii> l_p, l_i, l_e;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                if(a[i][j] == 'p') l_p.push_back(ii(i,j));
                if(a[i][j] == 'i') l_i.push_back(ii(i,j));
                if(a[i][j] == 'e') l_e.push_back(ii(i,j));
            }
        for(int i=0; i<l_p.size(); i++)
            for(int j=0; j<l_i.size(); i++)
                for()
        if(flag) continue;
        cout<< "Sorry Man\n";
    }
    return 0;
}
