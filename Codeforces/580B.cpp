#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

const int N=100009;
ii a[N];
int n, d;
//---------------------------------------------------------
void doc(){
    cin>> n>> d;
    for(int i=1; i<=n; i++)
        cin>> a[i].first>> a[i].second;
}
//---------------------------------------------------------
void xuly(){
    long long maxFact, b[N];
    sort(a+1,a+n+1);
    b[0]=0;
    for(int i=1; i<=n; i++)
        b[i]=b[i-1]+a[i].second;
    int l=1; maxFact=INT_MIN;
    for(int r=1; r<=n; r++){
        while(a[r].first-a[l].first>=d) l++;
        maxFact=max(maxFact, b[r]-b[l-1]);
    }
    cout<< maxFact;
}
//---------------------------------------------------------
int main(){
    doc();
    xuly();
    return 0;
}
