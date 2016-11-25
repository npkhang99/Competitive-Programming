#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> p;

#define sum first
#define state second

int n, a[200009]={}, memo[89][100009]={};
long long L, R;
bitset<89> b;
vector<p> v;

bool valid(long long x){ return L <= x && x <= R; }

long long to_llong(bitset<89> b){
    long long ans = 0;
    for(int i=0; i<64; i++)
        if(b.test(i)) ans += (1LL << i);
    return ans;
}

void print(bitset<89> b){
    // cerr<< b<< endl;
    printf("%d\n",(int)b.count());
    for(int i=0; i<n; i++)
        if(b.test(i)) printf("%d ",i+1);
    printf("\n");
    exit(0);
}

// subtask 1
void subtask1(int i, bitset<89> b, long long t, long long left){
    if(i == n && valid(t)) print(b);
    else if(t > R || t + left < L) return;
    for(int j=0; j<2; j++){
        b.set(i,j);
        subtask1(i+1, b, t + a[i]*j, left - a[i]);
    }
}

// subtask 2
void gen(int i, bitset<89> b, long long t, int lim){
    if(t > R) return;
    if(i == lim){
        // cerr<< t<< " "<<to_llong(b)<< endl; 
        v.push_back(p(t,to_llong(b)));
        return;
    }
    v.push_back(p(t,to_llong(b)));
    // cerr<< b<< " "<< to_llong(b)<< endl;
    for(int j=0; j<2; j++){
        b.set(i,j);
        gen(i+1, b, t + a[i]*j, lim);
    }
    // if(t <= 100000) memo[i][t] = 1;
}

void firstHalf(int mid){
    gen(0,b,0,mid);
    sort(v.begin(),v.end());
}

void find(int i, bitset<89> b, long long t, int lim){
    if(t > R) return;
    if(i == lim){
        long long need = L - t;
        if(need > v.back().first) return;
        // cerr<< need<< endl;
        long long j = lower_bound(v.begin(), v.end(), p(need,0)) - v.begin();
        // printf("%lld %lld %lld\n",t,need,j);
        if(L <= t + v[j].first && t + v[j].first <= R){
            // cerr<< j<< endl;
            print(bitset<89>(v[j].second) | b);
        }
        return;
    }
    for(int j=0; j<2; j++){
        b.set(i,j);
        find(i+1, b, t + a[i]*j, lim);
    }
}

void subtask2(){
    int mid = n/2;
    firstHalf(mid);
    // for(int i=0; i<v.size(); i++)
    //     cerr<< v[i].first<< " ";
    // cerr<< endl;
    find(mid,b,0,n);
}

// subtask 3
void subtask3(int i, bitset<89> b, long long t){
    if(i == n){
        if(L <= t && t <= R) print(b);
        return;
    }
    if(memo[i][t]) return;
    for(int j=0; j<2; j++){
        b.set(i,j);
        subtask3(i+1, b, t + a[i]*j);
    }
    if(t <= 100000) memo[i][t] = 1;
}

int main(){
    // freopen("Subset.inp","r",stdin);
    // freopen("Subset.out","w",stdout);
    scanf("%d%lld%lld",&n,&L,&R);
    long long sum = 0;
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
        sum += a[i];
    }
    b.reset();
    if(n <= 20) subtask1(0,b,0,sum);
    else if(n <= 40) subtask2();
    else subtask3(0,0,0);
    return 0;
}
