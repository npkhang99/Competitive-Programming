#include <bits/stdc++.h>
using namespace std;

const int N = 3009;

int n;
long long k, memo[N][10000]={};
string st="";

long long gen(int i, int c){
    if(c < 0) return 0;
    if(i == n) return c == 0;
    if(memo[i][c] != -1) return memo[i][c];
    long long sl = gen(i+1,c+1) + gen(i+1,c-1);
    return memo[i][c] = min(sl, k+1);
}

void trace(int i, int c){
    if(i == n){
        cout<< st<< '\n';
        exit(0);
    }
    // cerr<< i<< " "<< c<< " "<< memo[i][c]<< endl;
    if(k <= gen(i+1,c+1)){
        st += '(';
        trace(i+1,c+1);
        return;
    }
    st += ')';
    k -= gen(i+1,c+1);
    trace(i+1,c-1);
}

void subtask1(){
    memset(memo, -1, sizeof memo);
    gen(0,0);
    trace(0,0);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("Bracket.inp","r",stdin);
    // freopen("Bracket.out","w",stdout);
    cin>> n>> k;
    subtask1();
    return 0;
}
