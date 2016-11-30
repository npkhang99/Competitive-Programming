#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
vector<ll> a;
map<ll, vector<bitset<20> > > p;
set<ll> b;

ll calc(bitset<20> bit){
    ll x = 0;
    for(int i=0; i<20; i++)
        x += a[i] * (ll)bit.test(i);
}

void b_gen(int i, bitset<20> bit){
    if(i == 20){
        ll k = calc(bit);
        b.insert(k);
        p[k].push_back(bit);
        return;
    }

    for(int j=0; j<2; j++){
        bit.set(i,j);
        b_gen(i+1,bit);
    }
}

void prep(){
    ll x = 1;
    a.push_back(1);
    for(int i=1; i<=19; i++){
        x *= 3ll;
        a.push_back(x);
    }
    b_gen(0,0);
}

int main(){
    // scanf("%lld",&n);
    prep();
    cerr<< b.size()<< endl;
    return 0;
}
