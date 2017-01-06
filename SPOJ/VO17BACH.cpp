#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int type, n, k, a[N]={};

int sumDigit(int x){
    int s = 0;
    while(x){
        s += x % 10;
        x /= 10;
    }
    return s;
}

int dictionary(string a, string b){
    for(int i=0; i<min(a.size(), b.size()); i++)
        if(a[i] < b[i]) return true;
        else if(a[i] > b[i]) return false;
    if(a.size() < b.size()) return true;
    else return false;
}

int comp(int a, int b){
    return sumDigit(a) < sumDigit(b) || (sumDigit(a) == sumDigit(b) && dictionary(to_string(a),to_string(b)));
}

int main(){
    int Q; scanf("%d",&Q);
    while(Q--){
        scanf("%d%d%d", &type, &n, &k);
        for(int i=1; i<=n; i++)
            a[i-1] = i;
        sort(a, a+n, comp);
        if(type) printf("%d\n", a[k-1]);
        else printf("%d\n", int(lower_bound(a, a+n, k, comp) - a) + 1);
    }
}
