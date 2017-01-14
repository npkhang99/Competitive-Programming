#include <bits/stdc++.h>
using namespace std;

const int N = 1000009;

long long n, x;
int a[N]={}, b[N]={};
vector<int> v;

int f(int i){
    return n-a[i]-1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("Water.inp","r",stdin);
    // freopen("Water.out","w",stdout);
    cin>> n>> x;
    if(2*x > (n-1)*(n-2)){
        cout<< "-1\n";
        return 0;
    }

    a[0] = n-1; a[n-1] = n;
    for(int i=1; i<n-1; i++)
        a[i] = a[i-1] - 1;

    long long curr = (n-1)*(n-2)/2;
    int c = n-2;
    while(curr > x){
        if(curr - f(c) >= x){
            curr -= f(c);
            v.push_back(a[c]);
            b[c] = 1;
        }
        c-=1;
    }
    for(int i=0; i<n; i++)
        if(!b[i]) cout<< a[i]<< " ";
    for(int i=0; i<v.size(); i++)
        cout<< v[i]<< " ";
    cout<< '\n';
    return 0;
}
