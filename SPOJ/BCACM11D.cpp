#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

const int N=10009;

int T, d[N]={}, s, t;
vector<int> a[N], prime;

bool isPrime(int x){
    for(int i=2; i<=sqrt(x); i++)
        if(x%i == 0) return false;
    return true;
}

bool isAdjencent(int a, int b){
    string s1 = to_string(a), s2 = to_string(b);
    int cnt = 0;
    for(int i=0; i<4; i++){
        if(s1[i]!=s2[i]) cnt+=1;
        if(cnt>1) return false;
    }
    return true;
}

void preprocess(){
    for(int i=1000; i<10000; i++)
        if(isPrime(i)) prime.push_back(i);

    for(int i=0; i<prime.size()-1; i++)
        for(int j=i+1; j<prime.size(); j++)
            if(isAdjencent(prime[i],prime[j]))
                a[prime[i]].push_back(prime[j]), a[prime[j]].push_back(prime[i]);
}

void BFS(){
    for(int i=0; i<10000; i++) d[i] = 10E8;
    queue<int> q;
    q.push(s); d[s] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u == t) break;
        for(int i=0; i<a[u].size(); i++){
            int v = a[u][i];
            if(d[v] > d[u]+1) q.push(v), d[v] = d[u]+1;
        }
    }
    printf("%d\n",d[t]);
}

int main(){
    preprocess();
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&s,&t);
        BFS();
    }
    return 0;
}
