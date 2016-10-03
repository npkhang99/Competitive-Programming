#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;

const int N=3*10E4+9;

int n, lmin[N], lmax[N], rmin[N], rmax[N];
long long a[N], ans=0;

int findMin(){
    stack<int> s;
    s.push(0);
    for(int i=1; i<n; i++){
        while(!s.empty() && a[i]<=a[s.top()]){
            rmin[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        rmin[s.top()] = n-s.top();
        s.pop();
    }

    while(!s.empty()) s.pop();
    s.push(n-1);
    for(int i=n-2; i>=0; i--){
        while(!s.empty() && a[i]<a[s.top()]){
            lmin[s.top()] = s.top()-i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        lmin[s.top()] = s.top()+1;
        s.pop();
    }
    // lmin[0] = 1;
}

void findMax(){
    stack<int> s;
    s.push(0);
    for(int i=1; i<n; i++){
        while(!s.empty() && a[i]>=a[s.top()]){
            rmax[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        rmax[s.top()] = n-s.top();
        s.pop();
    }

    while(!s.empty()) s.pop();
    s.push(n-1);
    for(int i=n-2; i>=0; i--){
        while(!s.empty() && a[i]>a[s.top()]){
            lmax[s.top()] = s.top()-i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        lmax[s.top()] = s.top()+1;
        s.pop();
    }
}

int main(){
    // freopen("Diferen.inp","r",stdin);
    // freopen("Diferen.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%lld",&a[i]);
    findMin();
    findMax();
    // for(int i=0; i<n; i++)
    //     printf("%lld - %d %d - %d %d\n",a[i],lmin[i],rmin[i],lmax[i],rmax[i]);
    for(int i=0; i<n; i++)
        ans += a[i]*lmax[i]*rmax[i]; - a[i]*lmin[i]*rmin[i];
    printf("%lld\n",ans);
    return 0;
}
