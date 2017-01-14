#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int T, factNum;
long long a, b;
vector<int> fact;

int findFacts(){
    for(int i=2; i<1000000; i++){
        int isFact = 1;
        for(int j=2; j<=(int)sqrt(i); i++)
            if(i%j==0){
                isFact = 0;
                break;
            }
        if(isFact) fact.push_back(i);
    }
}

int isSquare(long long n){
    long long x = sqrt(n);
    return x*x==n;
}

int check(long long n, int x){
    return (n/x) * x == n;
}

void xuly(long long a, long long b){
    int ans = 0;
    for(long long i=a; i<=b; i++){
        if(i==36){
            ans+=1;
            continue;
        }
        if(i%3==0 && isSquare(i)){
            int cnt = 5;
            cnt += check(i,9)*2;
            for(int j=4; j<(int)sqrt(i); j++){
                if(i%j == 0) cnt+=2;
                if(cnt>9) break;
            }
            if(cnt==9) ans+=1;
        }
    }
    printf("%d\n",ans);
}

int main(){
    // freopen("DMT.inp","r",stdin);
    // freopen("DMT.out","w",stdout);
    scanf("%d",&T);
    factNum = findFacts();
    for(int t=0; t<T; t++){
        scanf("%lld%lld",&a,&b);
        xuly(a,b);
    }
    return 0;
}
